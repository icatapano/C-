// Created by: Ian Catapano
// Homework Assignment 7

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void insertLineNumber(ifstream& inStream, ofstream& outStream); // Copies a file and adds line numbers to each new line.

int main()
{
	ifstream inputFile, testStream;
	ofstream outputFile;
	char iFile[50], oFile[50], choice;

	cout << "Enter source file then target file: ";
	cin >> iFile >> oFile;
	inputFile.open(iFile);
	if (inputFile.fail())
	{
		cout << "Error: File " << iFile << " does not exist!\n";
		system("PAUSE");
		exit(1);
	}
	testStream.open(oFile);
	if (testStream.fail())
	{
		testStream.close();
		outputFile.open(oFile);
	}
	else
	{
		cout << "File " << oFile << " already exists, would you like to overwrite it (y/n)?:";
		cin >> choice;
		if (choice == 'n')
		{
			testStream.close();
			cout << "No file was changed.\n";
			system("PAUSE");
			exit(1);
		}
		testStream.close();
		outputFile.open(oFile);
	}
	insertLineNumber(inputFile, outputFile);
	cout << "File " << oFile << " has been copied from " << iFile << " with line numbers added.\n";
	system("PAUSE");
	inputFile.close();
	outputFile.close();
	return 0;
}

void insertLineNumber(ifstream& inFile, ofstream& outFile)
{
	char next;
	int num = 1;

	inFile.get(next);
	outFile.setf(ios::right | ios::adjustfield);
	outFile << setw(4) << num;

	while (!inFile.eof())
	{

		if (next == '\n')
		{
			num++;
			outFile << endl;
			outFile.setf(ios::right | ios::adjustfield);
			outFile << setw(4) << num << "  ";
		}
		else
		{
			outFile.setf(0, ios::floatfield);
			outFile << next;
		}
		outFile.flush();
		inFile.get(next);
	}
}