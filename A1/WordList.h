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
#include <iomanip>

using std::ifstream;
using std::string;
using std::istringstream;
using std::cout;
using std::endl;
using std::setw;

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
    void operator=(const WordList&);
    friend ostream& operator<<(ostream& sout,const WordList&);
    int getSize();
    void print();
    void load(const string&);
    void wordHandler(string&,int);
    
private:
    WordNode* head;
    WordNode* tail;
    int listSize;
    string file;
    void addFirst(WordNode*);
    void addLast(WordNode*);
    void push(WordNode*,int);
    void addBefore();
    bool isEmpty();
    void addAfter(WordNode* first,WordNode* second);
    void printList();
    void cleanString(string&);
    void sort();
    void mergeSort();
    WordNode* mergeLists(WordNode*, WordNode*);
    WordNode* MergeSort(WordNode*);
    WordNode* Merge(WordNode*,WordNode*);
    WordNode* Split(WordNode*);
    
};

#endif /* defined(__A1__WordList__) */
