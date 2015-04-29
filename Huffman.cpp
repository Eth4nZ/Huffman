#include "Huffman.h"
#include <iostream>
#include <utility>
using namespace std;

Huffman::Huffman(string src){
    data = src;
    encodedData = "";
    outPutData = "";
    huffmanTableString = "";
    heap = new MinHeap(data.length());
    buildTable();
    buildHeap();
    buildOutPutTable();
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

void Huffman::buildOutPutTable(){
    outPutTable.insert(pair<char,string>('0',"0000"));
    outPutTable.insert(pair<char,string>('1',"0001"));
    outPutTable.insert(pair<char,string>('2',"0010"));
    outPutTable.insert(pair<char,string>('3',"0011"));
    outPutTable.insert(pair<char,string>('4',"0100"));
    outPutTable.insert(pair<char,string>('5',"0101"));
    outPutTable.insert(pair<char,string>('6',"0110"));
    outPutTable.insert(pair<char,string>('7',"0111"));
    outPutTable.insert(pair<char,string>('8',"1000"));
    outPutTable.insert(pair<char,string>('9',"1001"));
    outPutTable.insert(pair<char,string>('a',"1010"));
    outPutTable.insert(pair<char,string>('b',"1011"));
    outPutTable.insert(pair<char,string>('c',"1100"));
    outPutTable.insert(pair<char,string>('d',"1101"));
    outPutTable.insert(pair<char,string>('e',"1110"));
    outPutTable.insert(pair<char,string>('f',"1111"));
}

void Huffman::codeOutput(string src){
    for(size_t i = 0; i < src.length(); i += 4){
        if(src.length()-i >= 4){
            string temp = src.substr(i, 4);
            cout << temp << endl;
            for(map<char, string>:: iterator it = outPutTable.begin();
                    it != outPutTable.end(); ++it){
                if(it->second == temp){
                    outPutData += (it->first);
                    break;
                }
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

