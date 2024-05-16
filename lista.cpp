
#include "lista.h"

//

//un constructor por defecto en el que se asuma como el tamaño de los bloques el valor 20.
List::List(){
    act = NULL;
    blockSize = 20;
    listSize = 0;
}

//Una operación constructora que reciba como único parámetro el tamaño de los bloques
List::List(int n){
    act = NULL;
    blockSize = n;
    listSize = 0;
}

//operación constructora que reciba un vector de elementos con todos los elementos en el vector.
List::List(vector<Element> &v){
    blockSize = 10;
    listSize = 0;
    Node* n = new Node(blockSize, NULL, NULL);
    n->setNext(n);
    n->setPrev(n);
    act = n;
    Node* temp = act;
    int i = 0;

    while(i < v.size()){
        if(temp->getCount() < blockSize){
            temp->pushElement(v[i]);
            //++listSize;
        }else{
            Node* sec = new Node(blockSize, NULL, NULL);
            sec->setPrev(temp);
            sec->setNext(act);
            act->setPrev(sec);
            temp->setNext(sec);
            temp = sec;
            temp->setCount(0);
            temp->setEnd(0);
            temp->pushElement(v[i]);
            //++listSize;
        }
        ++i;
        ++listSize;
    }
}


//Una operación constructora que tome como parámetro otra instancia de List y copie sus valores en el objeto que se está creando.
List::List(List &n){

}

//---------------------------------------------------------------
//resize *end y begin.

void List::push_back(Element e){
    Node* n = new Node(blockSize,NULL,NULL);
    Node* last;
    if(act == NULL){   
        act = n;
        n->setNext(n);
        n->setPrev(n);
        act->setEnd(0);
        act->pushElement(e);
    }else{
        last = act->getPrev();
        if((last->getCount() < last->getVectorSize()) && (last->getEnd() != (last->getVectorSize()))){
            last->pushElement(e);
        }else{
            last->setNext(n);
            n->setNext(act);
            n->setPrev(last);
            act->setPrev(n);
            last = n;
            last->setEnd(0);
            last->pushElement(e);
        }
    }
    ++listSize;
}

//---------------------------------------------------
void List::push_front(Element e){ 
    Node* n = new Node(blockSize, NULL, NULL);
    Node* last;
    if(act == NULL){
        act = n;
        n->setNext(n);
        n->setPrev(n);
        //act->setCount(act->getVectorSize() - 1);
        act->frontElement(e);
    }else{
        if((act->getCount() == 0) || (act->getBegin() == 0)){
            last = act->getPrev();
            last->setNext(n);
            n->setNext(act);
            n->setPrev(last);
            act->setPrev(n);
            act = n;
            //act->setCount(act->getVectorSize() - 1);
            act->frontElement(e);
        }
        else{
            act->frontElement(e);
        }
    }
    ++listSize;
}

void List::remove(int pos){
    Node* tmp = act, *tmp2, *tmp3;
    bool flag = true;

    if(pos>=listSize){
        tmp = NULL;
    }else{
        while(pos > tmp->getCount() && (flag || tmp != act)){
            tmp = tmp -> getNext();
            pos -= tmp->getCount();
            flag = false;
        }if(tmp->getCount() != 1){
            tmp->remove(pos);
        }else{
            if(tmp == act){//quitar primer nodo
                tmp3 = act->getPrev();
                tmp2 = act->getNext();
                tmp3->setNext(tmp2);
                tmp2->setPrev(tmp3);
                act = tmp2;

            }else if(tmp == act->getPrev()){ //quitar ultimo nodo
                tmp3 = tmp3->getPrev()->getPrev();
                tmp3 -> setNext(act);
                act->setPrev(tmp3);

            }else{//quitar nodo en el medio
                tmp2 = tmp->getNext();
                tmp3 = tmp->getPrev();
                tmp2->setPrev(tmp3);
                tmp3->setNext(tmp2);            
            }
        }
        delete tmp;
    }
}

void List::set(int pos, Element e){
  Node* tmp = act;
  int count;

  if(pos<= listSize/2){
    while(){
        tmp->setElement(pos, e);
    }
  }





}

Element List::at(int pos){
    Element ans;
    Node* temp = act;
    int counter = 0;
    int difference = blockSize - act->getCount();
    int numNodes = (pos + difference) / blockSize;
    if (pos <= listSize/2){
        while(counter < numNodes){
            temp = temp->getNext();
            ++counter;
        }
        int auxPos = pos - (((numNodes-1) * blockSize) + act->getCount());
        ans = temp->atElement(auxPos);
    }else if(pos >= listSize / 2){
        int numTotalNodes = (listSize/blockSize) + 1;
        int nodes = numTotalNodes - numNodes;
        while(counter < nodes){
            temp = temp->getPrev();
            ++counter;
        }
        int auxPos = (pos + difference) % blockSize;
        ans = temp->atElement(auxPos);
    }
    return ans;
}

void List::printVec(){
    Node* temp = act;
    bool flag = true;
    while( temp != act || flag){
        temp->printVector(*temp);
        temp = temp->getNext();
        flag = false;
    }
}


