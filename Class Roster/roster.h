#pragma once
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

class Roster
{
public:	// variables
	// create classRosterArray as an array of pointers to hold data provided in table.
	const static int students = 5;
	Student* classRosterArray[students];
private:	//	Private variables for Roster class.
	// variables to know which student object we're on as we parse the data table.
	int numStudents = 0;	//	integer for classRosterArray index for add function.
	int maxStudents = 0;	//	Increment max student count after parsing.  Decrement after removal.
public:	// functions
	//	Not defining a constructor.
	//	Define a deconstructor.
	~Roster();
	//	parse function to parse studentData.
	void parse(string data, int student);
	//	add() to set instance variables as defined from our Student class and updates the roster.
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	//	should remove the student from the roster based on studentID, if studentID does not exist should print error message stating that the student was not found.
	void remove(string studentID);
	//	Print a tab-separated list of student data.  printAll() should loop through all students and call the print() function to print the data to console.
	void printAll();
	//	Print the average days in course for StudentID
	void printAverageDaysInCourse(string studentID);
	//	printInvalidEmails() to print to console a list of all invalid email address in student data:
	void printInvalidEmails();
	//	Prints all students that match enumerated degreeProgram.  
	void printByDegreeProgram(DegreeProgram degreeProgram);
};