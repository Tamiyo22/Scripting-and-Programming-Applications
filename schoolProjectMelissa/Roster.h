#pragma once
#include "Student.h"



/*E. Create a Roster class (roster.cpp) by doing the following:

 1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
 2.  Create a student object for each student in the data table and populate classRosterArray.
  a.Parse each set of data identified in the “studentData Table.”
  b.Add each student object to classRosterArray. */

class Roster
{

public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string person);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};

