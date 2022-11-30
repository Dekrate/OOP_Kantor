#include <iostream>
#include "Money/PLN.h"
#include "Exchangers/PLNExchange.h"
#include "Exchangers/DollarsExchange.h"
#include "Exchangers/EuroExchange.h"
#include "Exchange.h"
#include <limits>

int main() {
    setlocale(LC_CTYPE, "Polish");
    double fromEURToPLN;
    double fromUSDToPLN;
    double fromPLNToEuro;
    double fromUSDToEuro;
    double fromPLNToUSD;
    double fromEURToUSD;

    std::cout << "Konfigurowanie walut. Dla symulacji, laskawie pozwalamy na wprowadzenie wlasnych kursow\n";
    std::cout << "Dla lepszego doswiadczenia, polecam sprawdzic kursy w internecie.\n";
    std::cout << "Wybierz wlasciwe dane, bowiem na nich bedzie opieal sie caly program!\n";
    std::cout << "Zeby nie przedluzac, wpisz prosze dwie wartosci oddzielone za pomoca spacji"
                 "- najpierw dla zlotowek - z euro na zlotowki i z"
                 "dolarow na zlotowki - kazdy pojedynczo i w osobnej linii.\n";
    try {
        std::cin >> fromEURToPLN;
        while((std::cin.fail())||(fromEURToPLN<=1))
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
            std::cout << "Nie wprowadzono liczby lub jest nieprawidlowa. Sprobuj ponownie: ";
            std::cin >> fromEURToPLN;
        }
        std::cin >> fromUSDToPLN;
        while((std::cin.fail())||(fromUSDToPLN<=1))
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
            std::cout << "Nie wprowadzono liczby lub jest nieprawidlowa. Sprobuj ponownie: ";
            std::cin >> fromUSDToPLN;
        }
        PLNExchange plnExchange(fromEURToPLN, fromUSDToPLN);
        std::cout << "Doskonale! Teraz czas na cos grubego - euraski. Najpierw z PLN na Euro, a potem z USD na Euro.\n";
        std::cin >> fromPLNToEuro;
        while((std::cin.fail())||(fromPLNToEuro<=0))
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
            std::cout << "Nie wprowadzono liczby lub jest nieprawidlowa. Sprobuj ponownie: ";
            std::cin >> fromPLNToEuro;
        }
        std::cin >> fromUSDToEuro;
        while((std::cin.fail())||(fromUSDToEuro<=0))
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
            std::cout << "Nie wprowadzono liczby lub jest nieprawidlowa. Sprobuj ponownie: ";
            std::cin >> fromUSDToEuro;
        }
//        cin>>y;
//        while((cin.fail())||(y<1))
//        {
//            cin.clear();
//            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
//            cout << "Nie wprowadzono liczby. Sprobuj ponownie: ";
//            cin >> y;
//        }
        EuroExchange euroExchange(fromPLNToEuro, fromUSDToEuro);
        std::cout << "Na koniec gwozdz programu - dolarki! Na poczatek z PLN na USD, potem z EUR na USD\n";
        std::cin >> fromPLNToUSD;
        while((std::cin.fail())||(fromPLNToUSD<=0))
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
            std::cout << "Nie wprowadzono liczby. Sprobuj ponownie: ";
            std::cin >> fromPLNToUSD;
        }
        std::cin >> fromEURToUSD;
        while((std::cin.fail())||(fromEURToUSD<=1))
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
            std::cout << "Nie wprowadzono liczby. Sprobuj ponownie: ";
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

