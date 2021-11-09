//
// Created by kaladin on 17.09.2021.
//
#include <iostream>
#include "../include/server.h"
using namespace boost::asio;
int main(){
    server server1;
    server1.handle_connection();
    return 0;
}