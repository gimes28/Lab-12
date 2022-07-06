#ifndef SORT_h
#define SORT_h
#include <iostream>
#include <random>
using namespace std;

class Sort {
private:
    int size;
    //int* sortArr;
public:
    //Sort();
    //Sort(int sortArr[], int s);
    void BubbleSort(int sortArr[], int size);
    void InsertionSort(int sortArr[], int size);
    void QuickSort(int sortArr[], int low, int hi);
    int Partition(int sortArr[], int low, int hi);
    void CountingSort(int sortArr[], int freqArray[], int finalArray[], int size);
    void Merge(int sortArr[], int left, int right, int middle);
    void MergeSort(int sortArr[], int left , int right);
    void HeapSort(int sortArr[], int size);
    void Heap_Util(int sortArr[], int size, int place);
    void CountSort_Util(int sortArr[], int freqArray[], int finalArray[], int size, int place);
    void RadixSort(int sortArr[], int freqArray[], int finalArray[], int size);
    void printArray(int sortArr[], int size);
};

void Sort::BubbleSort(int sortArr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sortArr[j] > sortArr[j + 1]) {
                // swap(sortArr[j], sortArr[j + 1]);
                int temp = sortArr[j];
                sortArr[j] = sortArr[j + 1];
                sortArr[j + 1] = temp;
            }
        }
    }
}

void Sort::InsertionSort(int sortArr[], int size) {
    int key;
    for (int i = 1; i < size; i++)
    {
        key = sortArr[i];
        int j = i - 1;
        while (j >= 0 && sortArr[j] > key)
        {
            sortArr[j + 1] = sortArr[j];
            j--;
        }
        sortArr[j + 1] = key;

    }
}

void Sort::QuickSort(int curr[], int low, int high) {
    if (low < high) {
        int pivot = Partition(curr, low, high);
        QuickSort(curr, low, pivot - 1);
        QuickSort(curr, pivot + 1, high);
    }
}

int Sort::Partition(int curr[], int low, int high) {
    int pivot = curr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (curr[j] < pivot) {
            i++;
            int temp = curr[i];
            curr[i] = curr[j];
            curr[j] = temp;
        }
    }
    int temp = curr[i + 1];
    curr[i + 1] = curr[high];
    curr[high] = temp;
    return (i + 1);
}



void Sort::CountingSort(int sortArr[], int freqArray[], int finalArray[], int size) {
    int max = sortArr[0];

    for (int i = 1; i < size; i++) {
        if (max < sortArr[i]) {
            max = sortArr[i];
        }
    }

    for (int i = 0; i <= max; i++) {
        freqArray[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        freqArray[sortArr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        freqArray[i] += freqArray[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        finalArray[freqArray[sortArr[i]] - 1] = sortArr[i];
        freqArray[sortArr[i]]--;
    }

    for (int i = 0; i < size; i++) {
        sortArr[i] = finalArray[i];
    }
}

void Sort::MergeSort(int sortArr[], int left, int right) {
    int middle;
    if (left < right) {
        middle = (right + left) / 2;
        MergeSort(sortArr, left, middle);
        MergeSort(sortArr, middle + 1, right);
        Merge(sortArr, left, right, middle);
    }
}

void Sort::Merge(int sortArr[], int left, int right, int middle) {

    int low = left;
    int mid = middle + 1;
    int iter = 0;

    int* temp = new int[right - left + 1];

    while (low <= middle && mid <= right) {
        if (sortArr[low] < sortArr[mid]) {
            temp[iter] = sortArr[low];
            iter++;
            low++;
        }
        else {
            temp[iter] = sortArr[mid];
            iter++;
            mid++;
        }
    }

    while (low <= middle) {
        temp[iter] = sortArr[low];
        iter++;
        low++;
    }

    while (mid <= right) {
        temp[iter] = sortArr[mid];
        iter++;
        mid++;
    }

    for (int i = left; i <= right; i++) {
        sortArr[i] = temp[i - left];
    }
}

void Sort::HeapSort(int sortArr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        Heap_Util(sortArr, size, i);
    }
    for (int i = size - 1; i >= 0; i--) {
        //swap(sortArr[0], sortArr[i]);
        int temp = sortArr[0];
        sortArr[0] = sortArr[i];
        sortArr[i] = temp;
        Heap_Util(sortArr, i, 0);
    }
}

void Sort::Heap_Util(int sortArr[], int size, int place) {
    int max = place;
    int left = 2 * place + 1;
    int right = 2 * place + 2;

    if (left < size && sortArr[left] > sortArr[max]) {
        max = left;
    }
    if (right < size && sortArr[right] > sortArr[max]) {
        max = right;
    }
    if (max != place) {
        int temp = sortArr[place];
        sortArr[place] = sortArr[max];
        sortArr[max] = temp;
        Heap_Util(sortArr, size, max);
    }
}

void Sort::RadixSort(int sortArr[], int freqArray[], int finalArray[], int size) {
    int max = sortArr[0];

    for (int i = 1; i < size; i++) {
        if (max < sortArr[i]) {
            max = sortArr[i];
        }
    }

    for (int i = 1; max / i > 0; i *= 10) {
        CountSort_Util(sortArr, freqArray, finalArray, size, i);
    }
}

void Sort::CountSort_Util(int sortArr[], int freqArray[], int finalArray[], int size, int place) {

    for (int i = 0; i < 10; i++) {
        freqArray[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        freqArray[(sortArr[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        freqArray[i] += freqArray[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        finalArray[freqArray[(sortArr[i] / place) % 10] - 1] = sortArr[i];
        freqArray[(sortArr[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        sortArr[i] = finalArray[i];
    }
}


void Sort::printArray(int sortArr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << sortArr[i] << " ";
    }
}
#endif