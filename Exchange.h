//
// Created by Acer on 08.11.2022.
//

#include <utility>
#include <vector>
#include <memory>
#include "Exchangers/EuroExchange.h"
#include "Exchangers/PLNExchange.h"
#include "Exchangers/DollarsExchange.h"
#include "Money/USD.h"
#include "Money/EUR.h"

#ifndef OOP1___KANTOR_WALUT_EXCHANGE_H
#define OOP1_KANTOR_WALUT_EXCHANGE_H
class Exchange {
private:
    EuroExchange euro;
    PLNExchange pln;
    DollarsExchange dollars;

public:
    Exchange(EuroExchange euro, PLNExchange pln, DollarsExchange dollars) : euro(std::move(euro)), pln(std::move(pln)),
                                                                                                 dollars(std::move(dollars)) {}

public:
    void enterExchange() {
        std::cout << "Welcome to our exchange!\n";
        std::cout << "Currently, we supports three currencies!\n";
        std::cout << "It's Euro, dollars and Polish zloty.\n";
        std::cout << "Choose a currency, which you would like to exchange to:\n";
        std::cout << "1. PLN, 2. USD, 3. EUR\n";
        int currencyToExchange;
        std::cin >> currencyToExchange;
        double amount;
        switch (currencyToExchange) {
            case 1: {
                std::cout << "How much PLN do you have?\n";
                std::cin >> amount;
                if (amount <= 0) {
                    throw std::invalid_argument("Get outta here and earn some money first!");
                    break;
                }
                PLN plnAmount(amount);
                std::cout << "Great, we can do business now!!\n";
                std::cout << "It's time for exchange! \n";
                std::cout << "You can exchange PLN to: 1. EUR and 2. USD\n";
                std::cin >> currencyToExchange;
                switch (currencyToExchange) {
                    case 1: {
                        double newValue = euro.exchangerFromPLNToEUR(plnAmount);
                        std::cout << "Your EUR: " << newValue << std::endl;
                        std::cout << "Thank you for using our services!";
                        break;
                    }
                    case 2: {
                        double newValue = dollars.exchangerFromPLNtoUSD(plnAmount);
                        std::cout << "Your USD: " << newValue << std::endl;
                        std::cout << "Thank you for using our services!";
                        break;
                    }
                    default: {
                        throw std::invalid_argument("We don't have such an option. See you next time!");
                    }
                }
                break;
            }
            case 2: {
                std::cout << "How much dollars do you have?\n";
                std::cin >> amount;
                if (amount <= 0) {
                    throw std::invalid_argument("Emptily?");
                }
                USD usdAmount(amount);
                std::cout << "Great, we can do business now!!\n";
                std::cout << "It's time for exchange! \n";
                std::cout << "You can exchange USD to 1. PLN, 2. EUR\n";
                std::cin >> currencyToExchange;
                switch (currencyToExchange) {
                    case 1: {
                        double newValue = pln.exchangerFromUSDToPLN(usdAmount);
                        std::cout << "Your PLN: " << newValue << std::endl;
                        std::cout << "Thank you for using our services!";
                        break;
                    }
                    case 2: {
                        double newValue = euro.exchangerFromUSDtoEUR(usdAmount);
                        std::cout << "Your EUR: " << newValue << std::endl;
                        std::cout << "Thank you for using our services!";
                        break;
                    }
                    default: {
                        throw std::invalid_argument("We don't have such a currency. See you next time!");
                    }
                }
                break;
            }
            case 3: {
                std::cout << "How much Euro do you have?\n";
                std::cin >> amount;
                if (amount <= 0) {
                    throw std::invalid_argument("Find a job and then we will talk!");
                }
                EUR eurAmount(amount);
                std::cout << "Great! We can do business now!\n";
                std::cout << "It's time for currency exchange!\n";
                std::cout << "You can exchange EUR to: 1. PLN, 2. USD\n";
                std::cin >> currencyToExchange;
                switch (currencyToExchange) {
                    case 1: {
                        double newValue = pln.exchangerFromEURToPLN(eurAmount);
                        std::cout << "Your PLN:" << newValue << std::endl;
                        std::cout << "Thank you for using our services!";
                        break;
                    }
                    case 2: {
                        double newValue = dollars.exchangerFromEURtoUSD(eurAmount);
                        std::cout << "Your EUR: " << newValue << std::endl;
                        std::cout << "Thank you for using our services!";
                        break;
                    }
                    default: {
                        throw std::invalid_argument("We don't have such an option. See you next time!");
                    }
                }
                break;
            }
            default: {
                throw std::invalid_argument("A fraud! A fraud!");
            }
        }
    }
};
#endif //OOP1___KANTOR_WALUT_EXCHANGE_H
