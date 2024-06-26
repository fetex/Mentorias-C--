#include <iostream>
#include "node.h"
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class List{ //comentario lista 1
    private:
    int blockSize, listSize;
    Node* act;
    
    public:
    List();
    List(int);
    List(vector<Element>&);
    List(List&);
    void push_back(Element);
    void insert(Element, int);
    void remove(int);
    Element at(int);
    void set(int, Element);
    int size();
    bool empty();

    //print------------
    void printVec();
    void push_front(Element);
    //-----------------
    
    void append(List);//comentario lista 3
    bool operator==(const List&);
    void resizeBlock(int);
    vector<int> getVector();
    int getMax();
    bool contains();        
    static List addVectorOfLists(vector<List>&);
    bool operator+(List&);
    bool operator<(List&); //comentario lista 2
    bool operator==(const List&);
    Element operator[](int);
};
