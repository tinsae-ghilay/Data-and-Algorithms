//
// Created by tgk on 6/18/24.
//
# include "sort.h"
# include <iostream>
# include <random>
# include <chrono>


// fills an array of a given size
// with numbers from 0 -> size-1
// elements shuffled using vShuffle() function
vector<int> generateArray(const int size) {

    // declare vector
    auto arr = vector<int>();
    // fill it with numbers
    for(int i = 0; i < size; i++) {
        arr.push_back(i);
    }
    cout << "Array generated"<<endl;
    // shuffle it
    vShuffle(arr);
    // return it
    return arr;
}


// shuffles array so that it can be sorted again
// uses std::shuffle
void vShuffle(vector<int>& array) {
    auto device = random_device {};
    auto rng = std::default_random_engine {device()};
    cout << "Shuffling array ..."<<endl;
    ranges::shuffle(std::begin(array), std::end(array), rng);
}

// bubble sort
// uses the bubble sort algorithm to sort items
// items get sorted in escending order
void bubbleSort(vector<int>& array)
{
    bool swaped = true;
    size_t limit = array.size()-1;
    // normally here limit would be checked if it reached to 0 or not to finish sorting.
    // but bubble sort can be optimised by watching if items are sorted or not
    // by seting boolean value to true whenever a swap occurs
    // if no swap occurs in one itteration, then it means the array is sorted and we finish sorting
    // thus limitting multiple iteration on an already sorted array.
    while(swaped) {
        // lets set swapped to fales when we begin iterationg throug unsorted part of array
        swaped = false;
        for(size_t i = 0; i < limit; i++) {
            // if current item and item after it are in a wrong order
            if(array[i] > array[i+1]) {
                // bubble this item up
                SWAP(array[i],array[i+1]);
                // and make sure we are still swapping and array is not fully sorted yet
                swaped = true;
            }
        }
        limit--;
    }
}

// merges array left and right sorted parts
void merge(vector<int>& arr, const size_t start,const size_t mid, const size_t end)
{
    // we have an array,
    // we have starting , mid, and end indices of our operation
    // first lets keep track of where we are in the big array, i.e. start
    size_t in = start;
    // now lets store elements in temporary arrays
    // left
    auto left = vector<int>();
    // right
    auto right = vector<int>();


    // copy items to left
    // size of left array = mid - start + 1;
    for(size_t i = 0; i < mid-start+1; i++) {
        left.push_back(arr[start+ i]);
    }
    // copy items to right,
    // size of right array = end - mid
    for(size_t i = 0; i < end-mid; i++) {
        right.push_back(arr[mid + 1 + i]);
    }
    // now we compare and put items in their appropriate place in the big array
    // since we are comparing items from two arrays by index,
    // we have to keep track of where we are on the two arrays as well
    // index for left array
    size_t in_left = 0;
    // index for right array
    size_t in_right = 0;
    // Insert items in big array in a sorted order
    // actual sorting happens here
    while (in_left < left.size() && in_right < right.size()) {

        // left is smaller or they are equal?
        if(left[in_left] <= right[in_right])
        {
            // insert left first
            arr[in] = left[in_left];
            in_left++;
        } else { // right is smaller? insert right forst
            arr[in] = right[in_right];
            in_right++;
        }
        in++;
    }
    // if one of the arrays is empty
    // if left is still not completely copied
    while (in_left < left.size())
    {
        // copy elements
        arr[in] = left[in_left];
        in_left++;
        in++;
    }

    // if right isn't completely copied
    while (in_right < right.size())
    {
        // copy them all
        arr[in] = right[in_right];
        in_right++;
        in++;
    }

}
// merge sort
// sorts a given array using merge sort algorithm
// items get sorted in ascending order
void mergeSort(vector<int>& arr, const size_t start, const size_t end) {

    // if we are not deep enough/ part has one or 0 elements
    if(start < end) {
        // variable mid is last index of left array,
        // right array begins at mid +1
        // we set this at lower end of half,
        // so when array contains odd number of elements, eg 11 and start is 10, end = 21,
        // mid is (start + end) / 2 = 15 as we cant have floating pont numbers
        // if odd e.g. 10, start = 10 and end = 20, then mid = (10 + 20)/2 = 15; thus
        const size_t mid = (start + end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr, mid+1,end);
        merge(arr, start,mid,end);
        }

}

// prints arry elements in a formated manner
// array will be printed like below
// Array elements : {1, 2, 3, 4, 5}
void print(const vector<int>& arr) {

    cout << "Array elements : {"<< arr[0];
    for(size_t i = 1; i < arr.size(); i++) {
        cout << ", "<< arr[i];
    }
    cout << "}"<< endl;
}

// tests average time it took to do bubble  sort
// creates an array of size 8000
// records time stamp,
// sorts array
// records time stamp, and then record duration
// repeat @param repeat times
// return the average duration
unsigned long testBubbleSort(const int repeat){


    unsigned long duration = 0;
    for(int i = 0; i < repeat; i++) {
        vector<int> arr = generateArray(8000);
        // get start time
        const auto start = std::chrono::high_resolution_clock::now().time_since_epoch();
        // sort array
        bubbleSort(arr);
        // get end time
        const auto end = std::chrono::high_resolution_clock::now().time_since_epoch();
        // difference = duration
        duration+= std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    }
    return duration/repeat;

}


// runs Merge sort repeatedly on a shuffled array
// after shuffling array, record time -> run sort ->record time after sort
// repeat for @repeat times and then
// return the average duration it takes to sort the shuffled array
unsigned long testMergeSort(const int repeat){
    unsigned long duration = 0;
    for(int i = 0; i < repeat; i++) {
        vector<int> arr = generateArray(8000);
        // get start time
        const auto start = std::chrono::high_resolution_clock::now().time_since_epoch();
        // sort array
        mergeSort(arr, 0, arr.size());
        // get end time
        const auto end = std::chrono::high_resolution_clock::now().time_since_epoch();
        // difference = duration
        duration+= std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    }
    return duration/repeat;
}
