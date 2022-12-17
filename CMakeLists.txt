cmake_minimum_required(VERSION 3.23)
project(OOP1___Kantor_walut)

set(CMAKE_CXX_STANDARD 23)

add_executable(OOP1___Kantor_walut main.cpp Exchange.h src/Exchangers/EuroExchange.h src/Exchangers/PLNExchange.h src/Exchangers/DollarsExchange.h src/Exchangers/Currency.h src/Money/PLN.h Value.h src/Money/USD.h src/Money/EUR.h)
