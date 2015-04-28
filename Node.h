#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Node{
private:
    int frequency;
    char letter;
    string code;
    Node* left, *right;
public:
    Node();
    Node(char, int);
    Node(Node*, Node*);
    Node(const Node&);
    ~Node();
    int getFrequency(){
        return frequency;
    }
    char getLetter(){
        return letter;
    }
    string getCode(){
        return code;
    }
    Node* getLeft(){
        return left;
    }
    Node* getRight(){
        return right;
    }

    void setCode(string s){
        code = s;
    }
    friend ostream& operator<<(ostream&, const Node&);

    Node& operator=(const Node&);
};
#endif
