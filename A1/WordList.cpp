//
//  WordList.cpp
//  A1
//
//  Created by AMIR HAKIM on 2014-05-23.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#include "WordList.h"

WordNode::WordNode(char* newWord)
{
    cout << newWord << endl;
    WordData* word = new WordData(newWord);
    next=nullptr;
    cout << (word->getWP());
    
}

WordList::WordList()
{
    head=tail=nullptr;
    listSize=0;
}

WordList::WordList(const string& filename)
{
    load(filename);
}

WordList::~WordList()
{
    
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
    //cout << newWord << endl;
    unsigned long cwsize = (newWord.length())+1;
    char* cword=new char[cwsize];
    strcpy(cword,newWord.c_str());
    //WordNode wn(cword);
    //cout << cword[cwsize-1] << endl;
    cout << cwsize << endl;
    cout<<cword<<endl;
    cout<<&cword<<endl;
    WordNode w(cword);
    delete[] cword;
}

void WordList::load(const string& file)
{
    string line;
    string word;
    ifstream ifin(file);
    while (!ifin.eof())
    {
    getline(ifin,line);
    istringstream sen(line);
    while(sen>>word)
    {
        wordHandler(word);
        //cout<<word<<endl;
    }
    }
}

void WordList::addFirst(WordNode& newNode)
{
    if (head==nullptr)
    {
        cout << " (ERROE@WordList::addFirst)head already exist" << endl;
        return;
    }
    tail=head= &newNode;
}

void WordList::addLast(WordNode & newNode)
{
    if(head==nullptr) addFirst(newNode);
    else
    {
        WordNode* tmp = head;
        while (tmp->next!=nullptr) {
            tmp=tmp->next;
        }
        tmp->next = &newNode;
        tail = &newNode;
    }
    
}