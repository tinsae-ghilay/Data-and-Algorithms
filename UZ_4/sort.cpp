//
// Created by tgk on 6/14/24.
//

#include "sort.h"
#include <random>
#include <iostream>
# include <chrono>
# include <algorithm>
using namespace std;

// insertion sort loop
// sorts an array of elements in ascending order;
// source pseudo code on wikipedia
// [insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)
void loopInsertion(vector<int>& array) {
    // we start from second element
    // because the first element is considered sorted
    // as there are no items to compare it with
    for(size_t i = 1; i < array.size();i++) {
        // we compare item[i] with items below it,
        // we keep swaping it until item to the left is smaller than it
        size_t j = i;
        // improved version, reduces the amount of copying that hapens when we use SWAP() by half
        // source 'Data Structures and Algorithms made easy' - {by Narasimha Karumanchi}
        const auto target = array[i];
        while(j > 0 && array[j-1] > target) {
            // SWAP(array[j], array[j-1]; This is changed because it involves too much copying.
            // move every item bigger than target, to the right.
            // by replacing item at(j) with previous item -> array at(j-1)
            array[j] =  array[j-1];
            j--;
        }
        // when no items are biger than it any more, put target in the empty space
        // empty space exists because we moved all bigger elements to the right
        array[j] =  target;
    }
}

// insertion sort recursive
// [insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)
void recursiveInsertion(vector<int>& array, size_t n) {

    if (n <= 1) { // last item, done sorting
        // end
        return;
    }
    // sort n-1 elements first
    recursiveInsertion(array,n-1);
    size_t j = n-1;
    // improved version, reduces the amount of copying that hapens when we use SWAP() by half
    const auto target = array[n-1];
    while(j > 0 && array[j-1] > target) {
        // move every item bigger than target, to the right.
        // by replacing item at(j) with previous item -> array at(j-1)
        array[j] =  array[j-1];
        j--;
    }
    // when no items are biger than it any more, put target in the empty space
    // empty space exists because we moved all bigger elements to the right
    array[j] =  target;
}

// selection sort, sorts elements one at a time,
// find the smallest of none sorted items of the array,
// and put it at apropriate place
void selection(vector<int>& array)
{
    //cout << "Selection sorting ..."<<endl;
    for(size_t i = 0; i< array.size()-1; i++){
        auto least = i;
        for(size_t j = i+1; j < array.size();j++){
            if(array[j] < array[least]){
                least = j;
            }
        }
        if(i != least){ // no need to swap them if the items are equal -- optimizing
            std::swap(array[i],array[least]);
        }
    }
}

// shuffles a vector so it can be sorted again
void shuffleVector(vector<int>& array) {
    //cout << "shuffling vector..."<<endl;
    size_t size = array.size();
    for (size_t i = 0; i < size; i++)
    {
        const size_t r = random() % size;
        SWAP(array[i], array[r]);

    }
}

// generates a vector of some size
vector<int> generateArray(const size_t size) {

    auto arr = vector<int>();
    // populate array
    for(size_t i = 0; i < size; i++){

        arr.push_back(static_cast<int>(random()% size)+1);
    }
    //
    return arr;
}

void printVector(vector<int>& array) {
    cout <<" = {"<< array[0];
    for(size_t i = 1; i < array.size(); i++){
        cout <<  ", "<<array[i] ;
    }
    cout << " }"<<endl;
}


// testing Inserting sort
// craetes an array of size 8000
// records time stamp,
// sorts array
// records time stamp, and then record duration
// repeat @param repeat times
// return the average duration
unsigned long testInsertion(const int repeat){
    unsigned long duration = 0;
    for(int i = 0; i < repeat; i++) {
        vector<int> arry = generateArray(8000);
        // get start time
        const auto start = std::chrono::high_resolution_clock::now().time_since_epoch();
        // sort array
        loopInsertion(arry);
        // get end time
        const auto end = std::chrono::high_resolution_clock::now().time_since_epoch();
        // difference = duration
        duration+= std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    }
    return duration/repeat;

}

// testing recursive Inserting sort
// craetes an array of size 8000
// records time stamp,
// sorts array
// records time stamp, and then record duration
// repeat @param repeat times
// return the average duration
unsigned long testRecursiveInsertion(const int repeat){


    unsigned long duration = 0;
    for(int i = 0; i < repeat; i++) {
        vector<int> arry = generateArray(8000);
        // get start time
        const auto start = std::chrono::high_resolution_clock::now().time_since_epoch();
        // sort array
        recursiveInsertion(arry, arry.size());
        // get end time
        const auto end = std::chrono::high_resolution_clock::now().time_since_epoch();
        // difference = duration
        duration+= std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    }
    return duration/repeat;

}

// testing selection sort
// craetes an array of size 8000
// records time stamp,
// sorts array
// records time stamp, and then record duration
// repeat @param repeat times
// return the average duration
unsigned long testSelection(const int repeat) {
    unsigned long duration = 0;
    for(int i = 0; i < repeat; i++) {
        vector<int> arry = generateArray(8000);
        // get start time
        const auto start = std::chrono::high_resolution_clock::now().time_since_epoch();
        // sort array
        selection(arry);
        // get end time
        const auto end = std::chrono::high_resolution_clock::now().time_since_epoch();
        // difference = duration
        duration+= std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    }
    return duration/repeat;
}
