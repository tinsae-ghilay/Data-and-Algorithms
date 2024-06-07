//
// Created by tgk on 6/6/24.
//

#include "HashTable.h"
#include <cmath>
# include <string>
# include <stdexcept>


// Hash function 1,
// hashes string to unsigned long by multiplying a char by 31 to the position of the char
// returns a size_t cast of the hashed value modulo size
unsigned int HashTable::hash(const string &key)
{
    unsigned long hash = 0;
    for (size_t i = 0; i < key.length(); i++) {
        hash += key[i] * pow(31, i);
    }
    return (unsigned int)hash % this->size_;
}

// constructor
HashTable::HashTable(size_t size)
{
    this->size_ = size;
    this->container = new Pair*[this->size_];
}

// destructor
HashTable::~HashTable(){
    delete[] this->container;
};


// inserts a pair to table from key and value
// if key exists , replace value
// if key is in conflict (same index as an already inserted pair, link it to pair
// if index is empty, put pair at index
void HashTable::insert(const string &key, const string &value)
{
    // index of key from hash function mod size
    size_t index = hash(key);
    auto slot = this->container[index];

    if(slot){ // we have a pair already assigned to index
        // link to available element
        if(slot->key.compare(key) == 0){ // the same key so replace value
            cout << "Replacing value of "<< key <<" with "<< value << endl;
			slot->value = value;//replace value on that key;
		}else{ // new key
		    cout << "Inserting "<< key <<" : "<< value << " Pair at index "<<index<< endl;
		    while(slot->pair){
		        //slot = slot->pair;
		        continue;
		    }
		    // this is a new key to be added
		    try{
		        slot->pair = new Pair{ key,value, nullptr}; // attach it to existing linked list
		        // new item was added,
		        this->count_++;
		    }catch(const bad_alloc& e){
		        cout << "Exception cought : "<<e.what()<<endl;
		    }
		}
    }else{
        // put pair to array
        cout << "Inserting "<< key <<" : "<< value << " Pair at index "<<index<< endl;
        try{
            container[index] = new Pair{ key,value, nullptr};
            // new item added.
            this->count_++;
        }catch(const bad_alloc& e){
            cout << "Exception cought : "<<e.what()<<endl;
        }
    }
}


// print all elements of table
// if table is empty, it prints just open and clse curly braces
void HashTable::print()
{
    std::cout << "Pairs in table: {";
    for(size_t i = 0; i < this->size_; i++){
		auto p = this->container[i];
        // if we have an item, check if there are linked paires under it too
        while(p){
            std::cout <<" ["<< p->key << " : "<< p->value << "]";
            p = p->pair;
        }
    }
    std::cout << " }" << std::endl;
}


// remove an item by key
// if item is not found, returns false and nothing is removed
// if item is found, item is removed, links are reatached if available
// returns true on successful deletion
bool HashTable::remove(const string &key)
{
    cout<< "Removing " << key << " : ";
    auto p = find(key);
    if(!p){ // item is not found
        cout << "Not removed, because it was not found "<<endl;
        return false;
    }
    size_t index = hash(key);
    auto anchor = this->container[index];
    if(anchor->key.compare(p->key) == 0){ // item to remove is the base pair
        // replace base with linked pair
        this->container[index] = p->pair;
        // delete old base
        delete p;
        // item was removed
        this->count_--;
        cout << "Done!"<<endl;
        return true;
    }
    // if item to be deleted is linked to base
    // lets find its link to base and sever it
    auto child = anchor->pair;
    while(child->key.compare(key)){
        anchor = child;
        child = anchor->pair;
    }
    // now that we found the link to be severed
    // we reattach it to the anchor
    anchor->pair = p->pair;
    // delete our unwanted
    delete p;
    // item was removed
    this->count_--;
    cout << "Done!"<<endl;
    return true;
}


// find an item (search);
// return the item if found or null if nothing was found
Pair* HashTable::find(const string &key)
{
    // index of key from hash function mod size
    int index = hash(key);

    auto pair = this->container[index];

    while(pair){                /* value at index is not null */

        if(pair->key.compare(key) == 0){  /* found the key */
            break;
        }
        // if we reach here, key is a duplicate (collision) check next linked key
        pair = pair->pair;
    }
    // if we reach here, means no pair available with that key
    return pair;
}

// getter for size
size_t HashTable::size()
{
    return this->size_;
}

// getter for number of pairs in table
size_t HashTable::count()
{
    return this->count_;
}
