#pragma once
#include "degree.h"

class Student
{
public: 
    const static int courseCompletionArraySize = 3;

private: 

    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int courseCompletionDays[courseCompletionArraySize]; // Always 3 
    DegreeProgram degreeProgram;

public:

    Student(); // Constructor
    
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[], DegreeProgram degreeProgram); 
    
    ~Student();
    
    string getStudentID() const; 
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    int* getCourseCompletionDays();
    DegreeProgram getDegreeProgram() const;

    
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setCourseCompletionDays(int courseCompletionDays[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    
    void print();
};