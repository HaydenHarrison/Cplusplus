#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"

Roster::Roster() // Blank roster 
{
    this->headCount = 0; 
    this->lastStudent = -1; 
    this->students = nullptr; 
}
Roster::Roster(int headCount) 
{
    this->headCount = headCount;
    this->lastStudent = -1; 
    this->students = new Student * [headCount]; 
}
Roster::~Roster()
{ 
    for (int i = 0; i < headCount; i++)
    {
        delete this->students[i]; // Remove from memory 
    }
    delete this; // Remove empty roster 
}

void Roster::parseDataAndAdd(string rawData)
{ 
    std::vector<string> dataPoints; 
    std::stringstream inputSStream(rawData); 

    while (inputSStream.good())
    { 
        string data;
        getline(inputSStream, data, ',');
        dataPoints.push_back(data);
    }
    add(dataPoints.at(0), 
        dataPoints.at(1), 
        dataPoints.at(2), 
        dataPoints.at(3), 
        stoi(dataPoints.at(4)), 
        stoi(dataPoints.at(5)), 
        stoi(dataPoints.at(6)), 
        stoi(dataPoints.at(7)), 
        convert(dataPoints.at(8)) 
    );
}
DegreeProgram Roster::convert(string str)
{ 
    if (str == "SECURITY") return SECURITY;
    else if (str == "NETWORK") return NETWORK;
    else if (str == "SOFTWARE") return SOFTWARE;
    else return NONE;
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{ // Add new students
    if (lastStudent < headCount)
    { 
        lastStudent++; 
        this->students[lastStudent] = new Student();
        this->students[lastStudent]->setStudentID(studentID);
        this->students[lastStudent]->setFirstName(firstName);
        this->students[lastStudent]->setLastName(lastName);
        this->students[lastStudent]->setEmailAddress(emailAddress);
        this->students[lastStudent]->setAge(age);
        int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
        this->students[lastStudent]->setCourseCompletionDays(days);
        this->students[lastStudent]->setDegreeProgram(degreeProgram);
    }
    else 
    {
        std::cerr << std::endl << "Increase headcount please" << std::endl << std::endl;
    }
}
void Roster::printAll() // Print 
{
    std::cout << "Displaying all students below" << std::endl << std::endl;
    for (int i = 0; i <= this->lastStudent; i++)
    {

        (this->students)[i]->print();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Roster::remove(string studentID)
{ // Remove student

    bool found = false; // Check for ID 

    for (int i = 0; i <= lastStudent; i++)
    {
        if (this->students[i]->getStudentID() == studentID) 
        {
            found = true; 
            delete this->students[i];
            this->students[i] = this->students[lastStudent]; 
            lastStudent--; // Decriment roster 
            std::cout << "Successfully Removed student: " << studentID << std::endl << std::endl;
        }
    }
    if (!found)
    { 
        std::cerr << "Student: " << studentID << " NOT FOUND" << std::endl << std::endl;
    }

}
void Roster::printAverageDaysInCourse(string studentID)
{
    bool found = false; 

    for (int i = 0; i <= lastStudent; i++)
    {
        if (this->students[i]->getStudentID() == studentID) 
        {
            found = true;
            int* days = this->students[i]->getCourseCompletionDays(); 
            double averageDays = static_cast<double>(days[0] + days[1] + days[2]) / 3.0; 
            std::cout << "Average course completion days for student " << studentID << " is: "
                << averageDays << std::endl << std::endl;
        }
    }
    if (!found)
    {
        std::cerr << "Student: " << studentID << " NOT AVAILABLE" << std::endl << std::endl;
    }

}
void Roster::printInvalidEmails()
{
    std::cout << "Invalid Email Addresses:" << std::endl << std::endl;
    bool found = false; 

    for (int i = 0; i <= lastStudent; i++)
    { // Needs to have an at sign ('@') and period ('.') and should not include a space (' ').
        string email = this->students[i]->getEmailAddress();
        if (
            (email.find('.') == string::npos) || // No '.' 
            (email.find('@') == string::npos) || // No '@' 
            !(email.find(' ') == string::npos)  
            )
        { 
            found = true;
            this->students[i]->print();
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    if (!found)
    {
        std::cout << "No Invalid emails" << std::endl << std::endl;
    }
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    std::cout << "Displaying Students for " << degreeProgramStrings[degreeProgram] << " major" << std::endl << std::endl;
    for (int i = 0; i <= lastStudent; i++)
    {
        if (this->students[i]->getDegreeProgram() == degreeProgram)
        {
            this->students[i]->print();
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}