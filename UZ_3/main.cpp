//
// Created by tgk on 6/6/24.
//

# include <iostream>
# include "HashTable.h"
# include "sHashTable.h"


using namespace std;
int main(){
    auto table = sHashTable(10);

    table.insert("06708609081", "Tinsae");
    cout << "Table size "<< table.size()<<" and count "<< table.count() << endl;
    table.insert("06704545293", "Natsinet");
    table.insert("068860220", "Tafla");
    cout << "Table size "<< table.size()<<" and count "<< table.count() << endl;
    table.print();
    table.insert("06708609081", "Ghilay");
    table.insert("0", "Berhe");
    cout << "Table size "<< table.size()<<" and count "<< table.count() << endl;
    table.print();
    auto p = table.find("0");
    if(p) std::cout <<"Found ["<< p->key << " : "<< p->value << "]"<<endl;
    table.remove("0");
    table.print();
    table.remove("06708609081");
    table.remove("068860220");
    table.remove("0688");
    table.remove("06704545293");
    cout << "Table size "<< table.size()<<" and count "<< table.count() << endl;
    table.print();

}