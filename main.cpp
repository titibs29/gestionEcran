#include "screen.h"
#include <iostream>
#include <wiringSerial.h>
#include "screen.h"
#include "nextion/Nextion.h"







int main(void) {

    //INIT
    


    Init();

    // changement de temp�rature
    double temp = 22.3;
    setTemp(temp);

    //changement de puissance
    double pwr = 3400.2;
    setPwr(pwr);

    //changement de coordon�es g�ographique
    setPosition(50.411986, 4.442602);
    

    //changement de puissance du signal
    int signal = 3;
    setSignal(signal);

	return 0;

}