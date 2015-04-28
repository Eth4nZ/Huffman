#include <iostream>
#include <string>
#include <fstream>
#include "Huffman.h"

using namespace std;

int main(){
    ifstream fin("test.md", fstream::in);
    //not contain \n
    /*string temp;
    string s = "";
    while(getline(fin,temp)){
        s += temp;
    } */ 

    //contain \n
    char ch;
    string s = "";
    while (fin >> noskipws >> ch){
        s += ch;
    }
    
    //ofstream fout("test.out",fstream::out);

    Huffman* test = new Huffman(s);
    test->displayTable();
    test->displayHuffmanTable();
    string code = test->getEncodedString();
    cout << "Encoded string: " << code << endl;
    cout << "Decoded string: " << test->decodeString(code) << endl;
    delete test;
    return 0;
}



