#include "Roster.h"




void Roster::parse(string studentdata) {

	//repeat cuts to access each value by commas
	int firstComma = studentdata.find(",");
	string studentID = studentdata.substr(0, firstComma);

	int lastComma = firstComma + 1;
	firstComma = studentdata.find(",", lastComma);
	string firstName = studentdata.substr(lastComma, firstComma - lastComma);
	

    lastComma = firstComma + 1;
	firstComma = studentdata.find(",", lastComma);
	string lastName = studentdata.substr(lastComma, firstComma - lastComma);

	 lastComma = firstComma + 1;
	firstComma = studentdata.find(",", lastComma);
	string emailAddress = studentdata.substr(lastComma, firstComma - lastComma);

	lastComma = firstComma + 1;
	firstComma = studentdata.find(",", lastComma);
	int age = stoi(studentdata.substr(lastComma, firstComma - lastComma));

	//using the funstion stoi to convert string to int
	 lastComma = firstComma + 1;
	firstComma = studentdata.find(",", lastComma);
	int daysInCourse1 = stoi(studentdata.substr(lastComma, firstComma - lastComma));

	 lastComma = firstComma + 1;
	firstComma = studentdata.find(",", lastComma);
	int daysInCourse2 = stoi(studentdata.substr(lastComma, firstComma - lastComma));

	 lastComma = firstComma + 1;
	firstComma = studentdata.find(",", lastComma);
	int daysInCourse3 = stoi(studentdata.substr(lastComma, firstComma - lastComma));

	 
	DegreeProgram dp = UNDECIDED;
	if (studentdata.back() == 'Y') { dp = SECURITY; }
	else if (studentdata.back() == 'K') { dp = NETWORK; }
	else { dp = SOFTWARE; }



	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, dp);


}

//3. Define the following functions:

/*E) 3a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) 
that sets the instance variables from part D1 and updates the roster.*/

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

	//create array for our object
	int courses[3] = { daysInCourse1, daysInCourse2, daysInCourse3};

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, courses, degreeprogram);

}

/*E) 3b.  public void remove(string studentID)  that removes students from the roster by student ID.
If the student ID does not exist, the function prints an error message indicating that the student was not found.*/

void Roster::remove(string studentID) {

	bool removed = false;

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getID() == studentID) {
			removed = true;
			if (i < numStudents - 1) {

				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (removed == false) {
		cout << "Error! Student does not exist." << endl;
	}
	else {
		cout << "Removing student with ID " << studentID << endl;
		cout << "Student " << studentID << " was removed." << endl;
	}
}


/* E) 3c. public void printAll()
that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. 
The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.*/

void Roster::printAll(){

	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		cout << classRosterArray[i]->getID() << '\t';
		cout << classRosterArray[i]->getFirstName() << '\t';
		cout << classRosterArray[i]->getLastName() << '\t';
		cout << classRosterArray[i]->getEmail() << '\t';
		cout << classRosterArray[i]->getAge() << '\t';
		cout << classRosterArray[i]->getCourseDays()[0] << '\t';
		cout << classRosterArray[i]->getCourseDays()[1] << '\t';
		cout << classRosterArray[i]->getCourseDays()[2] << '\t';
		cout << degreeType[classRosterArray[i]->getDegree()] << endl; 
	}
}


 /* E) 3.d public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.*/

 void Roster::printAverageDaysInCourse(string studentID) {

	 for (int i = 0; i <= Roster::lastIndex; i++) {
		 if (classRosterArray[i]->getID() == studentID) {
			 cout << (classRosterArray[i]->getCourseDays()[0] + classRosterArray[i]->getCourseDays()[1] + classRosterArray[i]->getCourseDays()[2]) / 3 << endl;

		 }
		 cout << std::endl;
	 }
 }

 /* E) 3e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
 Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').*/



 void Roster::printInvalidEmails() {

	 bool valid = false;

	 for (int i = 0; i <= Roster::lastIndex; i++) {

		 string email = (classRosterArray[i]->getEmail());

		 size_t item = email.find("@");

		 if (item != string::npos){
			 item = email.find(".");
			 if (item != string::npos) {
				 item = email.find(" ");
				 if (item == string::npos) {
					 valid = true;
				 }
			 }
		 }

		    if (valid == false) {
			 cout << email  << " is an invalid email." << std::endl;
		 }

		 cout << endl;
	 }


 }


 /* E) 3f. public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.*/

 void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {

	 Student::printHeader();
	 for (int i = 0; i <= Roster::lastIndex; i++) {
		 if (Roster::classRosterArray[i]->getDegree() == degreeprogram) {
			 classRosterArray[i]->print();
		 }
		 cout << endl;
	 }
 }

 //F) 5.  Implement the destructor to release the memory that was allocated dynamically in Roster.

 Roster::~Roster() {

	 cout << "DESTRUCTOR CALLED!" << endl;
	 for (int i = 0; i < numStudents; i++) {
		 cout << "deleting student file #" << i + 1 << endl;
		 delete classRosterArray[i];
		 classRosterArray[i] = nullptr;
	 }
 }

