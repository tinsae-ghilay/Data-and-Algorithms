/*
* created by TGK on may 30, 2024 
* for Algorithms and data structures
*/

# ifndef STACK_H
# define STACK_H


typedef struct  Data
{
    int value;
    Data* data;
    
} Data;

class Stack{

private:
    Data* top_ = nullptr;
    int size_ = 0;

public:

    ~Stack();
    // inserts data on to stack
    void push(int data);

    // removes last inserted data from stack 
    // and returns the content (int in this case)
    int pop();

    // returns the last inserted element without deleting it
    int top();

    // returns the size of stack(number of items)
    int size();

    // checks if stack has no items
    bool isEmpty();

    // prints all elements of stack, and its size
    void print();

    // we will not implement is full because our stack is dynamic
};


# endif // STACK_H