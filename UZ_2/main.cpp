
# include "stack.h"
# include <iostream>

#include "binary.h"
using namespace std;

void testStack(){
    cout << "------- TESTING STACK -------"<<endl;
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
    cout << "------- TESTING TREE -------"<<endl;;
    //1. Erstellen Sie ein Binärbaum
    BinaryTree t;
    BinaryTree* r = nullptr;
    //2. Drucken Sie alle Elemente des Baums und seine Größe aus
    t.inOrder(r);
    cout << "Size of Tree = "<<t.size()<<" and depth = "<< t.depth(r)<<endl;
    //3. Fügen Sie die Elemente 7, 5, 3, 15, 13, 17, 12, 14, 16, 19 in genau dieser Reihenfolge zum Baum hinzu
    cout << "Insert ... [";
    int ints[] = {5, 3, 15, 13, 17, 12, 14, 16, 19};
    r= t.insert(r,7);
    for(int i: ints) {
        t.insert(r,i);
    }
    cout <<"]"<<endl;
    //4. Drucken Sie die Elemente des Baumes in der pre-order Reihenfolge aus
    cout <<"Pre  order [";
    t.preOrder(r);
    cout <<"]"<< endl;
    cout << "Size of Tree = "<<t.size()<<" and depth = "<< t.depth(r)<<endl;
    //5. Entfernen Sie Element 7
    t.remove(r,7);
    //6. Drucken Sie die Elemente des Baumes in der pre-order Reihenfolge aus
    cout <<"Pre  order [";
    t.preOrder(r);
    cout << "]"<<endl;
    cout << "Size of Tree = "<<t.size()<<" and depth = "<< t.depth(r)<<endl;
    //7. Entfernen Sie Element 17
    t.remove(r,17);
    //8. Drucken Sie die Elemente des Baumes in der pre-order Reihenfolge aus
    cout <<"Pre  order [";
    t.preOrder(r);
    cout <<"]"<< endl;
    cout << "Size of Tree = "<<t.size()<<" and depth = "<< t.depth(r)<<endl;
    //9. Entfernen Sie Element 15
    t.remove(r,15);
    //10. Drucken Sie die Elemente des Baumes in der pre-order Reihenfolge aus
    cout <<"Pre  order [";
    t.preOrder(r);
    cout <<"]"<< endl;
    cout << "Size of Tree = "<<t.size()<<" and depth = "<< t.depth(r)<<endl;
    //11. Drucken Sie die Elemente des Baumes in der post-order Reihenfolge aus
    cout <<"Post order [";
    t.postOrder(r);
    cout <<"]"<< endl;
    cout << "Size of Tree = "<<t.size()<<" and depth = "<< t.depth(r)<<endl;
    //12. Drucken Sie die Elemente des Baumes in der in-order Reihenfolge aus
    cout <<"In   order [";
    t.inOrder(r);
    cout <<"]"<< endl;
    cout << "Size of Tree = "<<t.size()<<" and depth = "<< t.depth(r)<<endl;
    int val = 16;
    auto fnd = t.find(r,val);
    fnd? cout <<"Found "<<val<<endl:cout <<"";
    val = 1;
    fnd = t.find(r,val);
    fnd? cout <<"Found "<<val<<endl:cout <<"";
    val = 14;
    fnd = t.find(r,val);
    fnd? cout <<"Found "<<val<<endl:cout <<"";
}

int main(){
    testStack();
    testTree();
    cout << "Task done, Thankyou!" <<endl;
    return 0;
}