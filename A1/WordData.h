//
//  WordData.h
//  A1
//
//  Created by AMIR HAKIM on 2014-05-16.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#ifndef __A1__WordData__
#define __A1__WordData__

#include <iostream>
#include "IntList.h"
using std::ostream;

class WordData{

public:
    WordData();
    WordData(const char*);
    WordData(const WordData&);
    ~WordData();
    void operator=(const WordData&);
    friend ostream& operator<<(ostream& sout,const WordData&);
    
    void addLineNumber();
    int getFrequency();
    void incrementFrequency();
    const char* getWP();
    IntList getIntList();
    int compare(const char*,int);
    int getLength();
    
private:
    char* word;
    int frequency;
    IntList lines;
    int length;
    
    
    
};

#endif /* defined(__A1__WordData__) */
