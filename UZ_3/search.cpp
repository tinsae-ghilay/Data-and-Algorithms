//
// Created by tgk on 6/8/24.
//

#include "search.h"
#include <chrono>
# include <iostream>

Search::Search()
{
    for(int i = 0; i < SIZE; i++){
        this->arr[i] = i;
    }
}

unsigned long Search::binarySearch(int item)
{
    auto start = std::chrono::high_resolution_clock::now().time_since_epoch();
    int low = 0;
    int high = SIZE-1;
    int mid = high/2;
    int found = this->arr[mid];
    while(found != item){
        // we search above
        if(item > found){
            low = mid;
        }else{
            high = mid;
        }
        mid = (low+high) / 2;
        found = this->arr[mid-1];
    }
    auto end = std::chrono::high_resolution_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

}

unsigned long Search::linearSearch(int item)
{
    auto start = std::chrono::high_resolution_clock::now().time_since_epoch();
    for(int i = 0; i < SIZE; i++){
        if(arr[i] == item){
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
}