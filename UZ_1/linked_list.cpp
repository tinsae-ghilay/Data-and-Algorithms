//
// Created by tgk on 5/23/24.
//

#include "linked_list.h"
# include <iostream>

using namespace std;

// destructor clears items
linkedList::~linkedList()
{
    auto node = deleteNode(this->head);
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
    // iterate from head to reach index
    auto node = head;
    unsigned int i = 1;
    while (i < index) {
        node = node->next;
        i++;
    }
    // once we are at the node priore the one to be deleted
    // we delete the item at index and return it's next node
    auto tmp = this->deleteNode(node->next);
    // we set next node of deleted node to prior node
    node->next = tmp;
    // and we reduce size
    this->size_--;
}
void linkedList::insert(unsigned int index, int value)
{
    if(this->size_< index){                                                            // index is beyond bounds

        cout << "trying to add an item that cannot be linked because list has currently "<< this->size_ << " items"<< endl;

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
