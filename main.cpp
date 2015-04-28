#include <iostream>
#include <string>
#include <fstream>
#include "Huffman.h"

using namespace std;

int main(){
    ifstream fin("test.md", fstream::in);
    /*ofstream fout("test.out",fstream::out);
    while (fin >> noskipws >> ch){
        fout << ch;
    }
    */
    string s="A aaaa bbbb cc fox jumps over the lazy dog.";
    Huffman* test = new Huffman(s);
    test->displayTable();
    test->displayHuffmanTable();
    string code = test->getEncodedString();
    cout << "Encoded string: " << code << endl;
    cout << "Decoded string: " << test->decodeString(code) << endl;
    delete test;
    return 0;
}



