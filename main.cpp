#include <iostream>
#include <vector>
#include "Employee.h"
#include "Date.h"
#include <thread>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 

using namespace std;

vector<Employee> initilizeProgram() {
    ifstream fin;
    fin.open("./Data_Files/Employees.dat");
    if (!fin) {
        cout << "Unable to open data file. Please check that data file is in correct location" << endl;
        cout << "Terminating program in 5 seconds..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        exit(1);
    }
    vector<Employee> Employees;

    int count = 0;

    string line;
    string word;
    string fname;
    string lname;
    string cnumber;
    string month;
    string date;
    string year;
    int amount;
    string reason;
    string supervisor;
    while (getline(fin, line)) {
        istringstream iss(line);
        iss >> word;
        if (word == "Employee") {
            iss >> fname >> lname >> cnumber;
            Employee toAdd(fname, lname, cnumber);
            Employees.push_back(toAdd);
            ++count;
        }
        if (word == "POINT") {
            iss >> month >> date >> year >> amount;
            getline(fin, reason);
            getline(fin, supervisor);
            Employees.at(count - 1).addPoint(month, date, year, amount, reason, supervisor);
        }
    }
    fin.close();
    return Employees;
}

void addEmployee(vector<Employee>& Employees) {
    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;

    cout << "Adding a Employee (Type CANCEL to cancel at any time): " << endl;
    string firstName;
    cout << "Enter Employee's First Name (ex. Bernie): ";
    cin >> firstName;
    if (firstName == "CANCEL") {
        cout << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl;
        return;
    }
    string lastName;
    cout << "Enter Employee's Last Name (ex. Shan): ";
    cin >> lastName;
    if (lastName == "CANCEL") {
        cout << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl;
        return;
    }
    string charlesNumber;
    cout << "Enter Employee's ID Number (ex. 001): ";
    cin >> charlesNumber;
    if (charlesNumber == "CANCEL") {
        cout << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl;
        return;
    }
    bool charlesNumberExists = false;
    for (unsigned i = 0; i < Employees.size(); ++i) {
        if (Employees.at(i).getCharlesNumber() == charlesNumber)
            charlesNumberExists = true;
    }

    if (charlesNumberExists) {
        cout << "Error adding " << firstName << " " << lastName << " - A Employee already exists as " << charlesNumber << endl;
    }
    else {
        cout << endl << "Adding Employee to database... Please wait..." << endl;
        cout << "Success! Employee " << firstName << " " << lastName << " " << charlesNumber <<
            " added to the database!" << endl << endl;
    
        Employee toAdd(firstName, lastName, charlesNumber);

        Employees.push_back(toAdd);
    }

    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

void removeEmployee(vector<Employee>& Employees) {
    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;

    cout << "Removing a Employee: " << endl;
    string charlesNumber;
    string choice;
    bool flag = true;
    bool flag2 = true;
    while (flag2) {
        cout << "Enter Employee's ID Number (ex. 001) (Type CANCEL to cancel): ";
        cin >> charlesNumber;
        if (charlesNumber == "CANCEL") {
            cout << "No changes have been made. Returning back to the Main Menu." << endl; 
            cout << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << endl;
            return;
        }
        //search for Employee in database
        for (unsigned i = 0; i < Employees.size(); ++i) {
            if (Employees.at(i).getCharlesNumber() == charlesNumber) {
                while (flag) {
                    cout << "Are you sure you want to delete " << Employees.at(i).getName() << " " << Employees.at(i).getCharlesNumber() << "?" << endl;
                    cout << "NOTE: This will delete ALL related information about this Employee. This action is NOT reversible!" << endl;
                    cout << "Do you wish to continue? (Yes/No): ";
                    cin >> choice;
                    if (choice == "Yes") {
                        flag = false;
                        flag2 = false;
                        cout << "Removing Employee from database... Please wait..." << endl;
                        cout << "Success! Employee has been removed from the database!" << endl;
                        Employees.erase(Employees.begin() + i);
                    }
                    else if (choice == "No") {
                        flag = false;
                        flag2 = false;
                        cout << "No changes have been made. Returning back to the Main Menu." << endl;
                    }
                    else {
                        cout << "Invalid selection. Please type Yes or No." << endl;
                    }
                }
            }
        }
        if (flag2) {
            cout << "No Employee matching " << charlesNumber << " found. Please try again." << endl;
        }
    }
    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

void addPoints(vector<Employee>& Employees) {
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
    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
    
    cout << "Add Points to a Employee (Type CANCEL to cancel at any time): " << endl;
    bool flag = true;
    string charlesNumber;
    string month;
    string date;
    string year;
    string supervisor;

    while (flag) {
        cout << "Enter Employee's ID Number (ex. 001): ";
        cin >> charlesNumber;
        if (charlesNumber == "CANCEL") {
            cout << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << endl;
            return;
        }
        for (unsigned i = 0; i < Employees.size(); ++i) {
            if (Employees.at(i).getCharlesNumber() == charlesNumber) {
                bool monthFlag = true;
                while (monthFlag) {
                    cout << "Enter today's month (ex. April): ";
                    cin >> month;
                    if (month == "CANCEL") {
                        cout << endl;
                        cout << "---------------------------------------------------------" << endl;
                        cout << endl;
                        return;
                    }
                    vector<string> months{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
                    for (unsigned i = 0; i < months.size(); ++i) {
                        if (months.at(i) == month) {
                            monthFlag = false;
                            break;
                        }
                    }
                    if (monthFlag) {
                        cout << "Invalid month entered. Please try again." << endl;
                    }
                }
                cout << "Enter today's date (ex. 27): ";
                cin >> date;
                if (date == "CANCEL") {
                    cout << endl;
                    cout << "---------------------------------------------------------" << endl;
                    cout << endl;
                    return;
                }
                cout << "Enter today's year (ex. 2020): ";
                cin >> year;
                if (year == "CANCEL") {
                    cout << endl;
                    cout << "---------------------------------------------------------" << endl;
                    cout << endl;
                    return;
                }
                cout << "Enter Supervisor's Name (ex. Hokari): ";
                cin.ignore();
                getline(cin, supervisor);
                if (supervisor == "CANCEL") {
                    cout << endl;
                    cout << "---------------------------------------------------------" << endl;
                    cout << endl;
                    return;
                }
                cout << endl;
                
                bool flag2 = true;
                char choice;
                while (flag2) {
                    cout << "Please choose a reason for giving points: " << endl;
                    cout << "1 - L (Late up to 15 minutes)" << endl;
                    cout << "2 - LL (Late 15+ minutes)" << endl;
                    cout << "3 - C (Called Out Following Proper Procedure)" << endl;
                    cout << "4 - M (Missed Training/Meeting/Appointment)" << endl;
                    cout << "5 - IP (Called Out Improper Procedure)" << endl;
                    cout << "6 - N (No Call/No Show)" << endl;
                    cout << "7 - CL (Continued Illness)" << endl;
                    cout << "Enter selection: ";
                    cin >> choice;

                    switch(choice) {
                        case '1':
                            Employees.at(i).addPoint(month, date, year, 1, "L (Late up to 15 minutes)", supervisor);
                            flag = false;
                            flag2 = false;
                            cout << endl;
                            cout << "---------------------------------------------------------" << endl;
                            cout << endl;
                            cout << "1 Point added to " << Employees.at(i).getName() << endl;
                            cout << Employees.at(i).getName() << " has a total of " << Employees.at(i).getTotalPoints() 
                                << " points (ONLY INCLUDES POINTS FROM LAST 75 DAYS)." << endl;
                            break;
                        case '2':
                            Employees.at(i).addPoint(month, date, year, 2, "LL (Late 15+ minutes)", supervisor);
                            flag = false;
                            flag2 = false;
                            cout << endl;
                            cout << "---------------------------------------------------------" << endl;
                            cout << endl;
                            cout << "2 Points added to " << Employees.at(i).getName() << endl;
                            cout << Employees.at(i).getName() << " has a total of " << Employees.at(i).getTotalPoints() 
                                << " points (ONLY INCLUDES POINTS FROM LAST 75 DAYS)." << endl;
                            break;
                        case '3':
                            Employees.at(i).addPoint(month, date, year, 3, "C (Called Out Following Proper Procedure)", supervisor);
                            flag = false;
                            flag2 = false;
                            cout << endl;
                            cout << "---------------------------------------------------------" << endl;
                            cout << endl;
                            cout << "3 Points added to " << Employees.at(i).getName() << endl;
                            cout << Employees.at(i).getName() << " has a total of " << Employees.at(i).getTotalPoints() 
                                << " points (ONLY INCLUDES POINTS FROM LAST 75 DAYS)." << endl;
                            break;
                        case '4':
                            Employees.at(i).addPoint(month, date, year, 3, "M (Missed Training/Meeting/Appointment)", supervisor);
                            flag = false;
                            flag2 = false;
                            cout << endl;
                            cout << "---------------------------------------------------------" << endl;
                            cout << endl;
                            cout << "3 Points added to " << Employees.at(i).getName() << endl;
                            cout << Employees.at(i).getName() << " has a total of " << Employees.at(i).getTotalPoints() 
                                << " points (ONLY INCLUDES POINTS FROM LAST 75 DAYS)." << endl;
                            break;
                        case '5':
                            Employees.at(i).addPoint(month, date, year, 4, "IP (Called Out Improper Procedure)", supervisor);
                            flag = false;
                            flag2 = false;
                            cout << endl;
                            cout << "---------------------------------------------------------" << endl;
                            cout << endl;
                            cout << "4 Points added to " << Employees.at(i).getName() << endl;
                            cout << Employees.at(i).getName() << " has a total of " << Employees.at(i).getTotalPoints() 
                                << " points (ONLY INCLUDES POINTS FROM LAST 75 DAYS)." << endl;
                            break;
                        case '6':
                            Employees.at(i).addPoint(month, date, year, 6, "N (No Call/No Show)", supervisor);
                            flag = false;
                            flag2 = false;
                            cout << endl;
                            cout << "---------------------------------------------------------" << endl;
                            cout << endl;
                            cout << "6 Points added to " << Employees.at(i).getName() << endl;
                            cout << Employees.at(i).getName() << " has a total of " << Employees.at(i).getTotalPoints() 
                                << " points (ONLY INCLUDES POINTS FROM LAST 75 DAYS)." << endl;
                            break;
                        case '7':
                            Employees.at(i).addPoint(month, date, year, 0, "CL (Continued Illness)", supervisor);
                            flag = false;
                            flag2 = false;
                            cout << endl;
                            cout << "---------------------------------------------------------" << endl;
                            cout << endl;
                            cout << "0 Points added to " << Employees.at(i).getName() << endl;
                            cout << Employees.at(i).getName() << " has a total of " << Employees.at(i).getTotalPoints() 
                                << " points (ONLY INCLUDES POINTS FROM LAST 75 DAYS)." << endl;
                            break;
                        default:
                            cout << endl << "Invalid Choice - Please enter a number from 1-7" << endl << endl;
                            break;
                    }
                }
            }
        }
        if (flag)
            cout << "No Employee matching " << charlesNumber << " found. Please try again." << endl;
    }

    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

void removePoints(vector<Employee>& Employees) {
    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
    
    cout << "Remove points from a Employee (Type CANCEL to cancel at any time): " << endl;
    string charlesNumber;
    bool flag = true;
    bool flag2 = true;
    int counter = 1;
    int choice;
    while (flag) {
        cout << "Enter Employee's ID Number (ex. 001): ";
        cin >> charlesNumber;
        cout << endl;
        if (charlesNumber == "CANCEL") {
            cout << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << endl;
            return;
        }
        for (int i = 0; i < Employees.size(); ++i) {
            if (Employees.at(i).getCharlesNumber() == charlesNumber) {
                cout << "Here are all the points for " << Employees.at(i).getCharlesNumber() << " " << Employees.at(i).getName() 
                    << " sorted from newest to oldest: " << endl;
                for (int j = 0; j < Employees.at(i).points.size(); ++j) {
                    cout << counter << " - ";
                    Employees.at(i).points.at(j).printPoint();
                    ++counter;
                }
                while (flag2) {
                    cout << "Pick a point to remove. Type 0 to Cancel: ";
                    cin >> choice;
                    if (choice == 0) {
                        cout << "No changes have been made. Returning back to the Main Menu." << endl; 
                        cout << endl;
                        cout << "---------------------------------------------------------" << endl;
                        cout << endl;
                        return;
                    }
                    if (choice < counter) {
                        cout << "Removing point from the records... Please wait..." << endl;
                        cout << "Points successfully removed!" << endl;
                        Employees.at(i).points.erase(Employees.at(i).points.begin() + (choice - 1));
                        cout << endl;
                        cout << "---------------------------------------------------------" << endl;
                        cout << endl;
                        return;
                    }
                }
            }
        }
        if (flag) {
            cout << "No Employee matching " << charlesNumber << " found. Please try again." << endl;
        }
    }
}

const void outputEmployees(vector<Employee>& Employees) {
    if (Employees.empty()) {
        cout << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl;
        cout << "There are currently no Employees in the database!" << endl;
        cout << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl;
        return;
    }
    sort(Employees.begin(), Employees.end());
    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
    cout << "List of all Employees sorted by points (ONLY INCLUDES POINTS RECEIVED IN LAST 75 DAYS): " << endl;
    for (unsigned i = 0; i < Employees.size(); ++i) {
        Employees.at(i).printEmployee();
    }
    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

const void outputEmployee(vector<Employee>& Employees) {
    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;

    if (Employees.empty()) {
        cout << "There are currently no Employees in the database!" << endl;
        cout << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl;
        return;
    }
    cout << "View Employee detailed point information (Type CANCEL to cancel at any time): " << endl;
    string charlesNumber;
    bool flag;
    while (flag) {
        cout << "Enter Employee's ID Number: ";
        cin >> charlesNumber;
        cout << endl;
        if (charlesNumber == "CANCEL") {
            cout << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << endl;
            return;
        }
        for (unsigned i = 0; i < Employees.size(); ++i) {
            if (Employees.at(i).getCharlesNumber() == charlesNumber) {
                sort(Employees.at(i).points.begin(), Employees.at(i).points.end());
                cout << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << endl;
                Employees.at(i).printEmployee();
                cout << endl << "Points History (Includes All Points)" << endl;
                if (Employees.at(i).points.empty()) {
                    cout << endl << "Employee has NO points in the system!" << endl;
                }
                else {
                    Employees.at(i).printAllPoints();   
                }
                flag = false;
            }
        }
        if (flag) {
            cout << "No Employee matching " << charlesNumber << " found. Please try again." << endl << endl;
        }
    }

    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

const void saveProgram(vector<Employee>& Employees) {
    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
    ofstream fout;
    fout.open("./Data_Files/Employees.dat");
    if (!fout) {
        cout << "Unable to open data file. Please check that data file is in correct location" << endl;
        cout << "Terminating program in 5 seconds..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        exit(1);
    }

    for (unsigned i = 0; i < Employees.size(); ++i) {
        fout << "Employee " << Employees.at(i).getName() << " " 
            << Employees.at(i).getCharlesNumber() << endl;
        for (unsigned j = 0; j < Employees.at(i).points.size(); ++j) {
            fout << "POINT " << Employees.at(i).points.at(j).receivedMonth <<
            " " << Employees.at(i).points.at(j).receivedDate << " " <<
            Employees.at(i).points.at(j).receivedYear << " " << Employees.at(i).points.at(j).amount << endl;
            fout << Employees.at(i).points.at(j).reason << endl;
            fout << Employees.at(i).points.at(j).admin << endl;
        }
    }

    cout << "Successfully saved program to data file." << endl;

    cout << "Press ENTER to close program" << endl;
    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

int main() {
    cout << "Welcome to the Attendance Manager v.0.0.1" << endl;
    cout << endl;
    cout << "Initializing database... Please wait..." << endl << endl;
    this_thread::sleep_for(chrono::seconds(2));
    vector<Employee> Employees = initilizeProgram();

    bool flag = true;
    char choice;
    while (flag) {
        cout << "Please choose from the following options: " << endl;
        cout << "1 - Add Employee to database" << endl;
        cout << "2 - Remove Employee from database" << endl;
        cout << "3 - Add points for a Employee" << endl;
        cout << "4 - Remove points for a Employee" << endl;
        cout << "5 - View Employee detailed point information" << endl;
        cout << "6 - Output ALL Employees by total points" << endl;
        cout << "7 - Save changes and exit program" << endl << endl;
        cout << "Enter choice: ";

        cin >> choice;
        cin.ignore();

        switch(choice) {
            case '1':
                addEmployee(Employees);
                break;
            case '2':
                removeEmployee(Employees);
                break;
            case '3':
                addPoints(Employees);
                break;
            case '4':
                removePoints(Employees);
                break;
            case '5':
                outputEmployee(Employees);
                break;
            case '6':
                outputEmployees(Employees);
                break;
            case '7':
                saveProgram(Employees);
                flag = false;
                break;
            default:
                cout << endl << "Invalid Choice - Please enter a number from 1-7" << endl << endl;
                break;
        }
    }

    return 0;
}