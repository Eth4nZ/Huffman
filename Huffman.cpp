#include "Huffman.h"
#include <iostream>
#include <utility>
using namespace std;

Huffman::Huffman(string src){
    data = src;
    encodedData = "";
    heap = new MinHeap(data.length());
    buildTable();
    buildHeap();
}

Huffman::~Huffman(){
    if(heap != NULL)
        delete heap;
}

void Huffman::buildTable(){
    for(size_t i = 0; i < data.length(); i++){
        char c =data.at(i);
        if(frequencyTable.find(data.at(i)) == frequencyTable.end()){
            frequencyTable.insert(pair<char, int>(c, 1));
        }
        else
            frequencyTable[c]++;
    }
}

void Huffman::buildHeap(){
    for(map<char, int>::iterator it = frequencyTable.begin();
            it != frequencyTable.end(); ++it){
        heap->insert(new Node(it->first, it->second));
    }
    heap->linearDisplay();
    //pop 2 and insert 1 at a time, until get only one left;
    while(!heap->isEmpty()){
        if(heap->getHeapSize() == 1)
            break;
        Node* left = heap->removeMin();
        Node* right = heap->removeMin();
        heap->insert(new Node(left, right));
    }
    string code = "";
    getEncoding(heap->getRoot(), code);
    encode();
}

void Huffman::getEncoding(Node* root, string code){
    if(root->getLeft() == NULL){
        root->setCode(code);
        cout << root->getLetter() << " " << root->getFrequency() << " " << code << endl;
        huffmanTable.insert(pair<char, string>(root->getLetter(), code));
        return;
    }
    else{
        getEncoding(root->getLeft(), code+"0");
        getEncoding(root->getRight(), code+"1");
    }
}

void Huffman::displayTable(){
    cout << "Frequency Table: " << endl;
    for(map<char, int>::iterator it = frequencyTable.begin();
            it != frequencyTable.end(); ++it){
        cout << it->first << "\t" << it->second << endl;
    }
}

void Huffman::encode(){
    for(size_t i = 0; i < data.length(); i++){
        encodedData.append(huffmanTable[data.at(i)]);
        encodedData.append(" ");
    }
}

void Huffman::displayHuffmanTable(){
    cout << "Huffman Table: " << endl;
    for(map<char, string>::iterator it = huffmanTable.begin();
            it != huffmanTable.end(); ++it){
        cout << it->first << "\t" << it->second << endl;
    }
}

string Huffman::decodeString(string src){
    string info = "";
    size_t lastBlock = 0;
    for(size_t i = 0; i < src.length(); i++){
        if(src.at(i) == ' '){
            string temp = src.substr(lastBlock, i-lastBlock);
            lastBlock = i+1;
            for(map<char, string>:: iterator it = huffmanTable.begin();
                    it != huffmanTable.end(); ++it){
                if(it->second == temp){
                    info += (it->first);
                    break;
                }
            }
        }
    }
    return info;
}

void Huffman::displayHeap(){
    heap->inOrderTraversal();
}

