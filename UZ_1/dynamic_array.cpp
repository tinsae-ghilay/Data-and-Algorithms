//
// Created by tgk on 5/22/24.
//

#include "dynamic_array.h"
# include <iostream>
# include <string>
# include <stdexcept>


using namespace std;
dynamicArray::~dynamicArray()
{
    // delete container / avoid leak
    delete[] this->container;
}

// resizes the container by 10
void dynamicArray::resize()
{
    // increase capacity by 10
    this->capacity+= 10;

    // temporary array to hold container contents
    int* temp = this->container;

    // reassign container to a bigger array
    this->container = new int[this->capacity];

    // copy contents from old array to new one
    for(unsigned int i = 0; i < this->size_; i++){
        this->container[i] = temp[i];
    }
    //delete old
    delete[] temp;
}


// gets an item at specified index
// this function is private, for internal use
int dynamicArray::at(unsigned int index)
{
    if(index < this->size_){ // index is valid
        return this->container[index];
    }else{ // index doesnt have value or doesnt exist
        throw out_of_range("Index out of bounds Exception");
    }
}

// prints the array contents e.g. result would look like below
// Dynamic array = [1, 2, 3, 4]
void dynamicArray::printArray() const
{
    cout << "Dynamic array = [";
    for (unsigned int i = 0; i < this->size_; ++i) {
        string item = (i==0)? to_string(this->container[i]) : ", "+ to_string(this->container[i]);
        cout << item;
    }
    cout << "]" << endl;
}

// appends an item to the end of the array
// size will be increased here
// capacity will be increased if container is already full.
void dynamicArray::add(int item)
{
    if(this->size_ >= this->capacity){                                                        // container already full
        // resize container
        this->resize();
    }
    // add item at last index
    this->container[this->size_] = item;
    // increase size by 1
    this->size_++;
}

// insert item at an index
// shift items after index -> to the right
// increase size by 1; --ATTENTION-- increment size and not capacity unless container is full
void dynamicArray::insert(unsigned int index, int value)
{
    if(this->is_full()){                                                                     // full capacity reached
        this->resize();
    }
    if(index >= this->size_){                                                               // out of bound
        throw out_of_range("Index out of bounds exception");
    }

    this->size_++;
    // if all is well, insert item and
    // shift items after insertion index
    for(auto i = index; i < this->size_+1; i++){

        // temp variable to hold item at index
        auto item = this->container[i];

        // replace index value with parameter value
        this->container[i] = value;
        // reset value with temp
        value = item;
    }
}


// getter for size variable
unsigned int dynamicArray::size() const {
    return  this->size_;
}

// get the lvalue to assign or access its rvalue
// source the internet
int& dynamicArray::operator[](unsigned int index)
{
    if (index >= this->size_) {                                                             // out of bound
        throw out_of_range("Index out of bounds exception");
    }
    // valid index
    return this->container[index];
}

// erases an item by index
void dynamicArray::erase(unsigned int index)
{
    if(index < this->size()){                                                               // index is valid

        // move everything in place;
        while (index < this->size_-1){
            this->container[index] = this->container[index+1];
            index++;
        }
        // reduce size after removing item
        this->size_--;
    }
}

// clear all elements from container
// sets size to 0; and container capacity to 0
void dynamicArray::clear(){

    // temp array to hold old container items
    // to be able to delete old array
    auto tmp = this->container;

    // new container of size 0
    this->container = new int[0];
    // set size to 0
    this->size_ = 0;
    // delete old container;
    delete[] tmp;
}

// is container full?
bool dynamicArray::is_full()const {
    return this->size_ == this->capacity;
}

// is container empty?
bool dynamicArray::is_empty() const {
    return this->size_ == 0;
}



