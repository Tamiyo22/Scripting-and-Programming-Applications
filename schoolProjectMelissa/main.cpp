
#include <iostream>
#include "Roster.h" 



using namespace std; 



int main()
{
    //F) 1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    cout << "Course Title: Scripting and Programming Applications C867" << endl;
    cout << "programming Language: c++ " << endl;
    cout << "Student ID: #001230193 " << endl;
    cout << "Name: Melissa Aybar " << endl;
    cout << endl;


    //A) Modify the “studentData Table” to include your personal information as the last item.
    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE","A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Melissa,Aybar,maybar@wgu.edu,100,7,14,21,SOFTWARE" };

    //I would recommend vectors in the future for the potentional growth of classes and students
    const int numStudents = 5;
    

    //2.  Create an instance of the Roster class called classRoster.
    Roster classRoster;
    Student classStudent;
  
    

    //3.  Add each student to classRoster.

        for(int i = 0; i < numStudents; i++) {
            classRoster.parse(studentData[i]);
            cout << endl;
        }

        // classRoster.printAll();
        cout << "All Current students" << endl;
        classRoster.printAll();
        cout << endl;


        //Print by degree program
        cout << "Viewing all students in the software degree program" << endl;
        classRoster.printByDegreeProgram((SOFTWARE));
        cout << endl;

        

        //classRoster.printInvalidEmails();
        cout << " All Invalid Emails" << endl;
        classRoster.printInvalidEmails();
        cout << endl;


        //loop through classRosterArray and for each element:
          //classRoster.printAverageDaysInCourse(/*current_object's student id*/);

        for (int i = 0; i <= classRoster.lastIndex; i++) {
            string studentIds = classRoster.classRosterArray[i]->getID();
            cout << "Printing out the averge days in a course for student ID " << studentIds << endl;
            classRoster.printAverageDaysInCourse(studentIds);
            cout << endl;
        } 

        cout << endl;

        //classRoster.remove("A3");
        cout << "Remove student " << endl;
        classRoster.remove("A3");
        cout << endl;

        //classRoster.printAll();
        cout << "All Current students" << endl;
        classRoster.printAll();
        cout << endl;

        //classRoster.remove("A3");
        cout << "Try to remove the student by id again" << endl;
        classRoster.remove("A3");
        cout << endl;


        //hold the window open
     system("pause");
    return 0;
}


