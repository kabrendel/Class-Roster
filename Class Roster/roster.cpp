#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"
using namespace std;

void Roster::parse(string data, int student)
{
	//	Sample student data:
	//	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY"
	char d = ',';									// our delimiter
	size_t rhs = data.find(d);
	string id = data.substr(0, rhs);				// student id
	
	size_t lhs = rhs + 1;
	rhs = data.find(d, lhs);
	string firstName = data.substr(lhs, rhs - lhs);	// first name

	lhs = rhs + 1;
	rhs = data.find(d, lhs);
	string lastName = data.substr(lhs, rhs - lhs);	// last name

	lhs = rhs + 1;
	rhs = data.find(d, lhs);
	string email = data.substr(lhs, rhs - lhs);		// email
	
	lhs = rhs + 1;
	rhs = data.find(d, lhs);
	int age = stoi(data.substr(lhs, rhs - lhs));	// age
	
	lhs = rhs + 1;
	rhs = data.find(d, lhs);
	int days1 = stoi(data.substr(lhs, rhs - lhs));	// days in class 1

	lhs = rhs + 1;
	rhs = data.find(d, lhs);
	int days2 = stoi(data.substr(lhs, rhs - lhs));	// days in class 2

	lhs = rhs + 1;
	rhs = data.find(d, lhs);
	int days3 = stoi(data.substr(lhs, rhs - lhs));	// days in class 3

	lhs = rhs + 1;
	rhs = data.find(d, lhs);
	string program = data.substr(lhs, rhs - lhs);	// degree program as a string
	DegreeProgram degreeProgram{};
	if (program == "SECURITY")
	{
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (program == "NETWORK")
	{
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (program == "SOFTWARE")
	{
		degreeProgram = DegreeProgram::SOFTWARE;
	}
	//	student parsed, increase max student count:
	maxStudents = maxStudents++;
	//	pass parsed data to add function.
	add(id, firstName, lastName, email, age, days1, days2, days3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	//	Convert seperate days integers to an array and pass into Student constructor to create a student object.
	int numCourseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	//	Create new Student object, allocate memory.
	classRosterArray[numStudents++] = new Student(studentID, firstName, lastName, emailAddress, age, numCourseDays, degreeProgram);
}

void Roster::remove(string studentID)
{
	bool del = false;
	for (int i = 0; i < maxStudents; i++)
	{
		if (del == false)
		{
			if (classRosterArray[i]->getid() == studentID)
			{
				//	delete pointer, free up that memory.
				delete classRosterArray[i];
				cout << "SUCCESS: Student was removed." << '\n';
				del = true;
			}
		}
		if (del == true)
		{
			//	Have to shift pointers or errors abound.
			//	We do this every pass even when we delete to make sure we move all pointers.
			if (i < maxStudents)
			{
				classRosterArray[i] = classRosterArray[i + 1];
			}
		}
	}
	if (del == true)
	{
		//	decrement maxStudent count
		maxStudents = maxStudents - 1;
	}
	else
	{
		cout << "ERROR: Student was not found." << '\n';
	}
}

void Roster::printAll()
{
	//	Print out entire student list.
	const int size = 7;
	Student::StudentFields fields[size] = {
		Student::StudentFields::ID,
		Student::StudentFields::FIRSTNAME,
		Student::StudentFields::LASTNAME,
		Student::StudentFields::EMAIL,
		Student::StudentFields::AGE,
		Student::StudentFields::DAYS,
		Student::StudentFields::DEGREE
	};
	for (int i = 0; i < maxStudents; i++)
	{
		classRosterArray[i]->print(fields, size);
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	//	Loop through classRosterArray and print out the average days from student data for 3 courses.
	for (int i = 0; i < maxStudents; i++)
	{
		if (classRosterArray[i]->getid() == studentID)
		{
			cout << "Student ID: " << studentID << '\t';
			cout << "Average Days in Course:" << '\t';
			cout << (classRosterArray[i]->getdays()[0] + classRosterArray[i]->getdays()[1] + classRosterArray[i]->getdays()[2]) / 3 << "." << '\n';
		}
	}
}

void Roster::printInvalidEmails()
{
	//	Note: A valid email should include an at sign('@') and period('.') and should not include a space(' ').
	char at		= '@';		//	@ symbol
	char per	= '.';		//	. period
	char spa	= ' ';		//	space, the final character
	size_t cla;				//	character located at.
	for (int i = 0; i < maxStudents; i++)
	{
		cla = classRosterArray[i]->getemail().find(at);
		if (cla == -1)
		{
			//	string missing @.
			cout << classRosterArray[i]->getid() << " " << classRosterArray[i]->getemail() << " invalid email address." << '\n';
		}
		else
		{
			//	string contained @ symbol, next checking for a period.
			cla = classRosterArray[i]->getemail().find(per);
			if (cla == -1)
			{
				//	string missing period.
				cout << classRosterArray[i]->getid() << " " << classRosterArray[i]->getemail() << " invalid email address." << '\n';
			}
			else
			{
				//	string contained a period, final check for spaces in string.
				cla = classRosterArray[i]->getemail().find(spa);
				if (cla != -1)
				{
					//	Final frontier found in string
					cout << classRosterArray[i]->getid() << " " << classRosterArray[i]->getemail() << " invalid email address." << '\n';
				}
			}
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	const int size = 7;
	Student::StudentFields fields[size] = {
		Student::StudentFields::ID,
		Student::StudentFields::FIRSTNAME,
		Student::StudentFields::LASTNAME,
		Student::StudentFields::EMAIL,
		Student::StudentFields::AGE,
		Student::StudentFields::DAYS,
		Student::StudentFields::DEGREE
	};
	for (int i = 0; i < maxStudents; i++)
	{
		if (classRosterArray[i]->getdegree() == degreeProgram)
		{
			classRosterArray[i]->print(fields, size);
		}
	}
}

Roster::~Roster()
{
	//  Doot doot.
	//	Nothing to see here.
}