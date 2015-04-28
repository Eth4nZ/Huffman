#include "MinHeap.h"
#include <iostream>

using namespace std;

MinHeap::MinHeap(int size){
    capacity = size;
    heapSize = 0;
    storage = new Node*[capacity];
    for(int i = 0; i < capacity; i++)
        storage[i] = NULL;
}

MinHeap::~MinHeap(){
    if(storage != NULL){
        for(int i = 0; i< capacity; i++){
            delete storage[i];
            heapSize--;
        }
        delete[] storage;
        //for debug purposes
        cout << "heap size is (should be zero): " << heapSize << endl;
    }
}

void MinHeap::insert(Node* rhs){
    if(heapSize == capacity){
        cerr << "No more room in this heap!" << endl;
        return;
    }
    heapSize++;
    storage[heapSize-1] = rhs;
    percUp(heapSize-1);
}

void MinHeap::percUp(int curIndex){
    int parentIndex;
    Node* temp;
    if(curIndex !=0){
        parentIndex = (curIndex-1)/2;
        if(storage[parentIndex]->getFrequency() >
                 storage[curIndex]->getFrequency()){
            temp = storage[parentIndex];
            storage[parentIndex] = storage[curIndex];
            storage[curIndex] = temp;
            percUp(parentIndex);
        }
    }
}

int MinHeap::numChildren(int index){
    int children = 0;
    int left = 2*index+1, right = left+1;
    if(left >= heapSize)
        return 0;
    if(storage[left] != NULL)
        children++;
    if(storage[right] != NULL)
        children++;
    return children;
}

void MinHeap::percDown(int curIndex){
    int children = 0;
    if(children = numChildren(children)){
        Node* temp;
        int left = 2*curIndex+1, right = left+1;
        switch(children){
            case 1:
                if(storage[curIndex]->getFrequency() >
                         storage[left]->getFrequency()){
                    temp = storage[left];
                    storage[left] = storage[curIndex];
                    storage[curIndex] = temp;
                }
                break;
            case 2:
                if((storage[curIndex]->getFrequency() >
                            storage[left]->getFrequency())
                        || (storage[curIndex]->getFrequency() >
                            storage[right]->getFrequency())){
                    int rhsIndex = left;
                    if(storage[left]->getFrequency()
                             > storage[right]->getFrequency())
                        rhsIndex++;
                    temp = storage[rhsIndex];
                    storage[curIndex] = storage[rhsIndex];
                    storage[rhsIndex] = temp;
                    percDown(rhsIndex);
                }
                break;
            default:
                //no way, this shouldn't happen;
                break;
        }
    }
    return;
}

Node* MinHeap::removeMin(){
    Node* value = new Node();
    *value = * storage[0];
    //replace 1st & last slot;
    Node* temp = storage[0];
    storage[0] = storage[heapSize-1];
    storage[heapSize-1] = temp;
    delete storage[heapSize-1];
    storage[heapSize-1] = NULL; //avoid dangling pointers
    heapSize--;
    percDown(0);
    return value;
}

Node MinHeap::peekMin(){
    return *storage[0];
}

bool MinHeap::isEmpty(){
    return (heapSize == 0);
}

void MinHeap::inOrderTraversal(){
    if(isEmpty()){
        cout << "MinHeap is empty!" << endl;
        return;
    }
    inOrder(0);
    cout << endl;
}

void MinHeap::inOrder(int curIndex){
    //left cur right
    int left = 2*curIndex+1, right = left+1;
    if((left < capacity) && (storage[left] != NULL))
        inOrder(left);
    cout << *storage[curIndex] << " ";
    if((right < capacity) && (storage[right] != NULL))
        inOrder(right);
}

void MinHeap::postOrderTraversal(){
    if(isEmpty()){
        cout << "MinHeap is empty!" << endl;
        return;
    }
    postOrder(0);;
    cout << endl;
}

void MinHeap::postOrder(int curIndex){
    //left right cur
    int left = 2*curIndex+1, right = left+1;
    if((left < capacity) && (storage[left] != NULL))
        inOrder(left);
    if((right < capacity) && (storage[right] != NULL))
        inOrder(right);
    cout << *storage[curIndex] << " ";
}

void MinHeap::preOrderTraversal(){
    if(isEmpty()){
        cout << "MinHeap is empty!" << endl;
        return;
    }
    preOrder(0);;
    cout << endl;
}

void MinHeap::preOrder(int curIndex){
    //cur left right
    int left = 2*curIndex+1, right = left+1;
    cout << *storage[curIndex] << " ";
    if((left < capacity) && (storage[left] != NULL))
        inOrder(left);
    if((right < capacity) && (storage[right] != NULL))
        inOrder(right);
}

void MinHeap::linearDisplay(){
    for(int i = 0; i < heapSize; i++)
        cout << *storage[i] << " ";
    cout << endl;
}

void MinHeap::emptyHeap(){
    while(!isEmpty()){
        Node* temp = removeMin();
        cout << *temp << endl;
    }
}

            
