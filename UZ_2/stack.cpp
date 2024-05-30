# include "stack.h"
# include <stdexcept>
# include <iostream>


using namespace std;

Stack::~Stack(){

    while(!(this->isEmpty()) && (this->top_->data)){
        auto waste = this->top_;
        this->top_ = waste->data;
        delete waste;
    }

}
// inserts data on to stack
void Stack::push(int data)
{
    if(this->isEmpty()){
        this->top_ = new Data{data, nullptr};
    }else{
        this->top_ = new Data{data,this->top_};
    }
    this->size_++;
    cout <<data <<" Has been pushed on stack"<<endl;
}


// removes last inserted data from stack 
// and returns the content (int in this case)
int Stack::pop()
{ 
    if(!this->isEmpty()){                           /* Stack has items */
        // store int value of top
        int val = top_->value;
        // store top in temp for deletion
        auto tmp = this->top_;
        // transfer to to new top
        this->top_ = this->top_->data;
        // delete old top
        delete tmp;
        // decrease size
        this->size_--;
        // return value of old top
        return val;
    }else{
        throw std::out_of_range("Stack has nothing to pop");
    }
}

// returns the last inserted element without deleting it
int Stack::top()
{
    return this->isEmpty()? 
        throw out_of_range("Stack is empty")
    : this->top_->value;
}

// returns the size of stack(number of items)
int Stack::size()
{
    return this->size_;
}

// checks if stack has no items
bool Stack::isEmpty()
{
    return !this->top_;
}

// prints all elements of stack, and its size
void Stack::print()
{
    cout << "Stack ";
    (this->isEmpty())? cout <<"empty"<<endl: cout<<"size = " <<this->size_ <<endl;
    cout << "Stack Elements = [";
    auto item = this->top_;
    while(item){
        // if item has next, add coma after value.
        item->data? cout << item->value << ", ": cout << item->value;
        // update item to the next one
        item = item->data;
    }
    cout << "]"<<endl;
}
