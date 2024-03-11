#include "Elevator.h"

int Elevator::nextId = 1;

Elevator::Elevator():ID(nextId),currFloor(1),available(true),door(false)
{
    Elevator::nextId += 1;
}



void Elevator::goUpOneFloor(){
    currFloor++;
    for (Passenger* p : passengers) {
            p->updateFloor(currFloor);
    }
}

void Elevator::goDownOneFloor(){
    currFloor--;
    for (Passenger* p : passengers) {
                p->updateFloor(currFloor);
        }
}

void Elevator::arrive(){
    cout<<"Elevator"<<ID<<" arrives "<< currFloor<<" floor!"<<endl;
}

void Elevator::ringBell(){
    cout<<"Elevator"<<ID<<": Ring Bell!"<<endl;
}

void Elevator::openDoor(){
    door = true;
    cout<<"Elevator"<<ID<<": Open Door!"<<endl;
}

void Elevator::addPassenger(Passenger*p){
    passengers.push_back(p);
    p->toggleInElevator();
    cout<<"Elevator"<<ID<<": Passenger In!"<<endl;
}

void Elevator::removePassenger(){
    for(Passenger* p:passengers){
        p->toggleInElevator();
    }
    passengers.clear();
    cout<<"Elevator"<<ID<<": Passenger Out!"<<endl;
}

void Elevator::closeDoor(){
    door = false;
    cout<<"Elevator"<<ID<<": Close Door!"<<endl;
}

void Elevator::warning(){
    cout<<"******Sounds Warning!******"<<endl;
}

void Elevator::displayText(const string &text){
    cout<<text<<endl;
}

void Elevator::fire(){
    cout<<"Elevator"<<ID<<" are moving to safe floor!"<<endl;
}

void Elevator::overload(){
    cout<<"Elevator"<<ID<<" is overloading!"<<endl;
}

void Elevator::powerOut(){
    cout<<"Elevator"<<ID<<" are moving to safe floor!"<<endl;
}

// basic
bool Elevator::getAvailable(){
    return available;

}
int Elevator::getCurrFloor(){
    return currFloor;
}

void Elevator::setAvailable(bool b){
    available = b;
}

bool Elevator::isEmpty(){
    return passengers.size() == 0;
}

int Elevator::getId(){
    return ID;
}
