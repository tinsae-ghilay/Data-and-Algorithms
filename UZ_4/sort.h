//
// Created by tgk on 6/12/24.
//

#ifndef SORT_H
#define SORT_H
# include <vector>

// swaps two integers
# define SWAP(x, y)  {int t = x; x= y; y = t;}

using  namespace  std;

// populates a vector and returns the vector
vector<int> generateArray(size_t size);

// sorts a vector using insertion sorting algorithm in a loop
void loopInsertion(vector<int>& array);

// sorts a vector using insertion sorting algorithm recursively
void recursiveInsertion(vector<int>& array, size_t n);

// sorts a vector using selection sort algorithm, loop
void selection(vector<int>& array);

// shuffles a vector for another round of sorting;
void shuffleVector(vector<int>& array);

// prints vector elements
void printVector(vector<int>& arr);

// runs loop insertion sort multiple times and returns the time it took to complete the task
unsigned long testInsertion(int repeat);

// runs recursive insertion sort multiple times and returns the time it took to complete the task
unsigned long testRecursiveInsertion(int repeat);

// runs selection sort multiple times and returns the time it took to complete the task
unsigned long testSelection(int repeat);

#endif //SORT_H
