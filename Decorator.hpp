#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include <iostream>
#include "Date.h"
#include "Employee.h"
#include <vector>
#include <map>
#include <ctime>

using namespace std;

class Decorator : public Employee{
    public:
	Decorator(){};
	virtual string displayGoodEmployeeMsg() = 0;
};

class GoodEmployee : public Decorator{
    private:
        string firstname;
        string lastname;
        string charlesNumber;
    public:
        GoodEmployee() {};

	GoodEmployee(Employee& e){
	    firstname = e.getFirstName();
	    lastname = e.getLastName();
	    charlesNumber = e.getCharlesNumber();
	}
	string displayGoodEmployeeMsg() {
	    return firstname + " " + lastname + " is an outstanding employee!\n";
	}
       
};

#endif
