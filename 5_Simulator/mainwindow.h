#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <vector>
#include "Passenger.h"
#include "Elevator.h"
#include <chrono>
#include <thread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // get an available elevator
    Elevator* getAvailable();
    // make elevator response to the request
    void responseRequest(Elevator* e, int floor,Passenger*p);
    // make elevator response to panel request
    void responsePanel(Elevator* e, int floor);
    // refresh display
    void refreshDisplay();
    // set timeer for help button
    void resetTimer();

private:
    Ui::MainWindow *ui;
    // set up a timer for help button
    QTimer * timer;
    // set up a timer for door obstacle
    QTimer * clickTimer;
    int clickCounter;
    vector<Passenger *> passengers;
    vector<Elevator *> elevators;


private slots:
    // reset button
    void resetAll();

    // passenger up down button
    void pressUpDownButton(int index);

    // Elevator panel number button
    void pressPanelNumber(int index, int floor);

    // Elevator Open Close button
    void pressOpen(int index);
    void pressClose(int index);

    // Elevator Help button
    void pressHelp(int index);
    void call911();
    void pressCSHelp();

    // Elevator obstacle button
    void pressObstacle(int index);
    void resetClickCounter();

    // Fire button
    void pressCSFire();
    void pressFire(int index);

    // Elevator overload button
    void pressOverload(int index);

    // power button
    void pressPowerOut();

};
#endif // MAINWINDOW_H
