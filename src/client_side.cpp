//
// Created by kaladin on 17.09.2021.
//
#include <thread>
#include <chrono>
#include <vector>
#include <iostream>
#include "../include/client.h"
using namespace boost::asio;
int main(){
    int n1;
    std::cin >> n1;
    std::string messages[n1];
    for (int i = 0;i<n1;i++){
        std::cin >> messages[i];
    }
    std::vector<std::thread> th;
    for (int i = 0;i<n1;i++)
    {
        th.emplace_back([&](){
            auto cl = std::make_shared<client>(messages[i].c_str());
            cl->do_work();
            cl->get_message();});
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    for (auto& d:th){
        d.join();
    }
    return 0;
}
