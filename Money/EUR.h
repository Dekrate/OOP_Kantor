//
// Created by Acer on 09.11.2022.
//

#ifndef OOP1___KANTOR_WALUT_EUR_H
#define OOP1___KANTOR_WALUT_EUR_H

#include "../Value.h"

class EUR: public Value {
public:
    explicit EUR(double amount) : amount(amount) {}

    double value() override {
        return 0;
    }
private:
    double amount;
};
#endif //OOP1___KANTOR_WALUT_EUR_H
