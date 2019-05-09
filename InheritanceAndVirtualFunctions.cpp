// Created by: Ian Catapano
// Homework Assignment 8

#include<iostream>
#include<string>
using namespace std;

class Pet
{
public:
	//Default constructor
	Pet()
		:name(""), age(0), weight(0){}
	//Constructor to create class object with variables intialized.
	Pet(const string& n, const int& a, const double& w)		
		:name(n), age(a), weight(w){}
	//Mutator to set the name to the private variable for the class object.
	void setName(string n){ name = n; }
	//Accessor to retrieve the name from the private variable for the class object.
	string getName() const { return name; }
	//Mutator to set the age to the private variable for the class object.
	void setAge(int a){ age = a; }
	//Accessor to retriece the age from the private variable for the class object.
	int getAge() const { return age; }
	//Mutator to set the weight to the private variable for the class object.
	void setWeight(double w){ weight = w; }
	//Accessor to retrieve the weight from the private variable for the class object.
	double getWeight() const { return weight; }
	//Function that retireve the life span of the animal, defined later.
	virtual int getLifespan(){ return 0; }
	//Function to return the remaining number of years a pet had left to live.
	int getRemainingYears(){ return getLifespan() - getAge(); }
private:
	string name;
	int age;
	double weight;
};

class Dog : public Pet
{
public:
	//Default constructor for a dog class object.
	Dog()
		:Pet(), breed(""){};
	//Constructor for dog class object that initializes the variables with a value.
	Dog(const string& n, const int& a, const double& w, const string& b)
		:Pet(n, a, w), breed(b){};
	//Mutator to set the private variable breed of the dog class object.
	void setBreed(string b){ breed = b; };
	//Accessor to return the private variable breed value of the dog class object.
	string getBreed() const { return breed; };
	//Redefined life span function for dog class objects.
	int getLifespan();
private:
	string breed;
};

int Dog::getLifespan()
{
	if (getWeight() < 101)
		return 13;
	else
		return 7;
}
class Cat : public Pet
{
public:
	//Redifined life span function for cat class objects.
	int getLifespan(){ return 8; };
};

int main()
{
	int tempAge = 0;
	double tempWeight = 0;
	Dog aDog;
	Cat aCat;
	aCat.setName("Kitty");
	aCat.setAge(2);
	aCat.setWeight(2.5);
	cout << aCat.getName() << "'s lifespan is " << aCat.getLifespan() << " years.\n";
	cout << aCat.getName() << "'s has " << aCat.getRemainingYears() << " remaining years of life.\n";
	aDog.setName("George");
	aDog.setBreed("Great Dane");
	cout << "How old is the dog?: ";
	cin >> tempAge;
	aDog.setAge(tempAge);
	cout << "How much does the dog weigh?: ";
	cin >> tempWeight;
	aDog.setWeight(tempWeight);
	cout << aDog.getName() << "'s lifespan is " << aDog.getLifespan() << " years.\n";
	cout << aDog.getName() << "'s has " << aDog.getRemainingYears() << " remaining years of life.\n";

	system("PAUSE");
	return 0;
}