#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include "Date.h"
#include <vector>
#include <map>
#include <ctime>

using namespace std;

struct Point {
    string receivedMonth;
    string receivedDate;
    string receivedYear;
    int amount;
    string reason;
    string admin;
    void printPoint();
    bool operator<(Point &);
    int getMonthIndex(string month);
};

class Employee {
    private:
        string firstname;
        string lastname;
        string charlesNumber;
    public:
        vector<Point> points;
        Employee(string fname, string lname, string cNumber);
        const void printEmployee();
        const void printAllPoints();
        int getTotalPoints();
        string getCharlesNumber();
        string getName();
        bool operator<(Employee &);
        void addPoint(string receivedMonth, string receivedDate, string receivedYear, int amount
            , string reason, string admin);
};

int getMonthIndex(string month);

#endif