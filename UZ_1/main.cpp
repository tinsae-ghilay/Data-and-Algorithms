//
// Created by tgk on 5/23/24.
//
# include "dynamic_array.h"
# include "linked_list.h"
# include <iostream>


using namespace std;


int main()
{
    // Array is dynamic such that we can append as many items as we like with the add() function
    // Array is also dynamic, such that we can insert as many elements as we like at any index if index is not out of bound
    // e.g. if size of array is 8, we can add an item and size will be 9;
    // we can insert item at indices 0 - 7, but not at 8 50 ... etc., even 42. insertion increases size and shifts items to the right of index
    // internally capacity starts at 10 and increases by 10 everytime the resize() function is called.
    /*auto arr = dynamicArray();

    cout << "Array before items are added: size = "<<arr.size()<< endl;
    arr.printArray();
    arr.add(100);
    arr.add(20);
    arr.add(500);
    cout << "Array after items added : size = "<< arr.size() << endl;
    arr.printArray();
    for(int i = 1; i <11; i++){
        arr.add(i*20);
    }
    cout << "More items added, and size = " << arr.size() << endl;
    arr.printArray();
    // adding item to array at specific index
    arr[5] = 45;
    cout << "Item at index [5] replaced with 45, and size = " << arr.size() << endl;
    arr.printArray();
    arr.insert(5,42);
    cout << "42 inserted at index 5, and size = " << arr.size() << endl;
    arr.printArray();
    cout <<"Second Item = "<< arr[1] <<", and size is = "<< arr.size() <<endl;
    arr.printArray();
    arr.erase(5);
    cout << "Array after 5th item erased : Size = " << arr.size() << ". >> Is it empty? : "<<((arr.is_empty())?"True":"False") <<endl;
    arr.printArray();

    try{
        arr[20] = 12;
        arr.printArray();
    }catch(out_of_range& e){
        cerr <<"threw "<< e.what() << " Trying to set 20th item with '[]' operator : "<<endl;
    }

    try{
        arr.insert(20,12);
        arr.printArray();
    }catch(out_of_range& e){
        cerr <<"threw "<< e.what() << " Trying to set 20th item  with 'insert(index, value)' function: "<<endl;
    }


    arr.clear();
    cout <<"Array after being cleared: size = " <<arr.size() <<". >> Is it empty? : "<<((arr.is_empty())?"True":"False") <<endl;
    arr.printArray();*/

    auto list = linkedList();

    cout<<"testing ..."<<endl;
    list.print();
    cout << "Size of list = "<< list.size()<<endl;
    list.add(42);
    list.print();
    cout << "Size of list = "<< list.size()<<endl;
    list.add(100);
    list.add(500);
    list.print();
    cout << "Size of list = "<< list.size()<<endl;
    list.erase(2);
    cout << "erased one, and Size of list = "<< list.size()<<endl;
    list.print();
    list.insert(2,900);
    list.print();
    cout << "Size of list after insert= "<< list.size()<<endl;
    list.insert(2,300);
    list.print();
    cout << "Size of list after insert= "<< list.size()<<endl;
    list.insert(9,900);
    list.print();
    cout << "Size of list after insert= "<< list.size()<<endl;
    return 0;
}