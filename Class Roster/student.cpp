#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//	accessor get functions for all variables
string Student::getid()
{
	return m_id;
}

string Student::getfirstName()
{
	return m_firstName;
}

string Student::getlastName()
{
	return m_lastName;
}

string Student::getemail()
{
	return m_email;
}

int Student::getage()
{
	return m_age;
}

int * Student::getdays()
{
	//	returns pointer to array "days".
	return m_days;
}

DegreeProgram Student::getdegree()
{
	return m_degree;
}

//	mutator or set functions for our Student class
void Student::setid(string& in)
{
	m_id = in;
}

void Student::setfirstName(string& in)
{
	m_firstName = in;
}

void Student::setlastName(string& in)
{
	m_lastName = in;
}

void Student::setemail(string& in)
{
	m_email = in;
}

void Student::setage(int in)
{
	m_age = in;
}

void Student::setdays(int *in)
{
	for (int i = 0; i < day; i++)
	{
		m_days[i] = in[i];
	}
}

void Student::setdegree(DegreeProgram in)
{
	m_degree = in;
}

//	Start of constructors:
Student::Student()
{
	//	default constructor with no parameters.
	//	could delete, used for testing.
	//	Student id, first name, last name, email, age, days[3], degree
	string a = "0";
	string b = " ";
	string c = " ";
	string d = " ";
	int e = 0;
	int f[day] = { 0,0,0 };
	DegreeProgram g = SOFTWARE;
	//	Set those default values
	setid(a);
	setfirstName(b);
	setlastName(c);
	setemail(d);
	setage(e);
	setdays(f);
	setdegree(g);
}

Student::Student(string& a, string& b, string& c, string& d, int e, int* f, DegreeProgram g)
{
	//	Should be some data checking/verification steps maybe..
	//	Constructor that takes in all fields:
	//	Student id, first name, last name, email, age, days[3], degree
	setid(a);
	setfirstName(b);
	setlastName(c);
	setemail(d);
	setage(e);
	setdays(f);
	setdegree(g);
}
//	End of constructors.

//	print function
void Student::print(StudentFields *in,int size)
{
	//	intake array of desired fields, array size, and print those fields
	//	Enumerated list: ID, FIRSTNAME, LASTNAME, EMAIL, AGE, DAYS, DEGREE
	for (int i = 0; i < size; i++)
	{
		switch (in[i])
		{
		case ID:
			cout << Student::getid() << '\t';
			break;
		case FIRSTNAME:
			cout << "First Name: " << Student::getfirstName() << '\t';
			break;
		case LASTNAME:
			cout << "Last Name: " << Student::getlastName() << '\t';
			break;
		case EMAIL:
			cout << "Email: " << Student::getemail() << '\t';
			break;
		case AGE:
			cout << "Age: " << Student::getage() << '\t';
			break;
		case DAYS:
			cout << "daysInCourse: {";
			for (int i = 0; i < day; i++)
			{
				cout << Student::getdays()[i];
				if (i < (day - 1))
				{
					cout << ", ";
				}
			}
			cout << "}" << '\t';
			break;
		case DEGREE:
			//	Enumerated degree types:
			//	SECURITY, NETWORK, SOFTWARE
			cout << "DegreeProgram: ";
			if (Student::getdegree() == SECURITY)
			{
				cout << "SECURITY" << '\n';
			}
			else if (Student::getdegree() == NETWORK)
			{
				cout << "NETWORK" << '\n';
			}
			else if (Student::getdegree() == SOFTWARE)
			{
				cout << "SOFTWARE" << '\n';
			}
			else
			{
				//	no match to degree types
				cout << "Degree Error" << '\n';
			}
			break;
		default:
			//	Error, could be array size passed in doesn't match array or array value doesn't match enumerated types
			cout << "Unexpected case in print function." << '\n';
			goto exit_loop;
		}
	}
	exit_loop:;
}