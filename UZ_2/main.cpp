
# include "stack.h"
# include <iostream>
# include "binary.h"

using namespace std;

void testStack(){
    //1. Erstellen Sie ein Stack
    Stack stack;
    //2. Geben Sie alle Elemente des Stacks und ihre Größe aus
    stack.print();
    //3. Fügen Sie Elementen mit den Werten 100, 200 und 300 zum Stack hinzu
    stack.push(100);
    stack.push(200);
    stack.push(300);
    //4. Geben Sie alle Elemente des Stacks und ihre Größe aus
    stack.print();
    //5. Entfernen Sie alle Elemente vom Stapel,
    while(!stack.isEmpty()){
        cout << stack.pop() <<" has been removed from stack"<<endl;
    }
    // und geben Sie nach dem Entfernen eines Elements die verbleibenden Elemente auf dem Stapel und ihre Größe aus
    stack.print();
    //6. Lesen Sie das aktuelle Element auf dem Stack und dann geben Sie es aus
    try{
        cout <<"Trying to get top: " <<stack.top()<< " was found"<<endl;
    }catch(out_of_range& e){
        cout << "Exception: "<<e.what()<<" while trying to get top"<<endl;
    }
    //7. Fügen Sie ein Element mit dem Wert 400 zum Stack hinzu
    stack.push(400);
    //8. Lesen Sie das aktuelle Element auf dem Stack und dann geben Sie es aus
    try{
        cout <<"Trying to get top: " <<stack.top()<< " was found"<<endl;
    }catch(out_of_range& e){
        cout << "Exception: "<<e.what()<<" while trying to get top"<<endl;
    }
    //9. Geben Sie alle Elemente des Stacks und ihre Größe aus
    stack.print();
    //10. Entfernen Sie ein Element vom Stack
    cout << stack.pop() <<" has been removed from stack"<<endl;
    //11. Geben Sie alle Elemente des Stacks und ihre Größe aus
    stack.print();
}
void testTree()
{
    //1. Erstellen Sie ein Binärbaum
    BinaryTree t;
    BinaryTree* r = nullptr;
    //2. Drucken Sie alle Elemente des Baums und seine Größe aus
    t.inOrder(r);
    cout << "Size of Tree = "<<t.size()<<endl;
    //3. Fügen Sie die Elemente 7, 5, 3, 15, 13, 17, 12, 14, 16, 19 in genau dieser Reihenfolge zum Baum hinzu
    cout << "Insert ... [";
    r= t.insert(r,7);
    t.insert(r,5);
    t.insert(r,3);
    t.insert(r,15);
    t.insert(r,13);
    t.insert(r,17);
    t.insert(r,12);
    t.insert(r,14);
    t.insert(r,16);
    t.insert(r,19);
    cout <<"]"<<endl;
    //4. Drucken Sie die Elemente des Baumes in der pre-order Reihenfolge aus
    cout <<"Pre  order [";
    t.preOrder(r);
    cout <<"]"<< endl;
    cout << "Size of Tree = "<<t.size()<<endl;
    //5. Entfernen Sie Element 7
    t.remove(r,7);
    //6. Drucken Sie die Elemente des Baumes in der pre-order Reihenfolge aus
    cout <<"Pre  order [";
    t.preOrder(r);
    cout << "]"<<endl;
    cout << "Size of Tree = "<<t.size()<<endl;
    //7. Entfernen Sie Element 17
    t.remove(r,17);
    //8. Drucken Sie die Elemente des Baumes in der pre-order Reihenfolge aus
    cout <<"Pre  order [";
    t.preOrder(r);
    cout <<"]"<< endl;
    cout << "Size of Tree = "<<t.size()<<endl;
    //9. Entfernen Sie Element 15
    t.remove(r,15);
    t.remove(r, 10);
    //10. Drucken Sie die Elemente des Baumes in der pre-order Reihenfolge aus
    cout <<"Pre  order [";
    t.preOrder(r);
    cout <<"]"<< endl;
    cout << "Size of Tree = "<<t.size()<<endl;
    //11. Drucken Sie die Elemente des Baumes in der post-order Reihenfolge aus
    cout <<"Post order [";
    t.postOrder(r);
    cout <<"]"<< endl;
    cout << "Size of Tree = "<<t.size()<<endl;
    //12. Drucken Sie die Elemente des Baumes in der in-order Reihenfolge aus
    cout <<"In   order [";
    t.inOrder(r);
    cout <<"]"<< endl;
    cout << "Size of Tree = "<<t.size()<<endl;
    int val = 16;
    auto fnd = t.find(r,val);
    fnd? cout <<"found "<<val<<endl:cout << "didn't find "<<val<<endl;
    val = 1;
    fnd = t.find(r,val);
    fnd? cout <<"found "<<val<<endl:cout << "didn't find "<<val<<endl;
    val = 14;
    fnd = t.find(r,val);
    fnd? cout <<"found "<<val<<endl:cout << "didn't find "<<val<<endl;
}


int main(){

    //testStack();
    testTree();
    return 0;
}




