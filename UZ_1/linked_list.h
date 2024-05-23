//
// Created by tgk on 5/23/24.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node{
    int value;
    Node* next;
}Node;

class linkedList {

private:
    unsigned int size_=0;
    Node* head = nullptr;
    Node* tail;
    Node* deleteNode(Node* node);

public:
    ~linkedList();
    void add(int value);
    void erase(unsigned int index);
    void insert(unsigned int index, int value);
    unsigned int size() const;
    void print();

};


#endif //LINKED_LIST_H
