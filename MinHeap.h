#ifndef _MINHEAP_H_
#define _MINHEAP_H_
#include "Node.h"

class MinHeap{
private:
    Node** storage;
    int heapSize;
    int capacity;

    void percUp(int);
    void percDown(int);
    int numChildren(int);

    void inOrder(int);
    void postOrder(int);
    void preOrder(int);
public:
    MinHeap(int);
    ~MinHeap();
    void insert(Node*);
    Node* removeMin();
    Node peekMin();

    bool isEmpty();
    int getHeapSize(){
        return heapSize;
    }
    Node* getRoot(){
        return storage[0];
    }

    void inOrderTraversal();
    void postOrderTraversal();
    void preOrderTraversal();
    void linearDisplay();
    void emptyHeap();
};
#endif
