#include "Employee.h"

void Point::printPoint() {
    cout << receivedMonth << " " << receivedDate << ", "
        << receivedYear << " - " << amount << " Points - "
        << reason << " - Given by: " << admin << endl;
}

Employee::Employee(string fname, string lname, string cNumber) {
    firstname = fname;
    lastname = lname;
    charlesNumber = cNumber;
}

const void Employee::printEmployee() {
    cout << firstname << " " << lastname << " " << charlesNumber << " - "
        << getTotalPoints() << " points total in last 75 days." << endl;
}

// make it so it only counts last 75 days
// algorithm - diff from today and given date
// if diff <= 75 -> add to sum

int Employee::getTotalPoints() {
    int sum = 0;
    string m;
    string d;
    string y;
    int difference;
    for (unsigned i = 0; i < points.size(); ++i) {
        m = to_string(getMonthIndex(points.at(i).receivedMonth));
        d = points.at(i).receivedDate;
        y = points.at(i).receivedYear;
        Date receiveDay(m, d, y);
        difference = daysBetweenThenAndNow(receiveDay);
        if (difference <= 75) {
            sum += points.at(i).amount;
        }
    }
    return sum;
}

bool Employee::operator<(Employee & compareTo) {
    return this->getTotalPoints() > compareTo.getTotalPoints();
}

string Employee::getCharlesNumber() {
    return charlesNumber;
}

void Employee::addPoint(string receivedMonth, string receivedDate, string receivedYear, int amount
    , string reason, string admin) {
        points.push_back({receivedMonth, receivedDate, receivedYear, amount, reason, admin});
}

string Employee::getName() {
    return firstname + " " + lastname;
}

const void Employee::printAllPoints() {
    for (unsigned i = 0; i < points.size(); ++i) {
        points.at(i).printPoint();
    }
}

bool Point::operator<(Point & rhs) {
    if (this->receivedYear == rhs.receivedYear) {
        if (this->getMonthIndex(receivedMonth) == rhs.getMonthIndex(receivedMonth)) {
            if (this->receivedDate == rhs.receivedDate) {
                return this->amount > rhs.amount;
            }
            else
                return this->receivedDate > rhs.receivedDate;
        }
        else
            return this->getMonthIndex(receivedMonth) > rhs.getMonthIndex(receivedMonth);
    }
    else
        return this->receivedYear > rhs.receivedYear;
}

int getMonthIndex(string month) {
    map<string, int> months
    {
        { "January", 1 },
        { "February", 2 },
        { "March", 3 },
        { "April", 4 },
        { "May", 5 },
        { "June", 6 },
        { "July", 7 },
        { "August", 8 },
        { "September", 9 },
        { "October", 10 },
        { "November", 11 },
        { "December", 12 }
    };
    const auto iter = months.find(month);

    if(iter != months.cend())
        return iter->second;
    return -1;
}

int Point::getMonthIndex(string month) {
    map<string, int> months
    {
        { "January", 1 },
        { "February", 2 },
        { "March", 3 },
        { "April", 4 },
        { "May", 5 },
        { "June", 6 },
        { "July", 7 },
        { "August", 8 },
        { "September", 9 },
        { "October", 10 },
        { "November", 11 },
        { "December", 12 }
    };
    const auto iter = months.find(month);

    if(iter != months.cend())
        return iter->second;
    return -1;
}