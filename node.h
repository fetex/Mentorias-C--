/*
Implentacion Nodos
Abril 10/ 2024
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

typedef int Element;

class Node{
  private:
    Node *next, *prev;
    int count, begin, end;
    vector<Element> vec;

  public:
    Node();
    Node(int, Node*, Node*);
    Node* getNext();
    Node* getPrev();
    Node* getNode(int);
    int getCount();
    void setCount(int);
    void setData(Element);
    void setNext(Node*);
    void setPrev(Node*);

    int getVectorSize();
    void pushElement(Element);
    void frontElement(Element);
    void remove(int);
    void insert(Element);
    void setELement(int, Element);
    Element atElement(int);
    int getBegin();
    void setBegin(int);
    int getEnd();
    void setEnd(int);
    
    
    void printVector(Node);
    //void removeDataVec(int);
    
};