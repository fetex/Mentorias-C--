
#include "node.h"

Node::Node() {
    next = NULL;
    prev = NULL;
    count = 0;
    begin = 0;
    end = 0;
    vec = vector<Element>(20);
}

Node::Node(int detSize, Node* n, Node* p){
    next = n;
    prev = p;
    count = 0;
    begin = 0;
    end = 0;
    vec = vector<Element>(detSize);
}

Node* Node::getNext(){
    return next;
}

void Node::setPrev(Node* p) {
    prev = p;
}

Node* Node::getPrev(){
    return prev;
}

void Node::setNext(Node* n){
    next = n;
}

int Node::getCount(){
    return count;
}

void Node::setCount(int n){
    count = n;
}

int Node::getVectorSize(){
    return vec.size();
}

int Node::getBegin(){
    return begin;
}

void Node::setBegin(int pos){
    begin = vec[pos];
}

void Node::setEnd(int pos){
    end = vec[pos];
}

//void Node::set(Element e, int pos){}

int Node::getEnd(){
    return end;
}

void Node::pushElement(Element e){
    vec[end] = e;
    end++;
    count++;
} 

void Node::frontElement(Element e){
    if(begin == 0){
        begin = vec.size();    
    }
    vec[begin-1]= e;
    --begin;
    ++count;
}

void Node::remove(int pos){
    for(int i= begin+pos; i<end-1; i++){
        vec[i]= vec[i+1];
    }   
    --end;
    //count++;
}

void Node::setELement(int pos, Element e){
    if(pos >= 0 && pos < vec.size()){
        vec[pos] == e;
    }
    //count++;
}

Element Node::atElement(int pos){
    return vec[pos];
}

/*implementaacion con iteradores, el iterador se mueve y sigue apuntando a lo mismo

Element Node::atElement(int pos){
    return vec.at(pos);
}
*/


void Node::printVector(Node n){
    for(int i = 0; i < vec.size(); ++i){
        cout << n.vec[i] << " ";
    }
    cout<<endl;
}

