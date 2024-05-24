/*
 * Created by tgk on 5/22/24.
 *
 * Array is dynamic such that we can append as many items as we like with the add() function
 * Array is also dynamic, such that we can insert as many elements as we like at any index if index is not out of bound
 * e.g. if size of array is 8, we can add an item and size will be 9;
 * we can insert item at indices 0 - 7, but not at 8 50 ... etc., even 42. insertion increases size and shifts items to the right of index
 * internally capacity starts at 10 and increases by 10 everytime the resize() function is called.
*/
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H


class dynamicArray {

private:

    // size of this objects
    unsigned int size_ = 0;
    // size of container array
    unsigned int capacity = 10;
    // container array
    int* container = new int[10];

    // increases container size by 10
    // better, instead of doing that on every add() call.
    void resize();


    // returns true if size == capacity
    bool is_full() const;

public:

    // destructor
    ~dynamicArray();

    // prints the array
    // can also be done by overloading the << operator.
    void print() const;

    // adds an item at the end of array
    void add(int item);

    // insert item at an index
    // shift items after index -> to the right
    // increase size by 1; --ATTENTION-- increment size and not capacity unless container is full
    void insert(unsigned int index, int value);

    // get item at given index
    int at(unsigned int index);

    // getter
    unsigned int size() const;

    // index operator
    // returns lvalue (reference) to element
    int& operator[](unsigned int index);

    // erases an item from an index
    // shifts items to fill gap, if there is one
    void erase(unsigned int index);

    // clears all elements of the container
    // sets size to 0;
    void clear();


    // returns true if size of array = 0;
    bool is_empty() const;
};


#endif //DYNAMIC_ARRAY_H
