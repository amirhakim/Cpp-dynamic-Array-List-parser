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
    
    length = (int)strlen(newword)+1;
    word = new char[length];
    strcpy(word,newword);
}

WordData::WordData(const WordData& Original)
{
    length = Original.length;
    word = new char[length];
    strcpy(word,Original.word);
}

WordData::~WordData()
{
    delete[] word;
}

void WordData::operator=(const WordData& Original)
{
    if (this==&Original) return;
    delete[] word;
    length = Original.length;
    word = new char[length];
    strcpy(word,Original.word);
}


ostream& operator<<(ostream& sout,const WordData& Object)
{
    sout<< "object.word: " <<Object.word<<'\n';
    
    return sout;
}

int WordData::compare(const char* target)
{
    return strcmp(target, word);
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

