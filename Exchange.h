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
        std::cout << "Witaj w kantorze!\n";
        std::cout << "Aktualnie obslugujemy trzy rodzaje walut, naszym skromnym zdaniem najpopularniejsze!\n";
        std::cout << "To Euro - bo wiadomo, mozna zaszpanowac, ze jest sie swiatowym\n";
        std::cout << "Nastepnie nasze ukochane, rodzime zlotoweczki.\n";
        std::cout << "A na sam koniec - dolary! Az przypominaja sie czasy PeWeXow!\n";
        std::cout << "Na poczatek, wybierz walute, na ktorej bedziesz chcial dokonac wymiany:\n";
        std::cout << "1. PLN, 2. USD, 3. EUR\n";
        int currencyToExchange;
        std::cin >> currencyToExchange;
        double amount;
        switch (currencyToExchange) {
            case 1: {
                std::cout << "Ile masz zlotoweczek?\n";
                std::cin >> amount;
                if (amount <= 0) {
                    throw std::invalid_argument("Najpierw idz zarobic, a potem pogadamy!");
                    break;
                }
                PLN plnAmount(amount);
                std::cout << "Swietnie! Mozemy przejsc do rzeczy!\n";
                std::cout << "Teraz czas na wymiane walut! \n";
                std::cout << "Mozesz wymienic PLN na 1. EUR, 2. USD\n";
                std::cin >> currencyToExchange;
                switch (currencyToExchange) {
                    case 1: {
                        double newValue = euro.exchangerFromPLNToEUR(plnAmount);
                        std::cout << "Transakcja pomyslna! Twoje EUR to: " << newValue << std::endl;
                        std::cout << "Dziekujemy za skorzystanie z naszych uslug!";
                        break;
                    }
                    case 2: {
                        double newValue = dollars.exchangerFromPLNtoUSD(plnAmount);
                        std::cout << "Transakcja pomyslna! Twoje USD to: " << newValue << std::endl;
                        std::cout << "Dziekujemy za skorzystanie z naszych uslug!";
                        break;
                    }
                    default: {
                        throw std::invalid_argument("Nie mamy takiej opcji w naszej ofercie. Zapraszamy innym razem!");
                    }
                }
                break;
            }
            case 2: {
                std::cout << "Ile masz dolarow?\n";
                std::cin >> amount;
                if (amount <= 0) {
                    throw std::invalid_argument("Pusto w kieszeniach, co?");
                }
                USD usdAmount(amount);
                std::cout << "Swietnie! Mozemy przejsc do rzeczy!\n";
                std::cout << "Teraz czas na wymiane walut! \n";
                std::cout << "Mozesz wymienic USD na 1. PLN, 2. EUR\n";
                std::cin >> currencyToExchange;
                switch (currencyToExchange) {
                    case 1: {
                        double newValue = pln.exchangerFromUSDToPLN(usdAmount);
                        std::cout << "Transakcja pomyslna! Twoje PLN to: " << newValue << std::endl;
                        std::cout << "Dziekujemy za skorzystanie z naszych uslug!";
                        break;
                    }
                    case 2: {
                        double newValue = euro.exchangerFromUSDtoEUR(usdAmount);
                        std::cout << "Transakcja pomyslna! Twoje EUR to: " << newValue << std::endl;
                        std::cout << "Dziekujemy za skorzystanie z naszych uslug!";
                        break;
                    }
                    default: {
                        throw std::invalid_argument("Nie mamy takiej opcji w naszej ofercie. Zapraszamy innym razem!");
                    }
                }
                break;
            }
            case 3: {
                std::cout << "Ile masz euro?\n";
                std::cin >> amount;
                if (amount <= 0) {
                    throw std::invalid_argument("Najpierw idz zarobic, a potem pogadamy!");
                }
                EUR eurAmount(amount);
                std::cout << "Swietnie! Mozemy przejsc do rzeczy!\n";
                std::cout << "Teraz czas na wymiane walut! \n";
                std::cout << "Mozesz wymienic EUR na 1. PLN, 2. USD\n";
                std::cin >> currencyToExchange;
                switch (currencyToExchange) {
                    case 1: {
                        double newValue = pln.exchangerFromEURToPLN(eurAmount);
                        std::cout << "Transakcja pomyslna! Twoje PLN to: " << newValue << std::endl;
                        std::cout << "Dziekujemy za skorzystanie z naszych uslug!";
                        break;
                    }
                    case 2: {
                        double newValue = dollars.exchangerFromEURtoUSD(eurAmount);
                        std::cout << "Transakcja pomyslna! Twoje EUR to: " << newValue << std::endl;
                        std::cout << "Dziekujemy za skorzystanie z naszych uslug!";
                        break;
                    }
                    default: {
                        throw std::invalid_argument("Nie mamy takiej opcji w naszej ofercie. Zapraszamy innym razem!");
                    }
                }
                break;
            }
            default: {
                throw std::invalid_argument("Nie badz oszustem! Wychodzisz!");
            }
        }
    }
};
#endif //OOP1___KANTOR_WALUT_EXCHANGE_H
