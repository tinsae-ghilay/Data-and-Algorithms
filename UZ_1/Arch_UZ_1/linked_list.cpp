//
// Created by tgk on 5/23/24.
//

#include "linked_list.h"
# include <iostream>

using namespace std;

// destructor clears items
linkedList::~linkedList()
{
    auto node = this->head;
    while(node){
        node = this->deleteNode(node);
    }
}

// deletes a node
// this is private and should not be accessed from outside
// returns a pointer to the next node
Node* linkedList::deleteNode(Node* node){
    // pointer to next node to be returned
    Node* tkn = node->next;
    // delete the node
    delete node;
    // return the next node
    return tkn;
}


// appends a new node to the end of the list
void linkedList::add(int value)
{
    // new node from parameter
    Node* current = new Node{value, nullptr};
    // head hasn't been initialised?
    if(!this->head){                                                                    // head is null
        this->head = current;
        this->tail = current;
    }else{                                                                              // head is already initialised
        // efficient way to append item to last position is to hold the last item
        // instead of iteration through all
        this->tail->next = current;
        this->tail = current;
    }
    // size also increases here
    this->size_++;
}
void linkedList::erase(unsigned int index)
{
    if(index >=this->size_ || this->size_ == 0){
        cout << "There is no item to erase at index "<<index << " in this list"<<endl;
        return;
    }
    if(index == 0){

        if(this->size_ != 1){
            this->head = deleteNode(this->head);
        }else{
            delete this->head;
        }
    }else{

        // iterate from head to reach index
        auto node = head;
        //unsigned int i = 1;
        for(unsigned int i = 0;i < index-1; i++){
            node = node->next;
        }
        // once we are at the node priore the one to be deleted
        // we delete the item at index and return it's next node
        node->next = deleteNode(node->next);
        // if this is the last item, assign it to tail;
        if(!node->next){
            this->tail=node;
        }
    }
    // and we reduce size
    this->size_--;
}
void linkedList::insert(unsigned int index, int value)
{
    if(this->size_< index){                                                            // index is beyond bounds
        // exception should be thrown here, but I don't want the program to exit
        // so just print message out. and that is that.
        cout << "Trying to add an item at index "<<index<<" cannot be linked because list has currently "<< this->size_ << " items"<< endl;

    }else if(index == 0){                                                               // index is 0?

        auto node = new Node{value, this->head};
        this->head = node;
        this->size_++;

    }else{
        auto current = this->head;

        // lets get the node at index-1
        for(unsigned int i = 1; i < index; i++){
            current = current->next;
        }
        // holder for next node of current
        auto node = current->next;

        // set next of current, and set its next = old next of current node
        current->next =new Node {value,node};
        // increase size
        this->size_++;
    }
}

// prints lis content with arrow separating them
// will look like "List = [1 -> 2 -> 3 -> 4] asn an example
void linkedList::print() {
    cout << "List = [";
    auto node = this->head;
    if(node){
        cout<<node->value;
        node = node->next;
    }
    while(node){
        cout << " -> "<<node->value;
        node = node->next;
    }
    cout <<"]"<<endl;
}

unsigned int linkedList::size() const {
    return this->size_;
}


// overloading index operator
int& linkedList::operator[](unsigned int index) {
    if(index >= this->size_){                                                       // out of bounds
        // exception should be thrown here, but I don't want the program to exit
        // so just print message out. and that is that.
        cout << "Index out of bounds "<< this->size_ << " items"<< endl;
    }
    auto node = this->head;
    for(size_t i = 0; i < index; i++ ){
        node = node->next;
    }
    return node->value;
}

// removes last item if there is one
void linkedList::removeLast() {
    if(this->size_ == 0){                                                           // list contains 0 elements
        cout << "list doesn't have items to delete";
    }
    auto node = this->head;
    if(this->size_ == 1){                                                           // we only have one item?

        // head and tail set to null
        this->head = nullptr;
        this->tail = nullptr;
        // delete node
        delete node;
    }else{
        for(unsigned int i = 1; i < this->size_-1; i++){
            node = node->next;
        }
        auto waste = node->next;
        this->tail = node;
        tail->next = nullptr;
        delete waste;
    }
    this->size_--;
}

bool linkedList::isEmpty() const {
    return this->size_ == 0;
}
