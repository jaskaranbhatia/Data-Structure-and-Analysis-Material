#include<bits/stdc++.h>
using namespace std;

class Node {
public:    
    int data;
    Node *left;
    Node *right;
    
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node *&root, int data) {
    if(root == NULL) {
        root = new Node(data);
    } else if (root->data >= data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node *maxNode(Node *root) {
    Node *temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    
    return temp;
}

Node *removeMax(Node *root) {
    if(root == NULL) return NULL;
    
    if(root->right == NULL) {
        return root->left;
    }
    
    Node *par = root;
    Node *child = root->right;
    
    while(child->right != NULL) {
        par = child;
        child = child->right;
    }
    
    par->right = NULL;
    return root;
}

int main() {
    Node *root = NULL;
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 1);
    insertNode(root, 4);
    
    while(root != NULL) {
        Node *max = maxNode(root);
        cout<<max->data<<" ";
        root = removeMax(root);
    }
}