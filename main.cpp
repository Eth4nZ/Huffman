#include <iostream>
#include <fstream>

using namespace std;

int main(){
    char ch;
    ifstream fin("test.md", fstream::in);
    ofstream fout("test.out",fstream::out);
    while (fin >> noskipws >> ch){
        fout << ch;
    }
}
