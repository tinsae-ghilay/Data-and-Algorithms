//
// Created by tgk on 6/18/24.
//

# include "sort.h"
# include <iostream>
using namespace std;
int main(){

    vector<int> arr = generateArray(50);
    cout << "unsorted array " << endl;
    print(arr);
    bubbleSort(arr);
    cout << "Sorted array "<<endl;
    print(arr);
    vShuffle(arr);
    cout << "unsorted array " << endl;
    print(arr);
    mergeSort(arr, 0, arr.size()-1);
    cout << "Sorted array "<<endl;
    print(arr);

    return 0;
}