#include <iostream>
#include <fstream>

using namespace std;

int main(){
    char ch;
    fstream fin("test.md", fstream::in);
    while (fin >> noskipws >> ch){
        cout << ch;
    }
}
