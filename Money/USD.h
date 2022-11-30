//
// Created by Acer on 09.11.2022.
//

#ifndef OOP1___KANTOR_WALUT_USD_H
#define OOP1___KANTOR_WALUT_USD_H

#include "../Exchangers/Currency.h"
#include "../Value.h"

class USD: public Value {
public:
    explicit USD(double amount) : amount(amount) {}

    double value() override {
        return amount;
    }

private:
    double amount;
};
#endif //OOP1___KANTOR_WALUT_USD_H
