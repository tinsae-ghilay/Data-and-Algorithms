//
// Created by tgk on 6/6/24.
// for Algorithms and data structures
//

#ifndef HASHTABLE_H
#define HASHTABLE_H
# include <string>
# include <iostream>


using namespace  std;

// pair of key and value

typedef struct Pair{
    string key;
    string value;
    Pair* pair;
}pair;

inline std::ostream& operator <<(std::ostream& os, Pair& pair){
    return os << " ["<< pair.key <<" : " <<pair.value<<"]";
}
class HashTable {

    private:
    // number of items
    size_t count_ = 0;
    size_t size_ = 0;
    // array container for elements
    Pair **container;
    // my hash function
    protected:
    virtual size_t hash(const string& key);


    public:
    // constructor
    HashTable(size_t size);
    ~HashTable();
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


class HashTableOne : public HashTable {

    using HashTable::HashTable;
    // my hash function
    size_t hash(const string& key) override;
};

class HashTableTwo : public HashTable {
    
    using HashTable::HashTable;
    // my hash function
    size_t hash(const string& key) override;

};

#endif //HASHTABLE_H