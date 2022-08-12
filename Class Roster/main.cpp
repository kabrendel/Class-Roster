// C867 Class Roster.cpp

#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
using namespace std;

// data table input from assignment
const string studentData[] =
{
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Kris,Brendel,kbrend1@wgu.edu,41,5,6,9,SOFTWARE"
};

int main()
{
    //  Print information for assignment:
    cout << "Scripting and Programming - Applications - C867" << '\n';
    cout << "Application written in C++ in Microsoft Visual Studio Community 2022" << '\n';
    cout << "WGU Student ID:" << '\t' << "#005672762." << '\n';
    cout << "Name:" << '\t' << "Kristopher Brendel" << '\n' << '\n';
    //  create Roster object.
    Roster classRoster;
    //  Parse studentData and add to roster.
    for (int i = 0; i < 5; i++)
    {
        classRoster.parse(studentData[i],i);
    }
    //  Print entire roster of students.
    cout << "Student roster:" << '\n';
    classRoster.printAll();
    //  print invalid emails from student data.
    cout << '\n' << "Invalid emails found in student data:" << '\n';
    classRoster.printInvalidEmails();
    //  Print average days in 3 courses for all students in roster.
    cout << '\n' << "Average days in 3 courses for students in roster:" << '\n';
    for (int i = 0; i < 5; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getid());
    }
    //  Print all students getting a degree in Software.
    cout << '\n' << "All students enrolled in a Software degree:" << '\n';
    classRoster.printByDegreeProgram(SOFTWARE);
    //  Remove student with ID A3.
    cout << '\n' << "Removing a student from our data:" << '\n';
    classRoster.remove("A3");
    //  Print entire roster of students.
    cout << '\n' << "Student roster:" << '\n';
    classRoster.printAll();
    //  Remove student with ID A3.
    cout << '\n' << "Removing a student from our data:" << '\n';
    classRoster.remove("A3");
}