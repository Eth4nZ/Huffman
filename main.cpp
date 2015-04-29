#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include "Huffman.h"

using namespace std;

int main(){
    char x = ' ';
    cout << "e.....Encode test_raw.md to test_encoded.md" << endl;
    cout << "d.....Decode test_encoded.md to test_decoded.md" << endl;
    cout << "......Other key to exit" << endl;
    cout << "select: ";
    cin >> x;
    if(x == 'e'){
        ifstream fin("test_raw.md", fstream::in);
        ofstream fout("test_encoded.md",fstream::out);
        char ch;
        string s = "";
        while (fin >> noskipws >> ch){
            s += ch;
        }

        Huffman* enctest = new Huffman(s);
        enctest->displayTable();
        enctest->displayHuffmanTable();
        string code = enctest->getEncodedString();
        cout << "Encoded string: " << code << endl;
        //fout << enctest->getHuffmanTableString() << endl;;
        //fout << code;
        fout << enctest->getOutPutData();
        //cout << "Decoded string: " << enctest->decodeString(code) << endl;
        delete enctest;
    }
    else{
        if(x == 'd'){
            ifstream fin("test_encoded.md", fstream::in);
            ofstream fout("test_decoded.md",fstream::out);
            string s = "";
            Huffman* dectest = new Huffman(s,0);
        }
        else
            cout << "exit...." << endl;
    }
    return 0;
}



