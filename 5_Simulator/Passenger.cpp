#include "Passenger.h"

Passenger::Passenger():currFloor(1),inElevator(false)
{

}

void Passenger::updateFloor(int floor){
    currFloor = floor;
}


bool Passenger::getInElevator(){
    return inElevator;
}

void Passenger::toggleInElevator(){
    inElevator = !inElevator;
}

int Passenger::getCurrFloor(){
    return currFloor;
}
