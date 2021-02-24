#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class Date {
    private:
        string month;
        string day;
        string year;
        
    public:
        Date(string m, string d, string y);
        string getMonth();
        string getDay();
        string getYear();
};

bool isLeapYear(int year);
int daysInMonth(int month, int year);
string getCurrentMonth();
string getCurrentDay();
string getCurrentYear();
int daysBetweenThenAndNow(Date then);

#endif