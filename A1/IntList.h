//
//  IntList.h
//  A1
//
//  Created by AMIR HAKIM on 2014-05-11.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#ifndef __A1__IntList__
#define __A1__IntList__

#include <iostream>

class IntList{
public:
    IntList();
    ~IntList();
    bool isEmpty();
    bool inList();
    void addToEnd(int item);
    void addAfter(int item,int position);
    void setAt(int item,int position);
    int getAt(int position);
    int getSize();
    int getCapacity();
    
public:
    int size;
    int capacity;
    int* first;
    const int* cfirst;
private:
    void listHandler();
    
};

#endif /* defined(__A1__IntList__) */
