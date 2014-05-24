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

using std::ifstream;
using std::string;
using std::istringstream;
using std::cout;
using std::endl;

struct WordNode{
    WordData* word;
    WordNode* next;
    WordNode(char*);
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
    WordNode* find(const char*);
    void wordHandler(string);
    
private:
    

    WordNode* head;
    WordNode* tail;
    int listSize;
    void addFirst(WordNode&);
    bool isInList(const char*);
    void addLast(WordNode&);
    void addBefore();
    
    
};

#endif /* defined(__A1__WordList__) */
