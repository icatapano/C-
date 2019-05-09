// Created by Ian Catapano
// Homework Assignment 5

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Student
{
public:
	Student(string userName); //Constructor to intialize the name to what has been entered.
	Student(); //Constructor to intialize the name to be blank and the number of classes to zero.
	string getName() const; //Accessor to get the named stored in the private section of the class.
	int getNumCourse() const; //Accessor to get the number of classes from the private section of the class.
	void setName(string newName); //Mutator to set the name entered to the protected variable.
	void setNumCourse(int classes); //Mutator to set the number of classes to the protected variable.

private:
	string name;
	int numCourse;
};

bool operator ==(const Student& student1, const Student& student2);

int main()
{
	string nameEntered = " ";
	int numClasses = 0;

	Student userEntry, myEntry("Ian Catapano");
	cout << "What is your name? ";
	getline(cin, nameEntered);
	cout << endl << "How many courses are you currently enrolled in? ";
	cin >> numClasses;
	cout << endl;
	userEntry.setName(nameEntered);
	userEntry.setNumCourse(numClasses);
	myEntry.setNumCourse(2);
	cout << "Your information:" << endl << "Name: " << userEntry.getName() << endl << "Number of courses: "
		<< userEntry.getNumCourse() << endl << endl << "My information:" << endl << "Name: " << myEntry.getName()
		<< endl << "Number of courses: " << myEntry.getNumCourse() << endl << endl;
	if (userEntry == myEntry)
		cout << "The two students above are identical." << endl;
	else
		cout << "The two students above are not identical." << endl;
	system("PAUSE");
	return 0;
}

bool operator ==(const Student& student1, const Student& student2)
{
	if ((student1.getName() == student2.getName()) && (student1.getNumCourse() == student2.getNumCourse()))
		return true;
	else
		return false;
}

Student::Student(string userName)
	: name(userName), numCourse(0)
{}

Student::Student()
	:name(" "), numCourse(0)
{}

string Student::getName() const
{
	return name;
}

int Student::getNumCourse() const
{
	return numCourse;
}

void Student::setName(string newName)
{
	name = newName;
}

void Student::setNumCourse(int classes)
{
	numCourse = classes;
}