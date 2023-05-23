#include "mySimplyList.h"
#include "myVector.h"
#include <iostream>

using namespace std;

int main(){
    myVector<int> l1;
    l1.push(3);
    l1.push(2);
    l1.push(1);

    l1.print();
    cout << l1.get(3) << endl;
    return 0;
}