#include <iostream>
#include <wiringSerial.h>
#include "screen.h"







int main(void) {

    //INIT
    Init();
    std::cout << "connexion etablie" << std::endl;


    // changement de température

    double temp = 22.3;
    setTemp(temp);
    std::cout << "temperature changee" << std::endl;

    //changement de puissance
    double pwr = 3400.0;
    setPwr(pwr);
    std::cout << "puissance changee" << std::endl;


    //changement de coordonées géographique
    setPosition(50.411986, 4.442602);
    std::cout << "position changee" << std::endl;


    //changement de puissance du signal
    int signal = 3;
    setSignal(signal);
    std::cout << "signal change" << std::endl;


	return 0;

}