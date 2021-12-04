#include "screen.h"
#include <iostream>
#include <wiringSerial.h>







int main(void) {


    //INIT
    Init();

    // changement de température
    double temp = 22.5;
    setTemp(temp);
    std::cout << "temperature modifiee" << std::endl;

    //changement de puissance
    double pwr = 3400.2;
    setPwr(pwr);

    //changement de coordonées géographique
    setPosition(50.411986, 4.442602);
    

    //changement de puissance du signal
    int signal = 3;
    setSignal(signal);

    int hmi = status();

    int val = 0;
    while (serialDataAvail(hmi)) {
        val = serialGetchar(hmi);
        std::cout << "data: " << val << std::endl;
    }
    close();
    while(1){}
	return 0;

}