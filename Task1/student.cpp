#include "student.h"
#include"iostream"
using namespace std;
student::student()
{
	name = "\0";
	age = 0;
	id = 0;
	academicRecord = 0;
	rollNum = 0;
}

student::student(std::string Name, int Age, int Id, int AcademicRecord, int RollNum)
{
	name = Name;
	age = Age;
	id = Id;
	academicRecord = AcademicRecord;
	rollNum = RollNum;
}

void student::setName(std::string Name)
{
	name = Name;
}

std::string student::getName() const
{
	return name;
}

void student::setAge(int Age)
{
	age = Age;
}

int student::getAge() const
{
	return age;
}

void student::setId(int Id)
{
	id = Id;
}

int student::getId() const
{
	return id;
}

void student::setAcademicRecord(int AcademicRecord)
{
	academicRecord = AcademicRecord;
}

int student::getAcademicRecord() const
{
	return academicRecord;
}

void student::setRollNum(int RollNum)
{
	rollNum = RollNum;
}

int student::getRollNum() const
{
	return rollNum;
}

void student::display() const
{
	cout << "student name: " << name << endl;
	cout << "student age: " << age << endl;
	cout << "student id: " << id << endl;
	cout << "student academic record: " << academicRecord << endl;
	cout << "student roll number: " << rollNum << endl;
	cout << "\t\t\t**********************************************\n";
}

student::~student()
{

}
