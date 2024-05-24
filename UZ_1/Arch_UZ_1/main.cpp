//
// Created by tgk on 5/24/24.
//

# include "linked_list.h"
# include "dynamic_array.h"
# include <iostream>


using namespace std;

// test simulation for linked list
void testLinkedList(){
    cout <<endl<<"-- TESTING SINGLY LINKED LIST --"<<endl;
    // 1.Create a singly linked list
    linkedList list;
    // 2.Print out all the elements of the list and its size
    list.print();
    // 3.Add 17 as last element then print out all the elements of the list and its size
    list.add(17);
    list.print();
    cout <<"List has now "<<list.size()<<" elements after add(17)"<<endl;
    // 4.Add 28 as last element then print out all the elements of the list and its size
    list.add(28);
    list.print();
    cout <<"List has now "<<list.size()<<" elements after add(28)"<<endl;
    // 5.Add 1 as first element then print out all the elements of the list and its size
    list.insert(0,1);
    // 6.Add at position 1 the element with value -100 (NOTE: position 1 is the FIRST element!)
    list.insert(1,-100);
    // then print out all the elements of the list and its size
    list.print();
    cout <<"List has now "<<list.size()<<" elements after list[0] = 1 and list.insert(1,-100)"<<endl;
    // 7.Insert element with value 100 at position 100 then print out all the elements of the list and its size
    list.insert(100,100);
    list.print();
    cout <<"List has now "<<list.size()<<" elements after trying list.insert(100,100)"<<endl;
    // 8.Add 3800 as last element then print out all the elements of the list and its size
    list.add(3800);
    // 9.Add at position 2 the element with value 2222 (NOTE: position 1 is the FIRST element!)
    list.insert(1, 22222);
    // then print out all the elements of the list and its size
    list.print();
    cout <<"List has now "<<list.size()<<" elements after list.add(3800) and list[1] = 22222"<<endl;
    // 10. Add at position 4 the element with value 4444 (NOTE: position 1 is the FIRST element!)
    list.insert(3,4444);
    // then print out all the elements of the list and its size
    list.print();
    cout <<"List has now "<<list.size()<<" elements after list.insert(3,4444)"<<endl;
    // 11. Remove the first element then print out all the elements of the list and its size
    list.erase(0);
    list.print();
    cout <<"List has now "<<list.size()<<" elements after erasing first element"<<endl;
    // 12. Remove the first element then print out all the elements of the list and its size
    list.erase(0);
    list.print();
    cout <<"List has now "<<list.size()<<" elements after erasing first element"<<endl;
    // 13. Remove the last element then print out all the elements of the list and its size
    list.removeLast();
    list.print();
    cout <<"List has now "<<list.size()<<" elements after erasing last element"<<endl;
    // 14. Remove the last element then print out all the elements of the list and its size
    list.removeLast();
    list.print();
    cout <<"List has now "<<list.size()<<" elements after erasing last element"<<endl;
    // 15. Remove the element at location 2 (NOTE: position 1 is the FIRST element!)
    list.erase(1);
    // then print out all the elements of the list and its size
    list.print();
    cout <<"List has now "<<list.size()<<" elements after trying to remove second element"<<endl;
    // 16. Remove the element at location 2 (NOTE: position 1 is the FIRST element!)
    list.erase(1);
    // then print out all the elements of the list and its size
    list.print();
    cout <<"List has now "<<list.size()<<" elements after trying to remove second element"<<endl;
    // 17. Remove the element at location 3 (NOTE: position 1 is the FIRST element!)
    list.erase(3);
    // then print out all the elements of the list and its size
    list.print();
    cout <<"List has now "<<list.size()<<" elements  after trying to remove third element"<<endl;
    list.removeLast();
    // then print out all the elements of the list and its size
    list.print();
    cout <<"List has now "<<list.size()<<" elements  after trying to remove last element"<<endl;
}

// test simulation for dynamic array
void testDynamicArray(){

    cout <<endl<< "-- TESTING DYNAMIC ARRAY --"<<endl;
    // 1. Erstellen Sie ein dynamisches Array
    dynamicArray array;
    // 2. Geben Sie alle Elemente des Arrays und seine Größe aus
    array.print();
    cout << "Array created : Array has now "<<array.size()<<" elements "<<endl;
    // 3. Fügen Sie zwei Elementen mit den Werten 100 und 200 dem Array hinzu
    array.add(100);
    array.add(200);
    // 4. Geben Sie alle Elemente des Arrays und seine Größe aus
    array.print();
    cout << "Elements added : Array has now "<<array.size()<<" elements "<<endl;
    // 5. Fügen den Wert 500 an der Stelle 5 hinzu
    array.insert(5,500);
    // 6. Geben Sie alle Elemente des Arrays und seine Größe aus
    array.print();
    cout << "Tried to add 5 to array at position 5 : Array has now "<<array.size()<<" elements "<<endl;
    // 7. Fügen Sie den Wert 2100 an der Stelle 21 hinzu
    array.insert(21, 2100);
    // 8. Geben Sie alle Elemente des Arrays und seine Größe aus
    array.print();
    cout << "Tried to add 5 to array at position 21"<<array.size()<<" elements "<<endl;
}


int main()
{
    // test linked list
    testLinkedList();
    // test dynamic array
    testDynamicArray();

}