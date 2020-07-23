#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include "Date.h"
#include "Visitor.h"
#include <vector>
#include <map>
#include <ctime>

using namespace std;

class PrintVisitor;

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
    protected:
        string firstname;
        string lastname;
        string charlesNumber;
    public:
        vector<Point> points;
	Employee();
        Employee(string fname, string lname, string cNumber);
        const void printAllPoints();
        int getTotalPoints();
        string getCharlesNumber();
        string getName();
        bool operator<(Employee &);
        void addPoint(string receivedMonth, string receivedDate, string receivedYear, int amount
            , string admin);
	
	string getFirstName();
	string getLastName();
	void accept(PrintVisitor* pv);
};

int getMonthIndex(string month);

#endif
