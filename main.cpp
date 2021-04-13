#include <iostream>
#include <iomanip>
#include "roster.h"
using std::cout;
using std::endl;
using std::left;
using std::setw;

int main() {

    const int studentCount = 5; 

    const string studentData[] = { 
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Hayden,Harrison,hhar121@wgu.edu,28,10,20,30,SOFTWARE"
    };

    // Personal Information 
    cout << left << "Scripting_and_Programming_Applications_C867" << endl;
    cout << left << "Language: C++ \n";
    cout << left << "Student ID: 001389367 \n";
    cout << left << "Name: Hayden Harrison \n";
    cout << endl << endl;
    cout << "Adding students to the roster" << endl << endl;

    Roster* classRoster = new Roster(studentCount); 

    for (int i = 0; i < studentCount; i++)
    { // Add students 
        classRoster->parseDataAndAdd(studentData[i]);

    }

    cout << "-Students Added-" << endl << endl;

    
    classRoster->printAll();
    classRoster->printInvalidEmails();
    
    for (int i = 0; i < classRoster->headCount; i++)
    {
        classRoster->printAverageDaysInCourse(classRoster->students[i]->getStudentID());
    }
    classRoster->printByDegreeProgram(SOFTWARE);
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");
    // Remove A3 and confirm 

    return 0;
}