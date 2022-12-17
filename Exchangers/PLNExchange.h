//
// Created by Acer on 08.11.2022.
//

#ifndef OOP1___KANTOR_WALUT_PLNEXCHANGE_H
#define OOP1___KANTOR_WALUT_PLNEXCHANGE_H


#include "Currency.h"
#include "../Money/EUR.h"
#include "../Money/USD.h"
#include <iostream>
#include <sstream>

class PLNExchange: public Currency {
public:
    PLNExchange(const double fromEurToPln, const double fromUsDtoPln) : fromEurToPLN(fromEurToPln),
                                                                        fromUSDtoPLN(fromUsDtoPln) {};

    std::string info() override {
        std::ostringstream oss;
        oss << "You can exchange USD to PLN for: " << fromUSDtoPLN << ", Euro to PLN for: "<< fromEurToPLN;
        return oss.str();
    }

    [[nodiscard]] double exchangerFromEURToPLN(EUR euro) const {
        return euro.value() * fromEurToPLN;
    }

    [[nodiscard]] double exchangerFromUSDToPLN(USD usd) const {
        return usd.value() * fromUSDtoPLN;
    }
private:
    const double fromEurToPLN = 4.68;
    const double fromUSDtoPLN = 4.69;
};


#endif //OOP1___KANTOR_WALUT_PLNEXCHANGE_H
