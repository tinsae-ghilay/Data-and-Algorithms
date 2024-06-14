//
// Created by tgk on 6/12/24.
//
# include "sort.h"
# include <iostream>

using namespace std;




int main(){

    // size of array
    constexpr  int size = 50;

    // Suffled array to be sorted for demonstration
    auto arr = generateArray(size);

    cout << "********************************  STARTING TASK ONE *********************************************"<<endl << endl;
    // time stamps
    cout << "__ Recursive insertion sorting __"<<endl;
    // recursive insertion sort
    // this doesnt have much of a differece from loop insertion sort.
    // a bit slower than loop verson of insertion sort, probably because of stack unwinding
    // because we are using the improved version (moving bigger elemnts to the right and putting target element at the apropriate position instead of ewaping it with each item)
    // this algorithm is still faster than selection sort, by ~ 2x.
    const auto recursiveIns = testRecursiveInsertion(10);
    cout<<endl << "Recursive insertion took "<<recursiveIns << " microseconds"<<endl;
    // shuffle vector for another sorting round
    cout <<"Shuffled array";
    // print shuffled vector
    printVector(arr);
    cout << "Sorting using recursive insertion ..."<<endl<<"Sorted array";
    // recursive insertion sorting
    recursiveInsertion(arr,arr.size());
    // print sorted vector
    printVector(arr);

    cout <<endl<< "__ loop insertion sorting __" << endl;
    // loop insertion sort
    // insertion sort, the original algorithm (using swaping) involves more copying and thus was slower than selection sort.
    // the improved algorithm cuts this to more than half, so insertion sort became ~ 2x faster than selection sort
    const auto loopIns = testInsertion(10);
    cout<<endl << "Loop insertion took "<<loopIns << " microseconds"<<endl;
    // shuffle array again for another sorting
    cout << "shuffling array ..."<<endl<< "Shuffled array";
    shuffleVector(arr);
    // print shuffled vector
    printVector(arr);
    cout << "loop insertion sorting ..."<<endl << "Sorted array";
    // loop insertion sorting
    loopInsertion(arr);
    // print sorted vector
    printVector(arr);


    cout << endl << "********************************  STARTING TASK TWO *********************************************"<<endl << endl;
    //
    cout << "__ Selection sorting __"<<endl;
    // selection sort
    // selection sort has to compare more items. although it has to copy only once per itteration
    // copying happens only once per outer iteration;
    // it is slowwer than the improved version of insertion sorting, but a bit faster than the original insertion sorting.
    const auto sel = testSelection(10);
    cout <<endl<< "Selection sort took "<<sel <<" microseconds"<<endl;
    // shuffle array again for another sorting
    cout << "Shuffling array ..."<<endl<<"Shuffled array";
    shuffleVector(arr);
    // print shuffled vector
    printVector(arr);
    // selection sort
    cout << "Selection sorting ..."<<endl<<"Sorted array";
    selection(arr);
    // print vector
    printVector(arr);


}
