//
// Created by Acer on 08.11.2022.
//

#ifndef OOP1___KANTOR_WALUT_DOLLARSEXCHANGE_H
#define OOP1___KANTOR_WALUT_DOLLARSEXCHANGE_H


#include <sstream>
#include "Currency.h"
#include "../Money/USD.h"

class DollarsExchange: public Currency {
public:
    DollarsExchange(const double fromPlNtoUsd, const double fromEuRtoUsd) : fromPLNtoUSD(fromPlNtoUsd),
                                                                            fromEURtoUSD(fromEuRtoUsd) {}

    std::string info() override {
        std::ostringstream oss;
        oss << "You can exchange PLN to dollars for: " << fromPLNtoUSD << ", Euro to USD: "<< fromEURtoUSD;
        return oss.str();
    }

    [[nodiscard]] double exchangerFromPLNtoUSD(PLN pln) const {
        return pln.value() * fromPLNtoUSD;
    }

    [[nodiscard]] double exchangerFromEURtoUSD(EUR euro) const {
        return euro.value() * fromEURtoUSD;
    }

private:
    const double fromPLNtoUSD;
    const double fromEURtoUSD;
};


#endif //OOP1___KANTOR_WALUT_DOLLARSEXCHANGE_H
