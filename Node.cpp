#include "Node.h"
using namespace std;

Node::Node(){
    letter = ' ';
    frequency = 0;
    left = right = NULL;
}

Node::Node(char c, int i){
    letter = c;
    frequency = i;
    left = right = NULL;
}

Node::Node(Node* left, Node* right){
    this->left = left;
    this->right = right;
    frequency = left->getFrequency() + right->getFrequency();
    //letter = NULL;
}

Node::~Node(){
    if(left != NULL)
        delete left;
    if(right != NULL)
        delete right;
}

Node::Node(const Node& rhs){
    if(rhs.left != NULL){
        left = new Node();
        *left = *(rhs.left);
    }
    if(rhs.right != NULL){
        right = new Node();
        *right = *(rhs.right);
    }
    code = rhs.code;
    letter = rhs.letter;
    frequency = rhs.frequency;
}

ostream& operator<<(ostream& os, const Node& rhs){
    os << "\'" << rhs.letter << " " << rhs.frequency << "\'";
    return os;
}

Node& Node::operator=(const Node& rhs){
    if(this != &rhs){
        code = rhs.code;
        letter = rhs.letter;
        frequency = rhs.frequency;
        if(left != NULL)
            delete left;
        if(right != NULL)
            delete right;

        if(rhs.left != NULL){
            left = new Node();
            *left = *(rhs.left);
            if(rhs.right != NULL){
                right = new Node();
                *right = *(rhs.right);
            }
        }
        else left = right = NULL;
    }
    return *this;
}
