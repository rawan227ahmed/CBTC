#pragma once
#include"iostream"
class student
{
private:
    std::string name;
	int age;
	int id;
	int academicRecord;
	int rollNum;
public:
	student();
	student(std::string, int, int, int, int);
	void setName(std::string Name);
    std::string getName() const;
	void setAge(int Age);
	int getAge() const;
	void setId(int Id);
	int getId() const;
	void setAcademicRecord(int AcademicRecord);
	int getAcademicRecord() const ;
	void setRollNum(int RollNum);
	int getRollNum() const;
	void display()const;
	~student();
};

