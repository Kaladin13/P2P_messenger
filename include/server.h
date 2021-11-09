//
// Created by kaladin on 17.09.2021.
//

#ifndef MSGER_SERVER_H
#define MSGER_SERVER_H

#include "boost/asio.hpp"
#include "iostream"
#include <cstring>
using namespace boost::asio;
class server{
    enum{
        DEFAULT_PORT = 8239,
        MAX_BUFF_SIZE = 512
    };
private:
    io_service service;
    char buff[MAX_BUFF_SIZE];
public:
    server(){}
    void handle_connection() {
        while (true) {
            ip::tcp::socket socket(service);
            ip::tcp::acceptor acceptor(service,ip::tcp::endpoint(ip::tcp::v4(),DEFAULT_PORT));
            acceptor.listen(30);
            acceptor.accept(socket);
            read(socket, buffer(buff), [this](auto &&PH1, auto &&PH2) {
                return read_complete(buff, std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2));
            });
            std::cout << socket.local_endpoint() << "\n";
            std::cout << socket.remote_endpoint();
            std::cout << "\nI have read ";
            std::cout << buff << std::endl;
            if (std::strcmp(buff,"close")==0) {
                socket.close();
                return;
            }
            socket.write_some(buffer(buff));
            socket.close();
        }
    }
    static size_t read_complete(char * buff1, const boost::system::error_code & err, size_t bytes)
    {
        if ( err) return 0;
        bool found = std::find(buff1, buff1 + bytes, '_') < buff1 + bytes;
        // we read one-by-one until we get to enter, no buffering
        return found ? 0 : 1;
    }

};


#endif //MSGER_SERVER_H
