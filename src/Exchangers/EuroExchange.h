//
// Created by Acer on 08.11.2022.
//

#ifndef OOP1___KANTOR_WALUT_EUROEXCHANGE_H
#define OOP1___KANTOR_WALUT_EUROEXCHANGE_H


#include "Currency.h"
#include "../Money/USD.h"
#include "../Money/PLN.h"
#include <iostream>
#include <sstream>
// waluty też mogą być obiektami
// interejs w tych obiektach może mieć funkcję value() hehe getValue
// w klasie Currency dodatkowo dwie metody na zmianę kursu2863*74185632587324\0,254
class EuroExchange: public Currency {
public:
    std::string info() override {
        std::ostringstream oss;
        oss << "You can exchange from PLN to EUR: " << fromPLNtoEuro << ", and from USD to EUR: "<< fromUSDtoEuro;
        return oss.str();
    }

    EuroExchange(const double fromPlNtoEuro, const double fromUsDtoEuro) : fromPLNtoEuro(fromPlNtoEuro),
                                                                           fromUSDtoEuro(fromUsDtoEuro) {}
    [[nodiscard]] double exchangerFromPLNToEUR(PLN pln) const {
        return pln.value() * fromPLNtoEuro;
    }

    [[nodiscard]] double exchangerFromUSDtoEUR(USD usd) const {
        return usd.value() * fromUSDtoEuro;
    }
private:
    const double fromPLNtoEuro;
    const double fromUSDtoEuro;
};


#endif //OOP1___KANTOR_WALUT_EUROEXCHANGE_H
