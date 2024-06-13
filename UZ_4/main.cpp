//
// Created by tgk on 6/12/24.
//
# include "sort.h"
# include <iostream>

using namespace std;

int main(){

    Sort sort;

    auto arr = sort.generateArray(10);
    sort.printVector(arr);
    sort.selection(arr);
    sort.printVector(arr);

    sort.shuffleVector(arr);
    sort.printVector(arr);

    sort.loopInsertion(arr);
    sort.printVector(arr);
}