cmake_minimum_required(VERSION 3.23)
project(OOP1___Kantor_walut)

set(CMAKE_CXX_STANDARD 23)

add_executable(OOP1___Kantor_walut main.cpp Exchange.h Exchangers/EuroExchange.h Exchangers/PLNExchange.h Exchangers/DollarsExchange.h Exchangers/Currency.h Money/PLN.h Value.h Money/USD.h Money/EUR.h)
