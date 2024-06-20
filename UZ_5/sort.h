//
// Created by tgk on 6/18/24.
//

#ifndef SORT_H
#define SORT_H
# include <vector>
# include <algorithm> // will use this for shuffling

# define SWAP(x,y) {int t = x; x = y; y = t;}

using namespace std;

// fills an array with random elements up to a given size
// array will be sorted, hence, there is a need for a shuffler function to have it unsorted
vector<int> generateArray(int size);

// shuffles array so that it can be sorted again
void vShuffle(vector<int>& array);

// bubble sort
// uses the bubble sort algorithm to sort items
//  get sorted in ascending order
void bubbleSort(vector<int>& array);

// merges two parts of mergeSorted array
void merge(vector<int>& arr, size_t start, size_t mid, size_t end);

// merge sort
// sorts a given array using merge sort algorithm
// items get sorted in ascending order
void mergeSort(vector<int>& arr, size_t start, size_t end);


// prints array elements in a formatted manner
// array will be printed like below
// Array elements : {1, 2, 3, 4, 5}
void print(const vector<int>& arr);

// runs Bubble sort repeatedly on a shuffled array
// return the average duration it takes to sort the shuffled array
unsigned long testBubbleSort(const int repeat);

// runs Merge sort repeatedly on a shuffled array
// return the average duration it takes to sort the shuffled array
unsigned long testMergeSort(const int repeat);
#endif //SORT_H
