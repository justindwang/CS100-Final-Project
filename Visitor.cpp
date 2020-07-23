#include "Visitor.h"
#include "Employee.h"

//Part of the visitor design pattern
void PrintVisitor::visit(Employee* em){
            cout << em->getName() << " " << em->getCharlesNumber() << " - "
            << em->getTotalPoints() << " points total in last 75 days." << endl;
}
