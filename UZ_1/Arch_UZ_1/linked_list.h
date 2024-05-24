//
// Created by tgk on 5/23/24.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
/*
 * Node for singly linked list
 * contains an int and pointer to next node
 */
typedef struct Node{
    int value;
    Node* next;
}Node;

/*
 * linkedList Class implementation of singly linked list
 * class variables ,    size = number of nodes in this list
 *                      head = the first Node
 *                      tail = the last Node
 *
 * Operator [] either gets item at index; can also assign Node.value using list[index] = value this does not change size of list
 *
 * functions            deleteNode(Node* node)-> private , deletes a node and returns pointer to next node
 *                      add(value) adds an Node with given value to the last item
 *                      erase(index) , erases a Node from position -> reduces size
 *                      insert(index,value), inserts Node holding value at given index -> increases size
 *                      removeLast(), removes the last Node in the list -> reduces size
 *                      isEmpty() returns true if list has no nodes
 */
class linkedList {

private:
    unsigned int size_=0;
    Node* head = nullptr;
    Node* tail = head;

    // deletes a node
    Node* deleteNode(Node* node);

public:
    // destructor
    ~linkedList();

    // appends a Node to last Node
    // increases size
    void add(int value);

    // erases node from index and resets node links
    // reduces size
    void erase(unsigned int index);

    // inserts a Node at index
    // increases size
    void insert(unsigned int index, int value);

    // returns list size
    unsigned int size() const;

    // prints list contents
    void print();

    // index operator
    int& operator[](unsigned int index);

    // removes last node from list
    void removeLast();

    // is list empty?
    bool isEmpty() const;

};


#endif //LINKED_LIST_H
