#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <iostream>

using namespace std;

class Passenger
{
public:
    Passenger();

    // update passenger's floor level as elevator moving
    void updateFloor(int floor);

    void toggleInElevator();

    // basic
    bool getInElevator();
    int getCurrFloor();

private:
    // state passenger's current floor
    int currFloor;
    bool inElevator;
};

#endif // PASSENGER_H
