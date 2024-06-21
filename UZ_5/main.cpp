//
// Created by tgk on 6/18/24.
//

# include "sort.h"
# include <iostream>
using namespace std;
int main(){

    cout << "Generating array"<<endl;

    // generate array containing 5 elements for demonstration - > array will be shuffled after generation
    vector<int> arr = generateArray(50);
    cout << "Array generated"<<endl;

    // print shuffled array elements
    print(arr);
    cout <<endl << "Sorting array using bubble sort algorithm "<<endl;

    // bubble sort for demonstartion
    bubbleSort(arr);

    // print sorted array
    print(arr);
    cout << endl;

    // test bubble sort by calculating an average time taken to sort an array of size 8000 10 times.
    const auto btime = testBubbleSort(10);
    cout << "Bubble sort took "<<btime <<" Microseconds to complete"<<endl;

    cout <<endl<< "Shuffling array ..." << endl;
    // shuffle array again to demonstrate merge sort
    vShuffle(arr);
    // print shuffled array for demonstration
    print(arr);

    cout <<endl<< "Sorting array using Merge sort algorithm "<<endl;
    // demonstrate merge sort
    mergeSort(arr, 0, arr.size()-1);
    // print sorted array for demonstration
    print(arr);
    cout << endl;

    // test merge sort by calculating an average time taken to sort an array of size 8000 10 times.
    const auto mtime = testMergeSort(10);
    cout << "merge sort took "<< mtime <<" Microseconds to complete" << endl;
    cout << endl << "Merge sort is faster than Bubble sort by " << btime-mtime << " microseconds"<<endl;
    return 0;
}