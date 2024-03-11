#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,clickCounter(0)
{
    ui->setupUi(this);

    // initial passengers
    Passenger * p1 = new Passenger();
    Passenger * p2 = new Passenger();
    Passenger * p3 = new Passenger();
    passengers.push_back(p1);
    passengers.push_back(p2);
    passengers.push_back(p3);

    // initial elevators
    Elevator::nextId = 1;
    Elevator * e1 = new Elevator();
    Elevator * e2 = new Elevator();
    Elevator * e3 = new Elevator();
    elevators.push_back(e1);
    elevators.push_back(e2);
    elevators.push_back(e3);

    // display
    refreshDisplay();

    // reset all
    connect(ui->reset, &QPushButton::clicked, this, &MainWindow::resetAll);


    // Passenger Buttons
    connect(ui->up1, &QPushButton::clicked, [this]() {
        pressUpDownButton(0);
    });
    connect(ui->up2, &QPushButton::clicked, [this]() {
        pressUpDownButton(1);
    });
    connect(ui->up3, &QPushButton::clicked, [this]() {
        pressUpDownButton(2);
    });

    connect(ui->down1, &QPushButton::clicked, [this]() {
        pressUpDownButton(0);
    });
    connect(ui->down2, &QPushButton::clicked, [this]() {
        pressUpDownButton(1);
    });
    connect(ui->down3, &QPushButton::clicked, [this]() {
        pressUpDownButton(2);
    });

    // Elevator Buttons
    connect(ui->ePanel11, &QPushButton::clicked, [this]() {
        pressPanelNumber(0,1);  // Pass the value 1 to the slot
    });
    connect(ui->ePanel12, &QPushButton::clicked, [this]() {
        pressPanelNumber(0,2);
    });
    connect(ui->ePanel13, &QPushButton::clicked, [this]() {
        pressPanelNumber(0,3);
    });
    connect(ui->ePanel14, &QPushButton::clicked, [this]() {
        pressPanelNumber(0,4);
    });
    connect(ui->ePanel15, &QPushButton::clicked, [this]() {
        pressPanelNumber(0,5);
    });
    connect(ui->ePanel16, &QPushButton::clicked, [this]() {
        pressPanelNumber(0,6);
    });
    connect(ui->ePanel17, &QPushButton::clicked, [this]() {
        pressPanelNumber(0,7);
    });

    connect(ui->ePanel21, &QPushButton::clicked, [this]() {
        pressPanelNumber(1,1);
    });
    connect(ui->ePanel22, &QPushButton::clicked, [this]() {
        pressPanelNumber(1,2);
    });
    connect(ui->ePanel23, &QPushButton::clicked, [this]() {
        pressPanelNumber(1,3);
    });
    connect(ui->ePanel24, &QPushButton::clicked, [this]() {
        pressPanelNumber(1,4);
    });
    connect(ui->ePanel25, &QPushButton::clicked, [this]() {
        pressPanelNumber(1,5);
    });
    connect(ui->ePanel26, &QPushButton::clicked, [this]() {
        pressPanelNumber(1,6);
    });
    connect(ui->ePanel27, &QPushButton::clicked, [this]() {
        pressPanelNumber(1,7);
    });

    connect(ui->ePanel31, &QPushButton::clicked, [this]() {
        pressPanelNumber(2,1);
    });
    connect(ui->ePanel32, &QPushButton::clicked, [this]() {
        pressPanelNumber(2,2);
    });
    connect(ui->ePanel33, &QPushButton::clicked, [this]() {
        pressPanelNumber(2,3);
    });
    connect(ui->ePanel34, &QPushButton::clicked, [this]() {
        pressPanelNumber(2,4);
    });
    connect(ui->ePanel35, &QPushButton::clicked, [this]() {
        pressPanelNumber(2,5);
    });
    connect(ui->ePanel36, &QPushButton::clicked, [this]() {
        pressPanelNumber(2,6);
    });
    connect(ui->ePanel37, &QPushButton::clicked, [this]() {
        pressPanelNumber(2,7);
    });

    // Elevator Open Close button
    connect(ui->open1, &QPushButton::clicked, [this]() {
        pressOpen(0);
    });
    connect(ui->open2, &QPushButton::clicked, [this]() {
        pressOpen(1);
    });
    connect(ui->open3, &QPushButton::clicked, [this]() {
        pressOpen(2);
    });
    connect(ui->close1, &QPushButton::clicked, [this]() {
        pressClose(0);
    });
    connect(ui->close2, &QPushButton::clicked, [this]() {
        pressClose(1);
    });
    connect(ui->close3, &QPushButton::clicked, [this]() {
        pressClose(2);
    });

    // Elevator Help button
    connect(ui->help1, &QPushButton::clicked, [this]() {
        pressHelp(0);
    });
    connect(ui->help2, &QPushButton::clicked, [this]() {
        pressHelp(1);
    });
    connect(ui->help3, &QPushButton::clicked, [this]() {
        pressHelp(2);
    });
    connect(ui->help, SIGNAL(clicked()), this, SLOT(pressCSHelp()));

    // Elevator obstacle button
    connect(ui->obstacle1, &QPushButton::clicked, [this]() {
        pressObstacle(0);
    });
    connect(ui->obstacle2, &QPushButton::clicked, [this]() {
        pressObstacle(1);
    });
    connect(ui->obstacle3, &QPushButton::clicked, [this]() {
        pressObstacle(2);
    });
    clickTimer = new QTimer(this);
    clickTimer->setInterval(1000); // Set the interval to 1 second
    connect(clickTimer, &QTimer::timeout, this, &MainWindow::resetClickCounter);

    // Fire button
    connect(ui->fire_signal, SIGNAL(clicked()), this, SLOT(pressCSFire()));
    connect(ui->fire1, &QPushButton::clicked, [this]() {
        pressFire(0);
    });
    connect(ui->fire2, &QPushButton::clicked, [this]() {
        pressFire(1);
    });
    connect(ui->fire3, &QPushButton::clicked, [this]() {
        pressFire(2);
    });

    // Elevator overload button
    connect(ui->overload1, &QPushButton::clicked, [this]() {
        pressOverload(0);
    });
    connect(ui->overload2, &QPushButton::clicked, [this]() {
        pressOverload(1);
    });
    connect(ui->overload3, &QPushButton::clicked, [this]() {
        pressOverload(2);
    });

    // Power out button
    connect(ui->power_out, SIGNAL(clicked()), this, SLOT(pressPowerOut()));


}

void MainWindow::resetAll(){
    this->close();

    // Create a new instance of the main window
    MainWindow *newWindow = new MainWindow();
    newWindow->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    for (Passenger* p : passengers) {
        delete p;
    }
    for (Elevator* e : elevators) {
        delete e;
    }
}

Elevator* MainWindow::getAvailable(){
    for (Elevator* e : elevators) {
        if(e->getAvailable()){
            return e;
        }
    }
    return nullptr;
}

void MainWindow::responseRequest(Elevator * e, int floor,Passenger*p){
    // make is unavailable
    e->setAvailable(false);

    // elevator need to go up
    while(floor > e->getCurrFloor()){
        this_thread::sleep_for(std::chrono::seconds(1));
        e->goUpOneFloor();
        refreshDisplay();
        // process events to update UI
        QCoreApplication::processEvents();
    }

    // elevator need to go down
    while(floor < e->getCurrFloor()){
        this_thread::sleep_for(std::chrono::seconds(1));
        e->goDownOneFloor();
        refreshDisplay();
        // process events to update UI
        QCoreApplication::processEvents();
    }

    // open door get passenger in
    e->arrive();
    e->ringBell();
    e->openDoor();
    e->addPassenger(p);
    qInfo("The Door sustains 10 seconds...");
    this_thread::sleep_for(std::chrono::seconds(2));
    e->ringBell();
    e->closeDoor();
    cout<<endl;
}

void MainWindow::responsePanel(Elevator *e, int floor){
    // elevator need to go up
    while(floor > e->getCurrFloor()){
        this_thread::sleep_for(std::chrono::seconds(1));
        e->goUpOneFloor();
        refreshDisplay();
        // process events to update UI
        QCoreApplication::processEvents();
    }

    // elevator need to go down
    while(floor < e->getCurrFloor()){
        this_thread::sleep_for(std::chrono::seconds(1));
        e->goDownOneFloor();
        refreshDisplay();
        // process events to update UI
        QCoreApplication::processEvents();
    }

    // open door get passenger out
    e->arrive();
    e->ringBell();
    e->openDoor();
    e->removePassenger();
    qInfo("The Door sustains 10 seconds...");
    this_thread::sleep_for(std::chrono::seconds(2));
    e->ringBell();
    e->closeDoor();
    cout<<endl;

    // make it available again
    e->setAvailable(true);
}

void MainWindow::refreshDisplay(){
    // set LCD number
    ui->pFloor1->display(passengers[0]->getCurrFloor());
    ui->pFloor2->display(passengers[1]->getCurrFloor());
    ui->pFloor3->display(passengers[2]->getCurrFloor());

    ui->eFloor1->display(elevators[0]->getCurrFloor());
    ui->eFloor2->display(elevators[1]->getCurrFloor());
    ui->eFloor3->display(elevators[2]->getCurrFloor());
}



// Passenger Buttonss
void MainWindow::pressUpDownButton(int index){
    if(passengers[index]->getInElevator()){
        qInfo("Passenger is in one elevator!");
        cout<<endl;
        return;
    }

    Elevator* e = getAvailable();

    if(e == nullptr){
        qInfo("No avaliable elevator!");
        cout<<endl;
        return;
    }
    cout<<"Button remains illuminated until the elevator arrives....";

    int floor = passengers[index]->getCurrFloor();

    responseRequest(e,floor,passengers[index]);


}

// Elevator Buttons
void MainWindow::pressPanelNumber(int index, int floor){
    // get elevator
    Elevator * e = elevators[index];

    // check passenger
    if(e->isEmpty()){
        qInfo("There is no passenger in this Elevator!");
        cout<<endl;
        return;
    }
    cout <<floor<<" floor button is pressed!"<<endl;
    responsePanel(e,floor);
}

void MainWindow::pressOpen(int index){
    // get elevator
    Elevator * e = elevators[index];


    // check passenger
    if(e->isEmpty()){
        qInfo("There is no passenger in this Elevator!");
        cout<<endl;
        return;
    }
    e->ringBell();
    e->openDoor();
    cout<<endl;
}

void MainWindow::pressClose(int index){
    // get elevator
    Elevator * e = elevators[index];


    // check passenger
    if(e->isEmpty()){
        qInfo("There is no passenger in this Elevator!");
        return;
    }
    e->ringBell();
    e->closeDoor();
    cout<<endl;
}

void MainWindow::pressHelp(int index){
    // get elevator
    Elevator * e = elevators[index];


    // check passenger
    if(e->isEmpty()){
        qInfo("There is no passenger in this Elevator!");
        cout<<endl;
        return;
    }

    cout<<"Need Help!"<<endl;

    resetTimer();
}

void MainWindow::call911(){
    qInfo("Calling 911 ...");
    cout<<endl;
    if (timer != nullptr) {
        timer->stop();
    }
}

void MainWindow::pressCSHelp(){

    cout<<"Get Help!"<<endl;

    // reset timer
    resetTimer();
}

void MainWindow::resetTimer() {
    if(timer != nullptr){
        disconnect(timer, &QTimer::timeout, this, &MainWindow::call911);
        timer->stop();
        delete timer;
        timer = nullptr;
    }

    timer = new QTimer(this);
    timer->setInterval(5000); // 5000 milliseconds = 5 seconds
    connect(timer, &QTimer::timeout, this, &MainWindow::call911);
    timer->start();
}


void MainWindow::pressObstacle(int index){
    // get elevator
    Elevator * e = elevators[index];



    clickCounter++;
    if(clickCounter >= 5){
        e->warning();
        e->displayText("******The door is blocked!******");
    }
    // restart the timer to reset clickcounter
    clickTimer->start();

    cout<<"Door Obstacles!"<<endl;
    e->ringBell();
    e->openDoor();
    cout<<endl;
}

void MainWindow::resetClickCounter(){
    clickCounter = 0;
}

void MainWindow::pressCSFire(){
    qInfo("Fire signal!");
    this_thread::sleep_for(std::chrono::seconds(1));
    for(Elevator* e : elevators){

        e->fire();
        e->warning();
        e->displayText("******There is a fire, please leave after door open!******");
        responsePanel(e,1);
        e->setAvailable(false);
    }
}

void MainWindow::pressFire(int index){
    // get elevator
    Elevator * e = elevators[index];




    string text = "Elevator" + to_string(e->getId()) + " has fire issue!";
    qInfo("%s", text.c_str());
    this_thread::sleep_for(std::chrono::seconds(1));
    e->fire();
    e->warning();
    e->displayText("******There is a fire, please leave after door open!******");
    responsePanel(e,1);
    e->setAvailable(false);

}

void MainWindow::pressOverload(int index){
    // get elevator
    Elevator * e = elevators[index];


    string text = "Elevator" + to_string(e->getId()) + " overload!";
    qInfo("%s", text.c_str());
    this_thread::sleep_for(std::chrono::seconds(1));
    e->overload();
    e->warning();
    e->displayText("******Overloading!******");
    cout<<endl;

}

void MainWindow::pressPowerOut(){
    qInfo("Power Out!");
    this_thread::sleep_for(std::chrono::seconds(1));
    for(Elevator* e : elevators){

        e->powerOut();
        e->warning();
        e->displayText("******There is no power, please leave after door open!******");
        responsePanel(e,1);
        e->setAvailable(false);
    }
}
