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
    string huffmanTableString;
    string outPutData;
    MinHeap* heap;
    map<char, int> frequencyTable;
    map<char, string> huffmanTable;
    map<char, string> outPutTable;
    void buildTable();
    void buildHeap();
    void buildOutPutTable();
    void getEncoding(Node*, string);
    void encode();
    void codeOutput(string);
public:
    Huffman(string);
    Huffman(string,int);
    ~Huffman();
    string getSourceString(){
        return data;
    }
    string getEncodedString(){
        return encodedData;
    }
    string getOutPutData(){
        return outPutData;
    }
    string getHuffmanTableString(){
        return huffmanTableString;
    }
    void displayTable();
    void displayHeap();
    void displayHuffmanTable();
    string decodeString(string);

    void buildHuffmanTableFromString(string);

    void emptyHeap(){
        heap->emptyHeap();
    }
};
#endif
