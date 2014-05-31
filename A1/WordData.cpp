//
//  WordData.cpp
//  A1
//
//  Created by AMIR HAKIM on 2014-05-16.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#include "WordData.h"

using std::strlen;
using std::strcpy;
using std::cout;
using std::endl;

WordData::WordData()
{
    IntList lines;
    frequency = 0;
    length = 1;
    word = new char[1];
    *word= '\0';
}

WordData::WordData(const char* newword)
{
    IntList lines;
    frequency=1;
    length = (int)strlen(newword)+1;
    word = new char[length];
    strcpy(word,newword);
    //cout << word << endl;
}

WordData::WordData(const WordData& master)
{
    length = master.length;
    frequency=master.frequency;
    lines=master.lines;
    word = new char[length];
    strcpy(word,master.word);
}

WordData::~WordData()
{
    delete[] word;
}

void WordData::operator=(const WordData& master)
{
    if (this==&master) return;
    delete[] word;
    length = master.length;
    frequency=master.frequency;
    lines=master.lines;
    word = new char[length];
    strcpy(word,master.word);
}


ostream& operator<<(ostream& sout,const WordData& Object)
{
    sout<< "object.word: " <<Object.word<<'\n';
    
    return sout;
}

int WordData::compare(const char* target,int targetLength)
{
    char* targetCopy= new char[targetLength];
    strcpy(targetCopy,target);
    int x=strcmp(targetCopy, word);
    //cout<<"strcmp="<<x<<endl;
    delete[] targetCopy;
    return x;
}

const char* WordData:: getWP()
{
    //cout << word << endl;
    return word;
}

void WordData::incrementFrequency()
{
    frequency++;
}

int WordData::getLength()
{
    return length;
}
