#include "Date.h"

string getCurrentMonth() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return to_string(1 + ltm->tm_mon);
}

string getCurrentDay() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return to_string(ltm->tm_mday);
}

string getCurrentYear() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return to_string(1900 + ltm->tm_year);
}

bool isLeapYear(int year) {
    if (year % 4 != 0) 
        return false;
    else if (year % 100 != 0) 
        return true;
    else if (year % 400 != 0)  
        return false;
    else 
        return true;
}    

int daysInMonth(int month, int year) {
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year)) 
        days[1] = 29;
    return days[month-1];    
}

int daysBetweenThenAndNow(Date then) {
    int currentMonth = atoi(getCurrentMonth().c_str());
    int currentDay = atoi(getCurrentDay().c_str());
    int currentYear = atoi(getCurrentYear().c_str());
    int thenMonth = atoi(then.getMonth().c_str());
    int thenDay = atoi(then.getDay().c_str());
    int thenYear = atoi(then.getYear().c_str());

    if (currentYear == thenYear) {
        if (currentMonth == thenMonth) {
            if (currentDay == thenDay) {
                //nothing happens
            }
            else {
                if (currentDay < thenDay) {
                    return -1;
                }
            }
        }
        else {
            if (currentMonth < thenMonth) {
                return -1;
            }
        }
    }
    else {
        if (currentYear < thenYear) {
            return -1;
        }
    }

    int answer = 0;

    while (currentMonth != thenMonth || currentDay != thenDay || currentYear != thenYear) {
        if (currentMonth > 0) {
            if (currentDay > 0) {
                --currentDay;
                ++answer;
            }
            else {
                --currentMonth;
                if (currentMonth == 0) {
                    currentDay = daysInMonth(12, currentYear - 1);    
                }
                else {
                    currentDay = daysInMonth(currentMonth, currentYear);
                }
            }
        }
        else {
            --currentYear;
            currentMonth = 12;  
        }
    }
    return answer;
}

Date::Date(string m, string d, string y) {
    month = m;
    day = d;
    year = y;
}

string Date::getMonth() {
    return month;
}
string Date::getDay() {
    return day;
}
string Date::getYear() {
    return year;
}