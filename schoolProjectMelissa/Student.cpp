#include "Student.h"

/*2.  Create each of the following functions in the Student class :
	a.an accessor(i.e., getter) for each instance variable from part D1
	b.a mutator(i.e., setter) for each instance variable from part D1
	c.All external accessand changes to any instance variables of the Student class must be done using accessorand mutator functions.
	d.constructor using all of the input parameters provided in the table
	e.print() to print specific student data */


Student::Student() {

	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < 3; i++) {
		this->daysInCourses[i] = 0;
	};
	this->degreeprogram = DegreeProgram::UNDECIDED;

}



//methods
//constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourses[], DegreeProgram degreeprogram){

	this ->studentID = studentID;
	this ->firstName = firstName;
	this ->lastName = lastName;
	this ->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; ++i) {
		this->daysInCourses[i] = daysInCourses[i];
	}
	this->degreeprogram = degreeprogram;
}

//destructor
Student::~Student() {};

//getters
string Student::getID() {
	return this->studentID;
}
string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
string Student::getEmail() {
	return this -> emailAddress;
}
int Student::getAge() {
	return this -> age;
}
int* Student::getCourseDays() {
	return this->daysInCourses;
}
DegreeProgram Student::getDegree() {
	return this->degreeprogram;
}


//setters
void Student::setID(string id){ this->studentID = id; }
void Student::setFirstName(string firstname){ this->firstName = firstName; }
void Student::setLastName(string lastname){ this->lastName = lastName; }
void Student::setEmail(string email){  this->emailAddress; }
void Student::setAge(int age){ this->age = age; }
void Student::setCourseDays(int daysInCourses[]) {
	for (int i = 0; i < 3; ++i) {
		this->daysInCourses[i] = daysInCourses[i];
	}
}
void Student::setDegree(DegreeProgram degreeprogram){ this->degreeprogram = degreeprogram; }

void Student::printHeader() {

	cout << "    ID |   First Name |  Last Name |  E-Mail  |  Age |  Course Days Left |   Degree " << endl;
}

void Student::print(){

	cout << this->getID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge()  << '\t';
	cout << this->getCourseDays()[0] << ',';
	cout << this->getCourseDays()[1] << ',';
	cout << this->getCourseDays()[2] << '\t';
	cout << degreeType[this->getDegree()] << '\t';





}


