#include "mySimplyList.h"
#include "myVector.h"
#include <iostream>

using namespace std;

int main(){
    myVector<int> v1;
    v1.push(1);
    v1.push(2);
    v1.push(3);

    v1.print();
    cout << v1.find(2) << endl;

    List<int> l1;
    l1.insertHead(3);
    l1.insertHead(2);
    l1.insertHead(1);

    l1.print();
    cout << l1.find(2) << endl;
    return 0;
}