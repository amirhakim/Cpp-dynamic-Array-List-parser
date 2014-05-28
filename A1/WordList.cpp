//
//  WordList.cpp
//  A1
//
//  Created by AMIR HAKIM on 2014-05-23.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#include "WordList.h"

WordNode::WordNode(char* newWord,WordNode* next)
{
    //cout << newWord << endl;
    word = new WordData(newWord);
    this->next=next;
    //cout << (word->getWP());
    
}

WordList::WordList()
{
    head=tail=nullptr;
    listSize=0;
}

WordList::WordList(const string& filename)
{
    //cout << "wordlist" << endl;
    head=tail=nullptr;
    listSize=0;
    load(filename);
}

WordList::~WordList()
{
    
}

WordNode* WordList::findNode(const char* newWord)
{
    WordNode* tmp;
    tmp=head;
    while (tmp->next!=nullptr)
    {
        if (tmp->word->getWP()==newWord)
        {
            return tmp;
        };
        
    }
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

void WordList::wordHandler(string newWord,int lineNumber)
{
    //cout << newWord << endl;
    unsigned long cwsize = (newWord.length())+1;
    char* cword=new char[cwsize];
    strcpy(cword,newWord.c_str());
    //cout << cword[cwsize-1] << endl;
    //cout << cwsize << endl;
    //cout<<cword<<endl;
    //cout<<&cword<<endl;
    WordNode* wn = new WordNode(cword,nullptr);
    push(wn);
    delete[] cword;
}

void WordList::load(const string& file)
{
    //cout << file << endl;
    string line;
    string word;
    ifstream ifin(file);
    int lineNumber = 0;
    while (!ifin.eof())
    {
        //cout << "good" << endl;
        lineNumber++;
        getline(ifin,line);
        istringstream sen(line);
        while(sen>>word)
            {
                wordHandler(word,lineNumber);
                //cout<<lineNumber;
                //cout<<word<<endl;
            }
    }
}

void WordList::addFirst(WordNode* newNode)
{
    if (head==nullptr)
    {
        head=tail=newNode;
        head->next=nullptr;
        listSize++;
        return;
    }
    
    else
    {
        newNode->next=head;
        head=newNode;
        listSize++;
    }
//            cout << " (ERROE@WordList::addFirst)head already exist" << endl;
}

void WordList::addLast(WordNode* newNode)
{
    if(head==nullptr) addFirst(newNode);
    else
    {
        WordNode* tmp = head;
        while (tmp->next!=nullptr) {
            tmp=tmp->next;
        }
        tmp->next = newNode;
        tail = newNode;
        listSize++;
    }
    
}

WordNode* WordList::makeNode(char *newWord)
{
    WordNode* node = new WordNode(newWord,nullptr);
    return node;
}

void WordList::push(WordNode * possibleNode)
{
    WordNode* tmp = head;
    if (head==nullptr) addFirst(possibleNode);
    else
    {
        do
        {
            int p = (tmp->word->compare(possibleNode->word->getWP()));
            cout << "p" << p << endl;
            if(p==0)
            {
                cout << "match: " << tmp->word->getWP()<< endl;
                //increase frequesncy;
            }
            else
            {
                addLast(possibleNode);
            }
            
        } while(tmp->next!=nullptr);
    }

}



