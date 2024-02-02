// intlist.cpp
// Implements class IntList
// Sohom Dutta, February 1, 2024

#include "intlist.h"

#include <iostream>
#include <algorithm>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    first = nullptr;
    Node* curr = source.first;
    while(curr!=nullptr){
        append(curr->info);
        curr = curr->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    if(first!=nullptr){
        Node* prev = first;
        Node* curr = first->next;
        while(curr!=nullptr){
            Node* copy = curr;
            delete prev;
            prev = copy;
            curr = curr->next;
        }       
        delete prev;
    }
    
}

// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* curr = first;
    while(curr!=nullptr){
        sum = sum + curr->info;
        curr = curr->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = first;
    while(curr!=nullptr){
        if(curr->info==value){
            return true;
        }
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(first==nullptr){
        return 0;
    }
    Node* curr = first;
    int maxVal = curr->info;
    while(curr!=nullptr){
        maxVal = std::max(maxVal, curr->info);
        curr = curr->next;
    }
    return maxVal;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(first==nullptr){
        return 0.0;
    }
    double sum = 0.0;
    double count = 0.0;
    Node* curr = first;
    while(curr!=nullptr){
        sum = sum + curr->info;
        count = count + 1;
    }
    return sum / count;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    if(first==nullptr){
        first = new IntList::Node();
        first->info = value;
        first->next = nullptr;
        return;
    }
    Node* root = new IntList::Node();
    root->info = value;
    root->next = first;
    first = root;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
