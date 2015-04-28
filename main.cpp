#include <iostream>
#include <string>
#include <fstream>
#include "Huffman.h"

using namespace std;

int main(){
    char x = ' ';
    cout << "e.....Encode test_raw.md to test_encoded.md" << endl;
    cout << "d.....Decode test_encoded.md to test_decoded.md" << endl;
    cout << "......Other key to exit" << endl;
    cout << "select:";
    cin >> x;
    if(x == 'e'){
        ifstream fin("test_raw.md", fstream::in);
        ofstream fout("test_encoded.md",fstream::out);
        char ch;
        string s = "";
        while (fin >> noskipws >> ch){
            s += ch;
        }

        Huffman* test = new Huffman(s);
        test->displayTable();
        test->displayHuffmanTable();
        string code = test->getEncodedString();
        cout << "Encoded string: " << code << endl;
        fout << test->getHuffmanTableString() << endl;;
        fout << code;
        cout << "Decoded string: " << test->decodeString(code) << endl;
        delete test;
    }
    else{
        if(x == 'd'){
        }
        else
            cout << "exit...." << endl;
    }
    return 0;
}



