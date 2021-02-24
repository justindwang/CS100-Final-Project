#ifndef __VISITOR_H__
#define __VISITOR_H__

#include <iostream>
#include "Date.h"
#include "Employee.h"
#include <vector>
#include <map>
#include <ctime>

using namespace std;

class Employee;

class PrintVisitor {
    public:
        PrintVisitor() {};
        void visit(Employee*);
};

#endif

