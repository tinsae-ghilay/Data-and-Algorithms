//
// Created by tgk on 6/12/24.
//
# include "sort.h"
# include <iostream>

using namespace std;




int main(){

    // size of array
    constexpr  int size = 50;

    // Suffled array to be sorted
    auto arr = generateArray(size);
    // time stamps
    // loop insertion sort
    // insertion sort has to copy more times but compare less.
    // but compying takes more time than comparing ints
    // hence slower than slection sort. but faster than recursive insertion sort
    const auto loopIns = testInsertion(10);
    cout<<endl << "Loop insertion took "<<loopIns << " microseconds"<<endl;
    // print shuffled vector
    cout << "shuffling array ..."<<endl<< "Shuffled array";
    printVector(arr);
    cout << "loop insertion sorting ..."<<endl << "Sorted array";
    // recursive insertion sorting
    loopInsertion(arr);
    // print sorted vector
    printVector(arr);

    // recursive insertion sort
    // this doesnt have much of a differece from loop insertion sort.
    // a bit slower than loop verson of insertion sort, probably because of stack unwinding
    // Slower than selection sort in this case too
    const auto recursiveIns = testRecursiveInsertion(10);
    cout<<endl << "Recursive insertion took "<<recursiveIns << " microseconds"<<endl;
    // shuffle vector for another sorting round
    cout << "Shuffling array ..."<<endl<<"Shuffled array";
    shuffleVector(arr);
    // print shuffled vector
    printVector(arr);
    cout << "Sorting using recursive insertion ..."<<endl<<"Sorted array";
    // recursive insertion sorting
    recursiveInsertion(arr,arr.size());
    // print sorted vector
    printVector(arr);
    // selection sort
    // selection sort is faster beacuse, althoough it has to compare more items,
    // copying hapens only once per outer iteration;
    // and since data here is int, which makes  comparing a faster task than copying a byte
    const auto sel = testSelection(10);
    cout <<endl<< "Selection sort took "<<sel <<" microseconds"<<endl;
    // shuffle array again for another sorting
    cout << "Shuffling array ..."<<endl<<"Shuffled array";
    shuffleVector(arr);
    // print vector
    printVector(arr);
    // selection sort
    cout << "Selection sorting ..."<<endl<<"Sorted array";
    selection(arr);
    // print vector
    printVector(arr);


}
