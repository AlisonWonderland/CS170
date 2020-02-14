#include <iostream>
#include "State.h"
using namespace std;

class Node
{
    private:
        vector<Node*> children;
        Node* left; 
        Node* right;
        Node* up;
        Node* down;
        State nodeState;
    public:
        // pass in vector to create new state?
        Node(State state);
        void addChildren(string moveDirection);
}