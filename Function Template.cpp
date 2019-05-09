// Code by Ian Catapano
// 2/1/2014
// CSCI-C201
// Function template.

#include <iostream>
using namespace std;

const int USER = 1000;
const int MAX = 2;
double totalPoints = 0;
int totalPossible = 0;
double score = 0;
double scores[USER][MAX]={};

template<class T>
void sum(T a[][MAX], int num)
{
	if(num == 1)
	{
		totalPoints += a[num-1][0];
		totalPossible += a[num-1][1];
	}
	else
	{
		totalPoints += a[num-1][0];
		totalPossible += a[num-1][1];
		sum(a, num-1);
	}
}
int main()
{
	int numAssign = 0;

	cout << "How many homework assignments do you have to enter?: ";
	cin >> numAssign;

	for(int i = 0; i < numAssign; i++)
	{
		cout << "Enter points you earned for homework assignment " << i+1 << ", then enter the total points possible.: ";
		cin >> scores[i][0];
		cin >> scores[i][1];
	}
	sum(scores, numAssign);
	score = totalPoints / totalPossible;
	cout << "You had a total of " << totalPoints << " points out of " << totalPossible << " points possible. You score is: " << score * 100 << "%" << endl;
	system ("PAUSE");
}

