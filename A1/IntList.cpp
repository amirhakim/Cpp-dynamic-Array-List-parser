//
//  IntList.cpp
//  A1
//
//  Created by AMIR HAKIM on 2014-05-11.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#include "IntList.h"
using std::cout;
using std::endl;

IntList::IntList()
{
    first = NULL;
    size=0;
    capacity=0;
    //std::cout << "new list"<<std::endl;
}

IntList::IntList(IntList& Old)
{
    size=Old.size;
    capacity=Old.capacity;
    first= new int[size];
    for (int i=0; i<size; i++) {
        first[i]=Old.first[i];
    }
}

void IntList::operator=(const IntList& Old)
{
    if (this==&Old) return;
    delete[] first;
    size=Old.size;
    capacity=Old.capacity;
    first= new int[size];
    for (int i=0; i<size; i++) {
        first[i]=Old.first[i];
    }
}

ostream& operator<<(ostream& sout,const IntList& Object)
{
    sout<< '(' << Object.size<< ')';
    for (int i=0; i < (Object.size); i++) {
        sout << ' '<< Object.first[i]<< ' ';
    }
    sout<<'\n';
    return sout;
}

IntList::~IntList()
{
    delete[] first;
}


bool IntList::isEmpty()
{
    bool isEmpty=false;
    if (first == NULL) {
        isEmpty=true;
    }
    return isEmpty;
}


bool IntList::inList(int item)
{
    bool inList=false;
    if (first!=NULL) {
        for (int i=0; i<size; i++) {
            
            if(first[i]==item) inList=true;
        }
    }

    return inList;
}


void IntList::addToEnd(int item)
{
    listHandler();
    if(size==0)
    {
        first[0]=item;
    }
    else
    {
       first[size]=item;
    }
    
    size++;
}


void IntList::addAfter(int item,int position)
{
    if (positionValid(position)) {
        listHandler();
        int* temp;
        int sizeAfter = size-position-1;
        temp = new int[sizeAfter];
        for (int i=0; i<sizeAfter; i++) {
            temp[0]=first[i+position+1];
        }
        size++;
    }
}


void IntList::setAt(int item,int position)
{
    if (positionValid(position)) {
        first[position]=item;
    }
    else {cout << "ClassIntList::setAt(error:position not in range)" << endl;}
}


int IntList::getAt(int position)
{
    int x{0};
    if (positionValid(position)) {
        x=first[position];
    }
    else {cout << "ClassIntList::getAt(error:position not in range)" << endl;}
    return x;
}


int IntList::getSize()
{
    return size;
}


int IntList::getCapacity()
{
    return capacity;
}

int IntList::getPointer()
{
    const int& cp= *first;
    return cp;

}

void IntList::listHandler()
{
    if (first==NULL) {
        first=new int[1];
        capacity=1;
    }
    else if ((capacity-2)<=size)
    {
        int* temp=first;
        first=new int[capacity*2];
        for (int i=0; i <= size; i++) {
            first[i]=temp[i];
        }
        delete temp;
        capacity=capacity*2;
    }
    
}

bool IntList::positionValid(int position)
{
    bool valid=false;
    if (position <= size) {
        valid=true;
    }
    return valid;
}