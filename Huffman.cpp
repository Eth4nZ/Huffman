#include "Huffman.h"
#include <iostream>
#include <utility>
using namespace std;

Huffman::Huffman(string src){
    data = src;
    encodedData = "";
    huffmanTableString = "";
    heap = new MinHeap(data.length());
    buildTable();
    buildHeap();
    buildOutputTable();
    codeOutput(encodedData);
}

Huffman::Huffman(string src, int i){
    buildHuffmanTableFromString(src);
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

void Huffman::buildOutputTable(){
    outputTable.insert(pair<char,string>('0',"0000"));
    outputTable.insert(pair<char,string>('1',"0001"));
    outputTable.insert(pair<char,string>('2',"0010"));
    outputTable.insert(pair<char,string>('3',"0011"));
    outputTable.insert(pair<char,string>('4',"0100"));
    outputTable.insert(pair<char,string>('5',"0101"));
    outputTable.insert(pair<char,string>('6',"0110"));
    outputTable.insert(pair<char,string>('7',"0111"));
    outputTable.insert(pair<char,string>('8',"1000"));
    outputTable.insert(pair<char,string>('9',"1001"));
    outputTable.insert(pair<char,string>('a',"1010"));
    outputTable.insert(pair<char,string>('b',"1011"));
    outputTable.insert(pair<char,string>('c',"1100"));
    outputTable.insert(pair<char,string>('d',"1101"));
    outputTable.insert(pair<char,string>('e',"1110"));
    outputTable.insert(pair<char,string>('f',"1111"));
}

void Huffman::codeOutput(string src){
    outputData = "";
    for(size_t i = 0; i < src.length(); i += 4){
        string temp = src.substr(i, i+3);
        for(map<char, string>:: iterator it = outputTable.begin();
                it != outputTable.end(); ++it){
            if(it->second == temp){
                outputData += (it->first);
                break;
            }
        }
    }
}


void Huffman::buildHuffmanTableFromString(string src){
    size_t lastBlock = 0;
    int x=0;
    char c;
    string temp;
    for(size_t i = 0; i < src.length(); i++){
        if(src.at(i) == ' '){
            switch(x){
                case 0:
                    c = src.at(i);
                    break;
                case 1:
                    temp = src.substr(lastBlock, i-lastBlock);
                    break;
                }
            lastBlock = i+1;
            huffmanTable.insert(pair<char, string>(c, temp));
        }
    }
}

void Huffman::buildHeap(){
    for(map<char, int>::iterator it = frequencyTable.begin();
            it != frequencyTable.end(); ++it){
        heap->insert(new Node(it->first, it->second));
    }
    //cout << "heapSize: " << heap->getHeapSize() << endl; //debug
    //heap->linearDisplay(); //debug
    //pop 2 and insert 1 at a time, until get only one left;
    while(!heap->isEmpty()){
        if(heap->getHeapSize() == 1)
            break;
        Node* left = heap->removeMin();
        Node* right = heap->removeMin();
        heap->insert(new Node(left, right));
    }
    //cout << "heapSize: " << heap->getHeapSize() << endl; //debug
    //heap->linearDisplay(); //debug
    string code = "";
    getEncoding(heap->getRoot(), code);
    encode();
}

void Huffman::getEncoding(Node* root, string code){
    if(root->getLeft() == NULL){
        root->setCode(code);
        //cout << root->getLetter() << " " << root->getFrequency() << " " << code << endl; //debug
        huffmanTable.insert(pair<char, string>(root->getLetter(), code));
        huffmanTableString += root->getLetter();
        huffmanTableString.append(" ");
        huffmanTableString += code;
        huffmanTableString.append(" ");
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
        //encodedData.append(" ");
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

