//
//  WordList.cpp
//  A1
//
//  Created by AMIR HAKIM on 2014-05-23.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#include "WordList.h"

WordNode::WordNode(WordData newWord,WordNode* next):word(newWord)
{
    //cout << newWord << endl;
    this->next=next;
    //cout << (word) <<endl;
    
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
    //printList();
    //cout << listSize << endl;
}

WordList::~WordList()
{
    
}

int WordList::getSize()
{
    return listSize;
}

void WordList::wordHandler(string& newWord,int lineNumber)
{
    //newWord.erase(std::remove_if(newWord.begin(), newWord.end(),((int(*)(int))std::isalnum)), newWord.end());
    //cout << newWord << endl;
    unsigned long cwsize = (newWord.length())+1;
    char* cword=new char[cwsize];
    strcpy(cword,newWord.c_str());
    //cout << cword[cwsize-1] << endl;
    //cout << cwsize << endl;
    //cout<<cword<<endl;
    //cout<<&cword<<endl;
    WordData wd(cword);
    WordNode* wn = new WordNode(wd,nullptr);
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
                //cout<<word<<endl;
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
        //cout << "adde first "<<newNode->word.getWP()<<endl;
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
        //cout << "list was 1,new word: "<< newNode->word.getWP()<<endl;
        listSize++;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        //cout << "size was "<<listSize<<"new word "<<newNode->word.getWP()<<endl;
        listSize++;
    }
    
}

WordNode* WordList::makeNode(char *newWord)
{
    WordData wd(newWord);
    WordNode* node = new WordNode(wd,nullptr);
    return node;
}

void WordList::push(WordNode * possibleNode)
{
    if (head==nullptr) addFirst(possibleNode);
    else if (listSize==1)
    {
        if (head->word.compare(possibleNode->word.getWP(),possibleNode->word.getLength())==0) {
            head->word.incrementFrequency();
            //cout << "match1: " << possibleNode->word.getWP()<<endl;
            //"frequency: " << (possibleNode->word.getFrequency())<<endl;
            delete possibleNode;
            return;
        }
        else
        {
            addLast(possibleNode);
            //cout << "match2: " << possibleNode->word.getWP()<<endl;
        }
    }
    
    else
    {
        
        WordNode* tmp = head;
        while (tmp->next!=nullptr)
        {
            int x{0},y{0};
            x=tmp->word.compare(possibleNode->word.getWP(),possibleNode->word.getLength());
            y=tmp->next->word.compare(possibleNode->word.getWP(),possibleNode->word.getLength());
            //cout<<"x="<<x<<"y="<<y<<endl;
            if (x==0)
            {
                tmp->word.incrementFrequency();
                delete possibleNode;
                return;
            }
            
            else if (x<0)
            {
                addFirst(possibleNode);
                return;
            }
            
            
            else if (x>y)
            {
                addAfter(tmp, possibleNode);
                return;
            }
            
            else
            {
                addLast(possibleNode);
                return;
            }
            tmp=tmp->next;
        }
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
        if (head->word.compare(newWord,strlen(newWord))==0) {
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
            if (tmp->word.compare(newWord,strlen(newWord))==0) {
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
        if (head->word.compare(newWord,strlen(newWord))==0) {
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
            if (tmp->word.compare(newWord,strlen(newWord))==0) {
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
    else if (listSize==1)
    {
        cout << (head->word) << endl;
    }
    
    else
    {
        WordNode* tmp=head;
        while (tmp->next!=nullptr) {
            cout << (tmp->word) << endl;
            tmp=tmp->next;
        }
    }
    cout << "list size: " << listSize << endl;
}

void WordList::addAfter(WordNode *first, WordNode *second)
{
    if (isEmpty())
    {
        cout << "(ERROR@WordList::addAfter)new list created with two nodes"<<endl;
    }
    else if (listSize==1)
    {
        if (first==head)
        {
            addLast(second);
        }
        else
        {
            cout << "(ERROR@WordList::addAfter)first node was not in list=>nothing to do"<<endl;
            return;
        }
    }
    else
    {
        WordNode* tmp=head;
        while (tmp->next!=nullptr)
        {
            if (tmp==first) {
                second->next=tmp->next;
                tmp->next=second;
                listSize++;
                return;
            }
            tmp=tmp->next;
        }
    }
}

bool WordList::signChanged(int x, int y)
{
    bool hasChanged = (x >= 0) ^ (y < 0);
    //cout << "x=" << x << " y=" << y << endl;
    //cout << hasChanged << endl;
    return hasChanged;
}








