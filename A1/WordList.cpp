//
//  WordList.cpp
//  A1
//
//  Created by AMIR HAKIM on 2014-05-23.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#include "WordList.h"

WordNode::WordNode(char* newWord,WordNode& nextNode)
{
    word= newWord;
    next= &nextNode;
}

WordList::WordList()
{
    head=tail=nullptr;
    listSize=0;
}

WordList::WordList(string& file)
{
    load(file);
}

WordNode* WordList::find(const char* newWord)
{
    return nullptr;
}

bool WordList::isInList(const char* newWord)
{
    bool yesorno=false;
    return yesorno;
}

int WordList::getSize()
{
    return listSize;
}

void WordList::wordHandler(string newWord)
{
    
}

void WordList::load(string& file)
{
    string line;
    string word;
    ifstream ifin(file);
    getline(ifin,line);
    istringstream sen(line);
    while(sen>>word)
    {
        cout<<word;
    }
}