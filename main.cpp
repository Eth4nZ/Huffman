#include <iostream>
#include <fstream>
#include "Node.cpp"

using namespace std;

int main(){
    ifstream fin("test.md", fstream::in);
    /*ofstream fout("test.out",fstream::out);
    while (fin >> noskipws >> ch){
        fout << ch;
    }
    */

    Node* n = new Node();
    Node* n1 = new Node();
    n=n1;
}
