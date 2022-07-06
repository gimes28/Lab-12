#ifndef STUDENTLIST_h
#define STUDENTLIST_h
#include <iostream>
#include "Student.h"
using namespace std;

struct Node {
	Student* data;
	int index;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class StudentList {
private:
	int size;
	//Node* head;
public:
	Node* head;
	StudentList();
	void AddStudent(Student* val);
	Student* GetStudent(int pos);
	bool isEmpty();
	int length();
	void printList(bool AD = true);
	Node* nodeNav(int index);
	void BubbleSort();
	void InsertionSort();
	void QuickSort(Node* curr, int lo, int high);
	int Partition(Node* curr, int low, int hi);
};

StudentList::StudentList() {
	size = 0;
	head = nullptr;
}

void StudentList::AddStudent(Student* val) {
	Node* newNode = new Node;
	newNode->data = val;
	if (size == 0) {
		head = newNode;
		head->index = 0;
	}
	else {
		Node* search = head;
		while (search->next != nullptr) {
			search = search->next;
		}
		search->next = newNode;
		newNode->prev = search;
		newNode->index = size;
	}
	size++;
}

Student* StudentList::GetStudent(int pos) {
	bool found = false;
	Node* search = head;
	while (search != nullptr) {
		if (search->index == pos) {
			return search->data;
		}
		search = search->next;
	}
	return nullptr;
}

bool StudentList::isEmpty() {
	return size == 0;
}

int StudentList::length() {
	return size;
}

void StudentList::printList(bool AD) {

	if (AD) {
		Node* search = head;
		while (search != nullptr) {
			cout << "FName: " << search->data->getfName() << " LName: " << search->data->getlName() << " MNumber: " << search->data->getMNumber() << " index " << search->index << endl;
			search = search->next;
		}
	}
	else {
		Node* search = nodeNav(size - 1);
		while (search != nullptr) {
			cout << "FName: " << search->data->getfName() << " LName: " << search->data->getlName() << " MNumber: " << search->data->getMNumber() << " index " << search->index << endl;
			search = search->prev;
		}
	}
}

Node* StudentList::nodeNav(int index) {
	Node* nodePtr = head;

	for (int i = 0; i < index; i++) {
		nodePtr = nodePtr->next;
	}
	return nodePtr;
}

void StudentList::BubbleSort() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (GetStudent(j)->getfName() > GetStudent(j + 1)->getfName()) {
				Student* temp = nodeNav(j)->data;
				nodeNav(j)->data = nodeNav(j + 1)->data;
				nodeNav(j + 1)->data = temp;
			}
		}
	}
}

void StudentList::InsertionSort() {
	string key;
	for (int i = 1; i < size; i++)
	{
		key = nodeNav(i)->data->getlName();
		Student* temp = nodeNav(i)->data;
		int j = i - 1;
		while (j >= 0 && nodeNav(j)->data->getlName() > key)
		{
			nodeNav(j + 1)->data = nodeNav(j)->data;
			j--;
		}
		nodeNav(j + 1)->data = temp;
	}
}

void StudentList::QuickSort(Node* curr, int lo, int high) {

	if (lo < high) {
		int pivot = Partition(curr, lo, high);
		QuickSort(curr, lo, pivot - 1);
		QuickSort(curr, pivot + 1, high);
	}
}

int StudentList::Partition(Node* curr, int low, int high) {
	Node* pivot = nodeNav(high);
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (nodeNav(j)->data->getMNumber() < pivot->data->getMNumber()) {
			i++;
			Student* temp = nodeNav(i)->data;
			nodeNav(i)->data = nodeNav(j)->data;
			nodeNav(j)->data = temp;
		}
	}
	Student* temp = nodeNav(i + 1)->data;
	nodeNav(i + 1)->data = nodeNav(high)->data;
	nodeNav(high)->data = temp;
	return (i + 1);
}

#endif