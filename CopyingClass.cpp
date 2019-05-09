// Created by: Ian Catapano
// Homework Assignment 6
// 3/27/2014

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student
{
public:
	Student(); //default constructor for class Student
	Student(string aName); //constructor for class Student and assigns a predefined name
	Student& operator =(const Student& otherStudent); //copy constructor to copy one class to another
	string getName();  //accessor to retrieve name from private variable
	int getNumCourse(); //accessor to get the number of courses from private variable
	string* getCourseList(); //accessor to retieve array of course names from private array
	void setName(string aName); //mutator to set a name in private variable
	void setNumCourse(int numClass); //mutator to set number of courses to private variable
	void setCourseList(int num); //mutator to set course names to private array
	void input(); //function to prompt user for information
	void output(); //function to display a students information
	~Student() { delete[] courseList; } //destructor
private:
	string name;
	int numCourses;
	string* courseList;
};

void testStudent(Student aStudent);

int main()
{
	Student student1("Ian Catapano"), student2;
	testStudent(student1);
	student2 = student1;
	cout << "1st Student's info after Testing:\n";
	student1.output();
	cout << "2nd Student's info after Testing:\n";
	student2.output();
	system("PAUSE");
}

Student::Student()
: name(" "), numCourses(0)
{}

Student::Student(string aName)
: name(aName), numCourses(0)
{}

Student& Student::operator =(const Student& aStudent)
{
	if (this == & aStudent)
		return *this;
	else
	{
		name = aStudent.name;
		numCourses = aStudent.numCourses;
		delete[] courseList;
		courseList = new string[numCourses];
		for (int i = 0; i < numCourses; i++)
			courseList[i] = aStudent.courseList[i];
		return *this;
	}
}

string Student::getName() 
{
	return name;
}

int Student::getNumCourse()
{
	return numCourses;
}

string* Student::getCourseList()
{
	return courseList;
}

void Student::setName(string aName)
{
	name = aName;
}

void Student::setNumCourse(int numClass)
{
	numCourses = numClass;
}

void Student::setCourseList(int num)
{
	string courseName;
	courseList = new string[num];
	for (int i = 0; i < num; i++)
	{
		getline(cin, courseName);
		courseList[i] = courseName;
	}
}

void Student::input()
{
	string aName;
	int numClass;

	cout << "Enter the student's full name: ";
	getline(cin, aName);
	setName(aName);
	cout << "\nHow many classes is " << aName << " currently enrolled in?: ";
	cin >> numClass;
	cin.ignore(50, '\n');
	setNumCourse(numClass);
	cout << "\nEnter the " << numClass << " courses, one per line:\n";
	setCourseList(numClass);
}

void Student::output()
{
	int number = getNumCourse();
	string* courseName = getCourseList();

	cout << "Student's Name: " << getName() << endl;
	cout << "List of Courses:\n";
	for (int i = 0; i < number; i++)
	{
		cout << i+1 << '.' << " " << courseName[i] << endl;
	}
}

void testStudent(Student aStudent)
{
	cout << "Student's info:\n";
	aStudent.input();
	aStudent.output();
}