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
using std::ostream;

class IntList{
public:
    IntList();
    IntList(IntList&);
    ~IntList();
    void operator=(const IntList&);
    friend ostream& operator<<(ostream& sout,const IntList&);
    bool isEmpty();
    bool inList(int item);
    void addToEnd(int item);
    void addAfter(int item,int position);
    void setAt(int item,int position);
    int getAt(int position);
    int getSize();
    int getCapacity();
    bool positionValid(int position);
    int getPointer();
    
private:
    int size;
    int capacity;
    int* first;
    void listHandler();
    
};

#endif /* defined(__A1__IntList__) */
