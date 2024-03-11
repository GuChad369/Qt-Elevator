#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <string>
#include <vector>
#include <queue>
#include "Passenger.h"

using namespace std;

class Elevator
{
public:
     static int nextId;
    Elevator();

    void goUpOneFloor();
    void goDownOneFloor();
    void arrive();

    // open door
    void ringBell();
    void openDoor();
    void addPassenger(Passenger* p);
    void removePassenger();
    void closeDoor();

    // door obstacle
    void warning();
    void displayText(const string &text);

    // elevator fire
    void fire();

    // elevator overload
    void overload();

    // power out
    void powerOut();


    // basic
    bool getAvailable();
    void setAvailable(bool);
    int getCurrFloor();
    bool isEmpty();
    int getId();



private:
    const int ID;
    int currFloor;
    bool available;

    bool door;

    vector<Passenger*> passengers;

};

#endif // ELEVATOR_H
