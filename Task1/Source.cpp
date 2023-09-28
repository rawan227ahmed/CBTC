#include <string>
#include"iostream"
#include"fstream"
#include"student.h"
#include<vector>
using namespace std;
void readFile(vector<student>& students) {
	fstream inFile;
	inFile.open("file.txt", ios::in);
	if (inFile.is_open()) {
		string line;
		getline(inFile, line);
		getline(inFile, line);
		while (!inFile.eof()) {
			string name;
			int age;
			int id;
			int academicRecord;
			int rollNum;
			inFile >> name >> age >> id >> academicRecord >> rollNum;
			student s(name, age, id, academicRecord, rollNum);
			students.push_back(s);
		}
		inFile.close();
	}
}
void updateOutputFile(vector<student> students) {
	fstream outFile;
	outFile.open("file.txt", ios::out);
	if (outFile.is_open()) {
		outFile.clear();
		outFile << "\t\t---------------------------students---------------------------\n";
		outFile << "name age id academicRecord rollNumber\n";
		for (int i = 0; i < students.size(); i++) {
			outFile << students[i].getName() << "  " << students[i].getAge() << "  " << students[i].getId();
			outFile << "  " << students[i].getAcademicRecord() << "  " << students[i].getRollNum();
			if(i!= students.size()-1)
			outFile << endl;
		}
		outFile.close();
	}
}
void Insert(vector<student>& students) {
	cout << "\t\t\t--------------------Insert a record--------------------\n";
	int record;
	cout << "Enter the Number of students to be recorded:";
	cin >> record;
	string name;
	int age;
	int id;
	int academicRecord;
	int rollNum;
	for (int i = 0; i < record; i++) {
		cout << "Enter student name: ";
		cin >> name;
		cout << "Enter student age: ";
		cin >> age;
		cout << "Enter student id: ";
		cin >> id;
		cout << "Enter student academicRecoed: ";
		cin >> academicRecord;
		cout << "Enter student rollNum: ";
		cin >> rollNum;
		student s(name, age, id, academicRecord, rollNum);
		students.push_back(s);
		cout << "student recorded successfully\n";
		cout << "\n";
	}
	updateOutputFile(students);
}
void Display(vector<student>students) {
	cout << "\t\t\t--------------------Display records--------------------\n";
	if (students.size() == 0) {
		cout << "No student recorded yet\n";
		return;
	}
	for (int i = 0; i < students.size(); i++) {
		students[i].display();
	}
	cout << "\n";
}
void Modify(vector<student>& students) {
	cout << "\t\t\t--------------------Modify a record--------------------\n";
	if (students.size() == 0) {
		cout << "No students recorded yet\n";
		return;
	}
	int id;
	cout << "Enter the id of the student: ";
	cin >> id;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getId() == id) {
			bool back = false;
			while (!back) {
				cout << "\nto modify the name press 1\n";
				cout << "to modify the age press 2\n ";
				cout << "to modify the id press 3\n ";
				cout << "to modify the academic record press 4\n ";
				cout << "to modify the roll number press 5\n ";
				cout << "to back home press 6\n";
				cout << "choose an option: ";
				int option;
				cin >> option;
				string name;
				int num;
				switch (option)
				{
				case 1:
					cout << "Enter student name: ";
					cin >> name;
					students[i].setName(name);
					break;
				case 2:
					cout << "Enter student age: ";
					cin >> num;
					students[i].setAge(num);
					break;
				case 3:
					cout << "Enter student id: ";
					cin >> num;
					students[i].setId(num);
					break;
				case 4:
					cout << "Enter student academicRecoed: ";
					cin >> num;
					students[i].setAcademicRecord(num);
					break;
				case 5:
					cout << "Enter student rollNum: ";
					cin >> num;
					students[i].setRollNum(num);
					break;
				case 6:
					back = true;
					break;
				default:
					cout << "Invalid option\n";
					break;
				}
				cout << "Modified successfully\n";
			}
			updateOutputFile(students);
			return;
		}
	}
	cout << "this Id is not found\n";
}
void search(vector<student>students) {
	cout << "\t\t\t--------------------Search for a record--------------------\n";
	cout << "Enter An id to search for: ";
	int id;
	cin >> id;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getId() == id) {
			students[i].display();
			return;
		}
	}
	cout << "this id is not found\n";
}
void Delete(vector<student>& students) {
	cout << "\t\t\t--------------------Delete a record--------------------\n";
	cout << "Enter A student's id to be deleted: ";
	int id;
	cin >> id;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getId() == id) {
			for (int j = i; j < students.size(); j++) {
				if (j == (students.size() - 1)) {
					students.pop_back();
				}
				else {
					students[j] = students[j + 1];
				}
			}
			cout << "The student is deleted successfully\n";
			updateOutputFile(students);
			return;
		}
	}
	cout << "this id is not found\n";
}
int main() {
	bool Exit = false;
	vector <student>students;
	readFile(students);
	cout << "\t\t\t-------------------Student Record Mangment System-------------------\n";
	while (!Exit) {
		int option;
		cout << "to Insert a record press 1\n";
		cout << "to Display all students press 2\n";
		cout << "to Modify a record press 3\n";
		cout << "to search for a record press 4\n";
		cout << "to Delete a record press 5\n";
		cout << "to Exit press 6\n";
		cout << "choose your option:";
		cin >> option;
		switch (option)
		{
		case 1:
			Insert(students);
			break;
		case 2:
			Display(students);
			break;
		case 3:
			Modify(students);
			break;
		case 4:
			search(students);
			break;
		case 5:
			Delete(students);
			break;
		case 6:
			Exit = true;
			break;
		default:
			cout << "Invalid option\nPlease,Enter a right number!\n";
		}
		cout << "\n";
	}
	return 0;
}