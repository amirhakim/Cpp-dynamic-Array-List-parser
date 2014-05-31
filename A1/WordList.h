//
//  WordList.h
//  A1
//
//  Created by AMIR HAKIM on 2014-05-23.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#ifndef __A1__WordList__
#define __A1__WordList__

#include <iostream>
#include "WordData.h"
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <cctype>

using std::ifstream;
using std::string;
using std::istringstream;
using std::cout;
using std::endl;

struct WordNode{
    WordData word;
    WordNode* next;
    WordNode(WordData,WordNode*);
};

class WordList{
public:
    WordList();
    WordList(const string&);
    WordList(const WordList&);
    ~WordList();
    //void operator=(const WordList&);
    //friend ostream& operator<<(ostream& sout,const WordList&);
    int getSize();
    void print();
    void load(const string&);
    WordNode* findNode(const char*);
    void wordHandler(string&,int);
    WordNode* makeNode(char* newWord,int lineNumber);
    
    
//private:
    

    WordNode* head;
    WordNode* tail;
    int listSize;
    void addFirst(WordNode*);
    bool isInList(const char*);
    void addLast(WordNode*);
    void push(WordNode*,int);
    void addBefore();
    bool isEmpty();
    void addAfter(WordNode* first,WordNode* second);
    void printList();
    WordNode* travers();
    bool signChanged(int x,int y);
    void cleanString(string&);
    
    
};

#endif /* defined(__A1__WordList__) */
