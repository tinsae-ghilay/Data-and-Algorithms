//
// Created by tgk on 6/12/24.
//

#include "sort.h"
//#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

// insertion sort loop
void Sort::loopInsertion(vector<int>& array) {
    cout << "Insertion sorting ..."<<endl;
    size_t i = 1;
    while (i < array.size()){
        int j = i;
        while (j > 0 && (array[j-1] > array[i])){
            SWAP(array[j], array[j-1]);
            j--;
        }
        array[j] = array[i];
        i++;
    }
}

// insertion sort recursive
void Sort::recursiveInsertion(vector<int>& array) {

}

// selection sort
void Sort::selection(vector<int>& array)
{
    cout << "Selection sorting ..."<<endl;
    for(size_t i = 0; i< array.size()-1; i++){
        auto least = i;
        for(size_t j = i+1; j < array.size();j++){
            if(array[j] < array[least]){
                least = j;
            }
        }
        if(i != least){
            SWAP(array[i],array[least]);
        }
    }
}

// shuffles a vector so it can be sorted again
void Sort::shuffleVector(vector<int>& array) {
    cout << "shuffling vector..."<<endl;
    size_t size = array.size();
    for (size_t i = 0; i < size; i++)
    {
        int r = rand() % size;
        SWAP(array[i], array[r]);

    }
}

// generates a vector of some size
vector<int> Sort::generateArray(size_t size) {
    int begin = 0 - (int)size/2; // so that we have negative and positive numbers
    auto arr = vector<int>();
    for(size_t i = 0; i < size; i++){
        arr.push_back(random()% size);
        begin++;
    }
    // here we have a sorted array;
    // so we shuffle it.
    this->shuffleVector((arr));
    return arr;
}

void Sort::printVector(vector<int>& array) {
    cout <<"Array elements = {"<< array[0];
    for(size_t i = 0; i < array.size(); i++){
        cout <<  ", "<<array[i] ;
    }
    cout << " }"<<endl;
}
