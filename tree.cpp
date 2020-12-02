#include<iostream>
using namespace std;

struct node {
    int id;
    node *parent;
    node **children;
};

int main() {
    int nchild;

    node node0;
    node0.id = 0;
    node0.parent = NULL;
    cout << "input number of children of 0 " << endl;
    cin >> nchild;
    node0.children = new struct node* [nchild];

    for (int i = 0; i < nchild; i++) {
        node *child = new struct node;
        child->id = 10+i;
        child->parent = &node0;

        child->children = NULL;

        node0.children[i] = child;
    }

    for(int i = 0; i < nchild; i++) cout << node0.children[i]->id << " " << node0.children[i]->parent->id << " - ";
    cout << endl;


    return 0;
}
