#include "screen.h"

#define LENGTH 50

int hmi = 0;

void sendCommand(const char* cmd)
{
    while (serialDataAvail(hmi))
    {
        serialGetchar(hmi);
    }

    serialPrintf(hmi, cmd);
    serialPutchar(hmi, 0xFF);
    serialPutchar(hmi, 0xFF);
    serialPutchar(hmi, 0xFF);
}

    void Init()
{


    const char* device = "/dev/ttyS0";  //dossier de serial0, vor 'ls /dev -l'
    int baud = 9600;
    hmi = serialOpen(device, baud);

    sendCommand("");
    sendCommand("bkcmd=1");
    while (serialDataAvail(hmi))
    {
        serialGetchar(hmi);
    }

    sendCommand("page 0");
    while (serialDataAvail(hmi))
    {
        serialGetchar(hmi);
    }
    
}

void setTemp(double temp)
{
    int temperature = int(temp*10);
    char text[LENGTH*sizeof(char)];
    std::sprintf(text, "temp_val.val=%d", temperature);
    sendCommand(text);
    int val = 0;
    while (serialDataAvail(hmi)) {
        val = serialGetchar(hmi);
    }
}

void setTemp(int temp)
{
    int temperature = temp * 10;
    char text[LENGTH * sizeof(char)];
    std::sprintf(text, "temp_val.val=%d", temperature);
    sendCommand(text);
    int val = 0;
    
}

void setPwr(double pwr)
{
    int power = int(pwr * 10);
    char text[LENGTH * sizeof(char)];
    std::sprintf(text, "pow_val.val=%d", power);
    sendCommand(text);
}

void setLatitude(int lat)
{
    char text[LENGTH * sizeof(char)];
    std::sprintf(text, "lat_val.val=%d", lat);
    sendCommand(text);
}

void setLongitude(int lon)
{
    char text[LENGTH * sizeof(char)];
    std::sprintf(text, "lon_val.val=%d", lon);
    sendCommand(text);
}

void setPosition(double lat,double lon)
{
    int latitude = int(lat * 1000000);
    int longitude = int(lon * 1000000);

    setLatitude(latitude);
    setLongitude(longitude);
}

void setSignal(int signal)
{
    char text[LENGTH * sizeof(char)];
    std::sprintf(text, "sig_val.val=%d", signal);
    sendCommand(text);
}

int status()
{
    return hmi;
}

void close()
{
    serialClose(hmi);
}


