#pragma once
#include <iostream>
#include "Degree.h"

using namespace std;

/*D.For the Student class, do the following :
1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables :
•  student ID
•  first name
•   last name
•  email address
•  age
•  array of number of days to complete each course
•  degree program */

class Student {

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourses[3]; //hard coded 3 into here, since we know that there are only 3 classes per student. I would however recommend a constant int or vector in the future for growth 
	DegreeProgram degreeprogram;

	
public:
	Student(); //constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourses[], DegreeProgram degreeprogram); //full constructor
	~Student(); //destructor

	//getters
	string getID();
	string getFirstName();
	string getLastName(); 
	string getEmail();
	int getAge();
	int* getCourseDays();
	DegreeProgram getDegree();

	//setters
    void setID(string studentID);
	void setFirstName(string firstname);
	void setLastName(string lastname);
	void setEmail(string emailAddress);
	void setAge(int age);
	void setCourseDays(int daysInCourses[]);
	void setDegree(DegreeProgram degreeprogram);

	static void printHeader();

	void print();



};

