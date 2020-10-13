#ifndef EVENTS_H
#define EVENTS_H
#include <vector>
#include<iostream>
#include<fstream>
#include "event.h"
/// Class Events represents set of Trainings (Event objects)
/// @see Event
class Events
{
public:
    /// Events constructor
    Events();

    /// Events destructor
    ~Events();

    std::vector<Event> events;              /*!< Vector of family trainings */

    /// Method checking whether there is in datebase any such person's training on such day
    /// @param p_name -> name of person [QString]
    /// @param g_date -> date of training [QString]
    /// @retuns true if is in trainings person's training on such date, else false
    bool isPersonEvent(QString p_name, QString g_date);

    /// Operator += adding training to trainings
    /// @param ev -> training [Event]
    void operator+=(Event ev);

    /// Method deleting training from trainings
    /// @param p_name -> name of person [QString]
    /// @param act_name -> type of training [QString]
    /// @param g_date -> date of training [QString]
    /// @param g_stime -> starting time of training [QString]
    void delEvent(QString p_name, QString act_name, QString g_date, QString g_stime);

    /// Method loading trainings from file
    /// @param filepath -> path to file from which trainings are loaded [QString]
    void getFromFile(QString filepath);

    /// Method saving trainings to file
    /// @param filename -> path to file to which trainings will be saved [std::string]
    void saveToFile(std::string filepath);

    /// Static method comparing times of training
    /// @param ev1 -> first trainig [Event]
    /// @param ev2 -> second training [Event]
    /// @returns true if ev1 is earlier than e2, else false
    static bool comparePtrs(Event ev1, Event ev2);
private:
    /// Method adding training to trainings
    /// @param ev -> training to add [Event]
    void addEvent(Event ev);
};

#endif // EVENTS_H
