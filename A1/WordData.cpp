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
    sout<<Object.word << " " << Object.lines<<" ";
    
    return sout;
}

bool WordData::compareWordData(WordData & Object)
{
    if (compare(Object.getWP(),Object.getLength())==0)
    {
        addLineNumber(Object.lines.getAt(0));
        return true;
    }
    else
    {
        return false;
    }
}

int WordData::compare(const char* target,int targetLength)
{
    char* targetCopy= new char[targetLength];
    strcpy(targetCopy,target);
    int x=strcmp(targetCopy, word);
    delete[] targetCopy;
    return x;
}

const char* WordData:: getWP()
{
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

void WordData::addLineNumber(int newLine)
{
    if (lines.isEmpty()) {
        lines.addToEnd(newLine);
        incrementFrequency();
        return;
    }
    else if (lines.inList(newLine))
    {
        incrementFrequency();
        return;
    }
    else
    {
        lines.addToEnd(newLine);
        incrementFrequency();
        return;
    }
}

char WordData::getFirstLetter()
{
    char firstLetter=word[0];
    
    return firstLetter;
}
