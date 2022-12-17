//
// Created by Acer on 08.11.2022.
//

#ifndef OOP1___KANTOR_WALUT_PLN_H
#define OOP1___KANTOR_WALUT_PLN_H


#include "../../Value.h"

class PLN: public Value {
public:
    explicit PLN(double amount) : amount(amount) {}

    virtual ~PLN() = default;

    double value() override {
        return amount;
    }
private:
    double amount;
};


#endif //OOP1___KANTOR_WALUT_PLN_H
