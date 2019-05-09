// Created by: Ian Catapano
// Homework Assignment 9

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
public:
	// Constructor to create an instance of class Node.
	Node(const T& theData, Node<T>* theLink) :data(theData), link(theLink) {}
	// Mutator to set the value for private data variable.
	void setData(const T& theData) { data = theData; }
	// Mutator to set the value for private link variable.
	void setLink(Node<T>* ptr) { link = ptr; }
	// Accessor to retrieve the value of the private data variable.
	const T getData() const { return data; }
	// Accessor to retrieve the value of the private link variable.
	Node<T>* getLink() const { return link; }
private:
	T data;
	Node<T> *link;
};

template <class T>
class LinkedList
{
public:
	// Constructor to create an instance of LinkedList and set it to an empty list.
	LinkedList():head(NULL){}
	// Function to add a new node to the head of the list.
	void insertHead(T theData){ head = new Node<T>(theData, head); }
	// Function to add a new node after a selected node.
	void insertAfter(Node<T>* afterNode, T theData){ afterNode->setLink(new Node<T>(theData, afterNode->getLink())); }
	// Funtion to delete a selected node.
	void removeANode(Node<T>* beforeNode, Node<T>* remove);
	// Function to remove all nodes and return the linked list back to empty.
	void removeAllNodes();
	// Function to search the link list for a node.
	void search(const T& tar);
	// Function to display the list in reverse order of entry.
	void display();
	// Destructor to clear memory.
	virtual ~LinkedList(){ removeAllNodes(); }
private:
	Node<T>* head;
};

int main()
{
	char next;
	char letter;
	LinkedList<char> text;
	cout << "Enter a line of text:\n";
	cin.get(next);
	while(next != '\n')
	{
		text.insertHead(next);
		cin.get(next);
	}
	cout << "The input text line in reverse order:\n";
	text.display();
	cout << "Enter a character to find: ";
	cin.get(letter);
	text.search(letter);
	cout << "The reverse text line after inserting * is:\n";
	text.display();
	system("PAUSE");
	return 0;
}

template <class T>
void LinkedList<T>::search(const T& tar)
{
	Node<T>* here = head;
	while (here->getLink() != NULL)
	{
		if (here->getData() == tar)
			insertAfter(here, '*');
		here = here->getLink();
	}
}

template <class T>
void LinkedList<T>::removeANode(Node<T>* beforeNode, Node<T>* remove)
{
	beforeNode->setLink(remove->getLink());
	delete remove;
}

template <class T>
void LinkedList<T>::removeAllNodes()
{
	Node<T>* here = head;
	if(here == NULL)
		return;
	while (here->getLink() != NULL)
		removeANode(here, here->getLink());
	delete here;
}


template <class T>
void LinkedList<T>::display()
{
	Node<T>* here = head;
	while (here != NULL)
	{
		T result = here->getData();
		cout << result;
		here = here->getLink();
	}
	cout << endl;
}