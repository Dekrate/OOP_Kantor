#include <iostream>
#include "Exchange.h"
#include "src/Exchangers/PLNExchange.h"
#include "src/Exchangers/EuroExchange.h"
#include "src/Exchangers/DollarsExchange.h"
#include <limits>

int main() {
    double fromEURToPLN;
    double fromUSDToPLN;
    double fromPLNToEuro;
    double fromUSDToEuro;
    double fromPLNToUSD;
    double fromEURToUSD;

    std::cout << "Configuring currencies. For better simulation, you can easily press exchange rates.\n";
    std::cout << "If you want to immerse better, please check them on the internet.\n";
    std::cout << "Put two values separated by space - first for PLNs: from EUR to PLN and from USD to PLN"
                 "Every input must be in separate line!\n";
    try {
        std::cin >> fromEURToPLN;
        while((std::cin.fail())||(fromEURToPLN<=1))
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
            std::cout << "You didn't input proper value. Try again: ";
            std::cin >> fromEURToPLN;
        }
        std::cin >> fromUSDToPLN;
        while((std::cin.fail())||(fromUSDToPLN<=1))
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
            std::cout << "You didn't input proper value. Try again: ";
            std::cin >> fromUSDToPLN;
        }
        PLNExchange plnExchange(fromEURToPLN, fromUSDToPLN);
        std::cout << "Great! Now it's time for Euro - firstly from PLN to Euro, then from USD to Euro.\n";
        std::cin >> fromPLNToEuro;
        while((std::cin.fail())||(fromPLNToEuro<=0))
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
            std::cout << "You didn't input proper value. Try again: ";
            std::cin >> fromPLNToEuro;
        }
        std::cin >> fromUSDToEuro;
        while((std::cin.fail())||(fromUSDToEuro<=0))
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
            std::cout << "You didn't input proper value. Try again: ";
            std::cin >> fromUSDToEuro;
        }
        EuroExchange euroExchange(fromPLNToEuro, fromUSDToEuro);
        std::cout << "And finally - dollars! First of all, press from PLN to USD, then from EUR to USD \n";
        std::cin >> fromPLNToUSD;
        while((std::cin.fail())||(fromPLNToUSD<=0))
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
            std::cout << "You didn't input proper value. Try again: ";
            std::cin >> fromPLNToUSD;
        }
        std::cin >> fromEURToUSD;
        while((std::cin.fail())||(fromEURToUSD<=1))
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
            std::cout << "You didn't input proper value. Try again: ";
            std::cin >> fromEURToUSD;
        }
        DollarsExchange dollarsExchange(fromPLNToUSD, fromEURToUSD);
        Exchange exchange(euroExchange, plnExchange, dollarsExchange);
        try {
            exchange.enterExchange();
        } catch (std::invalid_argument& e) {
            std::cout << e.what();
        }
    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

