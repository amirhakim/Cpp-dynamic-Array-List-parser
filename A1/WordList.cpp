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
    printList();
}

WordList::~WordList()
{
    
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
    if (isEmpty())
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
    if(isEmpty()) addFirst(newNode);
    else if(listSize==1)
    {
        tail->next=newNode;
        tail=newNode;
        listSize++;
    }
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
    else if ((tmp=findNode(possibleNode->word->getWP()))!=nullptr)
             {
                 tmp->word->incrementFrequency();
             }
    else
    {
        addLast(possibleNode);
    }

}

bool WordList::isEmpty()
{
    if (listSize==0) {
        return true;
    }
    else return false;
}

bool WordList::isInList(const char* newWord)
{
    if (isEmpty()) {
        return false;
    }
    else if(head==tail)
    {
        if (head->word->compare(newWord)==0) {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        WordNode* tmp=head;
        while (tmp->next!=nullptr)
        {
            if (tmp->word->compare(newWord)==0) {
                return true;
            }
            tmp=tmp->next;
        }
        
    }
    return false;
}

WordNode* WordList::findNode(const char *newWord)
{
    if (isEmpty()) {
        return nullptr;
    }
    else if (head==tail)
    {
        if (head->word->compare(newWord)==0) {
            return head;
        }
        else
        {
            return nullptr;
        }
    }
    else
    {
        WordNode* tmp=head;
        while (tmp->next!=nullptr)
        {
            if (tmp->word->compare(newWord)==0) {
                return tmp;
            }
            tmp=tmp->next;
        }
    }
    return nullptr;
}

void WordList::printList()
{
    if (isEmpty()) {
        cout << "is empty"<<endl;
    }
    else if (head==tail)
    {
        cout << (head->word->getWP()) << endl;
    }
    
    else
    {
        WordNode* tmp=head;
        while (tmp->next!=nullptr) {
            cout << (tmp->word->getWP()) << endl;
            tmp=tmp->next;
        }
    }
}





