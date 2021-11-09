//
// Created by kaladin on 16.09.2021.
//

#ifndef MSGER_CLIENT_H
#define MSGER_CLIENT_H

#include "boost/asio.hpp"
using namespace boost::asio;
class client{
public:
    enum{
        DEFAULT_PORT = 8239,
        MAX_BUFF_SIZE = 512
    };
    const std::string DEFAULT_IP = "127.0.0.1";
    const std::string DEFAULT_SERVER_IP = "ip_adress";
private:
    io_service service;
    ip::tcp::resolver resolver;
    ip::tcp::resolver::query resolver_query;
    ip::tcp::socket socket;
    char buff[MAX_BUFF_SIZE];
    ip::tcp::endpoint ep;
public:
    client(const char* msg) : ep(ip::address::from_string(DEFAULT_IP),DEFAULT_PORT),
                         socket(service), resolver(service),
                         resolver_query(DEFAULT_IP, std::to_string(DEFAULT_PORT)){
        std::strcpy(buff,msg);
    }
    void do_work(){
        auto iter = resolver.resolve(resolver_query);
        ip::tcp::resolver::iterator it_end;
        for (;iter!=it_end;iter++){
            ep = iter->endpoint();
            socket.connect(ep);
        }
       // socket.connect(ep); //works without resolver queue too
        socket.write_some(buffer(buff));
    }
    void get_message(){
        read(socket, buffer(buff), [this](auto &&PH1, auto &&PH2) {
            return read_complete(buff, std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2));
        });
        std::cout << "I have received " << buff << "\n";
    }
    static size_t read_complete(char * buff1, const boost::system::error_code & err, size_t bytes)
    {
        if ( err) return 0;
        bool found = std::find(buff1, buff1 + bytes, '_') < buff1 + bytes;
        // we read one-by-one until we get to enter, no buffering
        return found ? 0 : 1;
    }
};

#endif //MSGER_CLIENT_H
