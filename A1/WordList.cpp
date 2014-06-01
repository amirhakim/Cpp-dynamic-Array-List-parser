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
    this->next=next;
}

WordList::WordList()
{
    head=tail=nullptr;
    listSize=0;
}

WordList::WordList(const string& filename)
{
    head=tail=nullptr;
    listSize=0;
    file=filename;
    load(filename);
    head=mergeSort(head);
    printList();
    popAll(head);
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
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);// string to lower case
}

void WordList::wordHandler(string& newWord,int lineNumber)
{
    unsigned long cwsize = (newWord.length())+1;
    char* cword=new char[cwsize];
    strcpy(cword,newWord.c_str());
    WordData wd(cword);
    wd.addLineNumber(lineNumber);
    WordNode* wn = new WordNode(wd,nullptr);
    push(wn,lineNumber);
    delete[] cword;
}

void WordList::load(const string& file)
{
    string line;
    string word;
    ifstream ifin(file);
    int lineNumber = 0;
    if (!ifin.is_open())
    {
        printf ("Error opening file");
        exit (EXIT_FAILURE);
    }
    while (!ifin.eof())
    {
        lineNumber++;
        getline(ifin,line);
        istringstream sen(line);
        while(sen>>word)
            {
                cleanString(word);
                if (word.length()<1) continue;
                wordHandler(word,lineNumber);
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

void WordList::push(WordNode * possibleNode,int lineNumber)
{
    if (head==nullptr) addFirst(possibleNode);
    else if (listSize==1)
    {
        if (head->word.compareWordData(possibleNode->word)==true) {
            delete possibleNode;
            return;
        }
        else
        {
            addLast(possibleNode);
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
                if (header=='[') {
                    return;
                }
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


WordNode* WordList::mergeSort(WordNode *head)
{
    WordNode *secondNode;
    
    if (head == NULL)
        return NULL;
    else if (head->next == NULL)
        return head;
    else
    {
        secondNode = split(head);
        return merge(mergeSort(head),mergeSort(secondNode));
    }
}

WordNode* WordList::merge(WordNode* firstNode, WordNode* secondNode)
{
    if (firstNode == NULL) return secondNode;
    else if (secondNode == NULL) return firstNode;
    else if (firstNode->word.compare(secondNode->word.getWP(), secondNode->word.getLength())>=0)     {
        firstNode->next = merge(firstNode->next, secondNode);
        return firstNode;
    }
    else
    {
        secondNode->next = merge(firstNode, secondNode->next);
        return secondNode;
    }
}

WordNode* WordList::split(WordNode* head)
{
    WordNode* secondNode;
    
    if (head == NULL) return NULL;
    else if (head->next == NULL) return NULL;
    else {
        secondNode = head->next;
        head->next = secondNode->next;
        secondNode->next = split(secondNode->next);
        return secondNode;
    }
}

void WordList::popAll(WordNode* head)
{
    if (head) {
        popAll(head->next);
        delete head;
    }
    head=tail=nullptr;
    listSize=0;
}

