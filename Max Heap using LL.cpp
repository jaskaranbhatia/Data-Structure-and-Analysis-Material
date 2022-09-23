// Implementation of Max Heap using Linked List

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class PriorityQueue {
public:
    Node *maxNode;
    
    PriorityQueue() {
        maxNode = NULL;
    }
    
    void insertElement(int data) {
        Node *temp = maxNode;
        Node *prev = NULL;
        
        while(temp != NULL && temp->data > data) {
            prev = temp;
            temp = temp->next;
        }
        
        if (prev == NULL) {
            Node *newMaxNode = new Node(data);
            newMaxNode->next = maxNode;
            maxNode = newMaxNode;
        } else {
            Node *newNode = new Node(data);
            prev->next = newNode;
            newNode->next = temp;
        }
        return;
    }
    
    void deleteMax() {
        Node *delNode = maxNode;
        maxNode = maxNode->next;
        delete delNode;
        return;
    }
    
    int getMax() {
        if(!maxNode->data) return -1;
        return maxNode->data;
    }
};


int main() {
    PriorityQueue p;
    p.insertElement(1);
    p.insertElement(2);
    p.insertElement(3);
    p.insertElement(4);
    p.insertElement(5);
    
    while(p.getMax() != -1) {
        cout<<p.getMax()<<endl;
        p.deleteMax();
    }
}