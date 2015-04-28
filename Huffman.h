#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_
#include "MinHeap.h"
#include <string>
#include <map>

using std::string;
using std::map;

class Huffman{
private:
    string data;
    string encodedData;
    MinHeap* heap;
    map<char, int> frequencyTable;
    map<char, string> huffmanTable;
    void buildTable();
    void buildHeap();
    void getEncoding(Node*, string);
    void encode();
public:
    Huffman(string);
    ~Huffman();
    string getSourceString(){
        return data;
    }
    string getEncodedString(){
        return encodedData;
    }
    void displayTable();
    void displayHeap();
    void displayHuffmanTable();
    string decodeString(string);

    void emptyHeap(){
        heap->emptyHeap();
    }
};
#endif
