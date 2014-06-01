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
    file=filename;
    load(filename);
    head=MergeSort(head);
    printList();
}

WordList::~WordList()
{
    
}

int WordList::getSize()
{
    return listSize;
}

void WordList::cleanString(string & word)
{
    
    for (size_t i = 0; i < word.length(); ++i)
        if (!isalnum(word[i]))
            word.erase(i, 1);//remove non alphabitical char
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);// string to lower
    //return word;
}

void WordList::wordHandler(string& newWord,int lineNumber)
{
    //cout << newWord << endl;
    unsigned long cwsize = (newWord.length())+1;
    char* cword=new char[cwsize];
    strcpy(cword,newWord.c_str());
    WordData wd(cword);
    wd.addLineNumber(lineNumber);
    WordNode* wn = new WordNode(wd,nullptr);
    push(wn,lineNumber);
    delete[] cword;
    //printList();
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
                cleanString(word);
                if (word.length()<1) continue;
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
        listSize++;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        listSize++;
    }
    
}

WordNode* WordList::makeNode(char *newWord,int lineNumber)
{
    WordData wd(newWord);
    wd.addLineNumber(lineNumber);
    WordNode* node = new WordNode(wd,nullptr);
    return node;
}

void WordList::push(WordNode * possibleNode,int lineNumber)
{
    if (head==nullptr) addFirst(possibleNode);
    else if (listSize==1)
    {
        if (head->word.compareWordData(possibleNode->word)==true) {
            //head->word.incrementFrequency();
            //head->word.addLineNumber(lineNumber);
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
        while (tmp!=nullptr)
        {
            if (tmp->word.compareWordData(possibleNode->word)==true)
            {
                delete possibleNode;
                return;
            }
            tmp=tmp->next;
        }
        addLast(possibleNode);
        delete tmp;
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
        while (tmp!=nullptr)
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
    cout << "Word Collection Source File:  "<<file<<endl;
    cout << "==============================="<<endl;
    if (isEmpty()) {
        cout << "is empty"<<endl;
    }
    else if (listSize==1)
    {
        cout << "Only one element found "<<endl;
        cout << (head->word) << endl;
    }
    
    else
    {
        WordNode* tmp=head;
        char header = '@';
        while (tmp!=nullptr) {
            char next=tmp->word.getFirstLetter();
            next=toupper(next);
            while (header!=next)
            {
                header++;
                cout <<"<"<<header<<">"<<endl;
                if (header==next) continue;
            }
            
            cout << setw(20)<< (tmp->word) << endl;
            tmp=tmp->next;
        }
    }
}

void WordList::addAfter(WordNode *first, WordNode *second)
{
    if (isEmpty())
    {
        cout << "(ERROR@WordList::addAfter)empty list"<<endl;
    }
    else if (listSize==1)
    {
        if (first==head)
        {
            addLast(second);
        }
        else
        {
            cout << "(ERROR@WordList::addAfter)the (after node) not in list"<<endl;
            return;
        }
    }
    else
    {
        WordNode* tmp=head;
        while (tmp!=nullptr)
        {
            if (tmp==first) {
                if (tmp==tail) {
                    addLast(second);
                    return;
                }
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

WordNode* WordList::MergeSort(WordNode *my_node)
{
    WordNode *secondNode;
    
    if (my_node == NULL)
        return NULL;
    else if (my_node->next == NULL)
        return my_node;
    else
    {
        secondNode = Split(my_node);
        return Merge(MergeSort(my_node),MergeSort(secondNode));
    }
}

WordNode* WordList::Merge(WordNode* firstNode, WordNode* secondNode)
{
    if (firstNode == NULL) return secondNode;
    else if (secondNode == NULL) return firstNode;
    else if (firstNode->word.compare(secondNode->word.getWP(), secondNode->word.getLength())>=0) //if I reverse the sign to >=, the behavior reverses
    {
        firstNode->next = Merge(firstNode->next, secondNode);
        return firstNode;
    }
    else
    {
        secondNode->next = Merge(firstNode, secondNode->next);
        return secondNode;
    }
}

WordNode* WordList::Split(WordNode* my_node)
{
    WordNode* secondNode;
    
    if (my_node == NULL) return NULL;
    else if (my_node->next == NULL) return NULL;
    else {
        secondNode = my_node->next;
        my_node->next = secondNode->next;
        secondNode->next = Split(secondNode->next);
        return secondNode;
    }
}



