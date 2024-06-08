//
// Created by tgk on 6/6/24.
//

# include <iostream>
# include "HashTable.h"
# include "sHashTable.h"
# include "pair.h"
# include "search.h"


using namespace std;
int main(){

    // 1. Erstellen Sie eine Hash-Tabelle mit einer Hash-Funktion
    cout << "--- TABLE WITH HASHING FUNCTION ONE ---" <<endl<<endl;
    auto t1 = sHashTable(5); // hash table with hash finction one (FNV hash function);
    // 2. Fügen Sie 5 Einträge in die Tabelle ein
    t1.insert("0676-425-83-47", "Alex");
    t1.insert("0688-625-47-33", "Alexa");
    t1.insert("0681 517 60 26", "Hofer") ;
    t1.insert("0676 108 68 78", "Andre");
    t1.insert("0699 837 79 90", "Christian");

    // 3. Drucken Sie die Tabelle aus (sowohl Schlüssel und Werte)
    t1.print();
    cout << "Table one size "<< t1.size()<<" and count "<< t1.count() << endl;
    // 4. Erstellen Sie eine weitere Hash-Tabelle mit einer anderen Hash-Funktion
    auto t2 = HashTable(5); // hashTable with hash function that adds char multiplied by 31 to the char index
    cout <<endl<< "--- TABLE WITH HASHING FUNCTION TWO ---" <<endl;
    // 5. Fügen SIe 5 Einträge in die Tabelle ein
    t2.insert("0676-425-83-47", "Alex");
    t2.insert("0688-625-47-33", "Alexa");
    t2.insert("06815176026", "Hofer") ;
    t2.insert("0676 108 68 78", "Andre");
    t2.insert("0699 837 79 90", "Christian");
    // 6. Drucken Sie die Tabelle aus (sowohl Schlüssel als auch Werte)
    t2.print();
    cout << "Table two size "<< t2.size()<<" and count "<< t2.count() << endl;
    // 7. Suchen Sie nach einem bestimmten Element in der Tabelle und drucken Sie den ganzen
    // Eintrag (d.h. das key-value Paar), wenn das Element gefunden wird
	string k = "0681 517 60 26";
	cout << "searching for "<<k<< " in table one "<< endl;
    auto p1 = t1.find(k); // from table 1
    (p1)? cout <<"Found "<< *p1<<endl: cout <<"Nothing was found" <<endl;
	k = "0680 993 12 22";
	cout << "searching for "<<k<< " in table two "<< endl;
    auto p2 = t2.find(k); // none existing
    (p2)? cout <<"Found "<< *p2<<endl: cout <<"Nothing was found"<<endl;
    // 8. Löschen Sie ein Element in der Tabelle und drucken Sie die Tabelle (sowohl Schlüssel als
    // auch Werte) aus
    t1.remove("0676-425-83-47");
    t2.remove("0676 108 68 78");
    // 9. Löschen Sie ein Element in der Tabelle und drucken Sie die Tabelle (sowohl Schlüssel als
    // auch Werte) aus
    t1.remove("0676 108 68 78");
    t2.remove("0699 837 79 90");
    cout << "Table two size "<< t2.size()<<" and count "<< t2.count() << endl;
    cout << "Table one size "<< t1.size()<<" and count "<< t1.count() << endl <<endl;
    Search s;
    int needle = 753;
    u_int64_t sLin = 0;
    cout <<endl << " COMPARING LINEAR AND BINARY SEARCH ALGORITHMS " << endl<< endl;
    for(int i = 0; i< 10; i++){
        sLin+= s.linearSearch(needle);
    }
    sLin = sLin/10;
    u_int64_t sBin = 0;
    for(int i = 0; i< 10; i++){
        sBin+= s.binarySearch(needle);
    }
    sBin = sBin/10;

    cout << "Linear search took :"<<sLin<<" microseconds"<<endl;
    cout << "Binary search took :"<<sBin<<" microseconds"<<endl;
    cout << "*** ALL DONE, Thankyou!! *** "<<endl;

    

}