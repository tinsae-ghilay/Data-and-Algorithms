//
// Created by tgk on 6/7/24.
//

#ifndef SHASHTABLE_H
#define SHASHTABLE_H

# include <string>
# include <iostream>
# include "pair.h"

using namespace std;


class sHashTable {
private:
    // number of items
    size_t count_ = 0;
    size_t size_ = 0;
    // array container for elements
    Pair **container;
    // my hash function
    size_t hash(const string& key);


public:
    // constructor
    sHashTable(size_t size);
    ~sHashTable();
    // insert a key value combination
    void insert(const string& key, const string& value);
    // prints all elements
    void print();
    // deletes elemnt by key
    bool remove(const string& key);
    // finds a pair with key
    Pair* find(const string& key);
    // get size(capacity of table)
    size_t size();
    // get number of elements
    size_t count();

};



#endif //SHASHTABLE_H
