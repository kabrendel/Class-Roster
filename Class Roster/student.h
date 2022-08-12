#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student
{
public:
	//	public accessor functions for our Student class
	string getid();
	string getfirstName();
	string getlastName();
	string getemail();
	int getage();
	int * getdays();
	DegreeProgram getdegree();
	//	public mutator functions for our Student class
	void setid(string& in);
	void setfirstName(string& in);
	void setlastName(string& in);
	void setemail(string& in);
	void setage(int in);
	void setdays(int *in);
	void setdegree(DegreeProgram in);
	//	Constructor
	//	default constructor
	Student();
	//	Student id, first name, last name, email, age, days[3] pointer, degree
	Student(string& a, string& b, string& c, string& d, int e, int *f, DegreeProgram g);
	//	enum StudentFields for easier readability in print function
	enum StudentFields
	{
		ID, FIRSTNAME, LASTNAME, EMAIL, AGE, DAYS, DEGREE
	};
	void print(StudentFields *in, int size);

//	private variables for our Student class
//	defined as m_ + variable name to denote these are member variables of our class.
private:
	string m_id;
	string m_firstName;
	string m_lastName;
	string m_email;
	const static int day = 3;
	int m_age;
	int m_days[day];
	DegreeProgram m_degree;
};