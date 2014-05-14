//
//  main.cpp
//  A1
//
//  Created by AMIR HAKIM on 2014-05-10.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#include <iostream>
#include "IntList.h"
using std::cout;
using std::endl;


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    IntList one;
    cout << "is empty?  "<< one.isEmpty() << endl;
    cout << "in list?  "<<one.inList(0)<<endl;
    cout << "size?  " << one.getSize()<<endl;
    cout << "capacity?  "<<one.getCapacity()<<endl;
    for (int i=0; i<one.getSize(); i++) {
        cout << "item@: " << i << " is: " << one.getAt(i)<<endl;
    }
    cout << "adding number 5------------------------"<<endl;
    one.addToEnd(5);
    cout << "is empty?  "<< one.isEmpty() << endl;
    cout << "in list?  "<<one.inList(0)<<endl;
    cout << "size?  " << one.getSize()<<endl;
    cout << "capacity?  "<<one.getCapacity()<<endl;
    for (int i=0; i<one.getSize(); i++) {
        cout << "item@: " << i << " is: " << one.getAt(i)<<endl;
    }
    cout << "adding number 6------------------------"<<endl;
    one.addToEnd(6);
    cout << "is empty?  "<< one.isEmpty() << endl;
    cout << "in list?  "<<one.inList(0)<<endl;
    cout << "size?  " << one.getSize()<<endl;
    cout << "capacity?  "<<one.getCapacity()<<endl;
    cout << "item@: " << 0 << " is: " << one.getAt(0)<<endl;
    
    for (int i=0; i<one.getSize(); i++) {
        cout << "item@: " << i << " is: " << one.getAt(i)<<endl;
    }
    cout << "adding number 7------------------------"<<endl;
    one.addToEnd(7);
    cout << "is empty?  "<< one.isEmpty() << endl;
    cout << "in list?  "<<one.inList(5)<<endl;
    cout << "size?  " << one.getSize()<<endl;
    cout << "capacity?  "<<one.getCapacity()<<endl;
    cout << "item@: " << 0 << " is: " << one.getAt(0)<<endl;
    
    for (int i=0; i<one.getSize(); i++) {
        cout << "item@: " << i << " is: " << one.getAt(i)<<endl;
    }
    
    
    
    return 0;
}

