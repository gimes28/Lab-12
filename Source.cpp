#include <iostream>
#include "Sort.h"
#include <random>
#include <chrono>
#include <algorithm>
#include "Student.h"
#include "StudentList.h"
typedef std::chrono::high_resolution_clock Clock;
using namespace std;

string rndString(int size) {
	string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string retString = "";
	for (int i = 0; i < size; i++) {
		int rnd = rand() % 25;
		retString += chars.at(rnd);
	}

	return retString;
}

int main() {
	srand(time(NULL));

	const int size = 50;
	Student* myStudarr[size];

	for (int i = 0; i < size; i++) {
		int mnum = i + 1;
		myStudarr[i] = new Student(rndString(5), rndString(7), mnum);
	}

	int seed = 45;
	shuffle(myStudarr, myStudarr + size, default_random_engine(seed));

	StudentList myList;

	for (int i = 0; i < size; i++) {
		myList.AddStudent(myStudarr[i]);
	}

	myList.printList();
	cout << endl;

	bool quit = false;
	while (!quit) {
		int in;
		do {
			cout << "Select a sort method to apply to the list: " << endl;
			cout << "  - Enter 1 for Bubble sort by first name" << endl;
			cout << "  - Enter 2 for Insertion sort by last name" << endl;
			cout << "  - Enter 3 for Quick sort by M number" << endl;

			cin >> in;

		} while (in < 1 || in > 3);

		int order;

		do {
			cout << "Enter 1 for ascending or 2 for descending order: " << endl;

			cin >> order;

		} while (order < 1 || order > 2);

		if (in == 1) {
			myList.BubbleSort();
		}
		else if (in == 2) {
			myList.InsertionSort();
		}
		else {
			int low = myList.nodeNav(0)->index;
			int high = myList.length() - 1;

			myList.QuickSort(myList.head, low, high);
		}

		if (order == 1) {
			myList.printList(true);
		}
		else {
			myList.printList(false);
		}

		int val;
		cout << "Do you want to keep sorting(1 to quit, 2 to keep sorting)?" << endl;
		cin >> val;

		if (val == 1) {
			quit = true;
		}
	}

	////////////////////////////////////////////
	//		  TESTING USED FOR TASK 2	      //
	////////////////////////////////////////////

  /*

	Sort bubbleTest;
	Sort insertionTest;
	Sort quickTest;
	Sort countingTest;
	Sort mergeTest;
	Sort radixTest;
	Sort heapTest;

	cout << "Unsorted Array: ";
	bubbleTest.printArray(sortArr, size);
	cout << endl;

	auto startBubble = Clock::now();
	bubbleTest.BubbleSort(sortArr, size);
	auto stopBubble = Clock::now();
	cout << endl;
	cout << size << " Items" << ": Bubble sort time: " << chrono::duration_cast<chrono::nanoseconds>(stopBubble - startBubble).count() << " nanoseconds" << endl;
	cout << "Sorted Array: ";
	bubbleTest.printArray(sortArr, size);
	cout << endl;

	shuffle(sortArr, sortArr + size, default_random_engine(10));

	auto startInsertion = Clock::now();
	insertionTest.InsertionSort(sortArr, size);
	auto stopInsertion = Clock::now();
	cout << endl;
	cout << size << " Items" << ": Insertion sort time: " << chrono::duration_cast<chrono::nanoseconds>(stopInsertion - startInsertion).count() << " nanoseconds" << endl;
	cout << "Sorted Array: ";
	insertionTest.printArray(sortArr, size);
	cout << endl;

	shuffle(sortArr, sortArr + size, default_random_engine(15));

	auto startQuick = Clock::now();
	quickTest.QuickSort(sortArr, 0, size - 1);
	auto stopQuick = Clock::now();
	cout << endl;
	cout << size << " Items" << ": Quick sort time: " << chrono::duration_cast<chrono::nanoseconds>(stopQuick - startQuick).count() << " nanoseconds" << endl;
	cout << "Sorted Array: ";
	quickTest.printArray(sortArr, size);
	cout << endl;


	shuffle(sortArr, sortArr + size, default_random_engine(20));

	auto startCount = Clock::now();
	int freqArray[2 * size] = { 0 };
	int finalArray[size] = { 0 };
	countingTest.CountingSort(sortArr, freqArray, finalArray, size);
	auto stopCount = Clock::now();
	cout << endl;
	cout << size << " Items" << ": Counting sort time: " << chrono::duration_cast<chrono::nanoseconds>(stopCount - startCount).count() << " nanoseconds" << endl;
	cout << "Sorted Array: ";
	countingTest.printArray(sortArr, size);
	cout << endl;

	shuffle(sortArr, sortArr + size, default_random_engine(25));

	auto mergeStart = Clock::now();
	mergeTest.MergeSort(sortArr, 0, size - 1);
	auto mergeStop = Clock::now();
	cout << endl;
	cout << size << " Items" << ": Merge sort time: " << chrono::duration_cast<chrono::nanoseconds>(mergeStop - mergeStart).count() << " nanoseconds" << endl;
	cout << "Sorted Array: ";
	mergeTest.printArray(sortArr, size);
	cout << endl;

	shuffle(sortArr, sortArr + size, default_random_engine(30));

	int freqArray2[2 * size];
	int finalArray2[size];
	auto startRadix = Clock::now();
	radixTest.RadixSort(sortArr, freqArray2, finalArray2, size);
	auto stopRadix = Clock::now();
	cout << endl;
	cout << size << " Items" << ": Radix sort time: " << chrono::duration_cast<chrono::nanoseconds>(stopRadix - startRadix).count() << " nanoseconds" << endl;
	cout << "Sorted Array: ";
	radixTest.printArray(sortArr, size);
	cout << endl;

	shuffle(sortArr, sortArr + size, default_random_engine(30));

	auto startHeap = Clock::now();
	heapTest.HeapSort(sortArr, size);
	auto stopHeap = Clock::now();
	cout << endl;
	cout << size << " Items" << ": Heap sort time: " << chrono::duration_cast<chrono::nanoseconds>(stopHeap - startHeap).count() << " nanoseconds" << endl;
	cout << "Sorted Array: ";
	heapTest.printArray(sortArr, size);
	cout << endl;

  */
}