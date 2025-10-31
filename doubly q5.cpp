#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class linkedList {
    node* head;

public:
    linkedList() {
        head = nullptr;
    }

    bool isCircular() {
        if (head == nullptr)
            return false;

        node* temp = head->next;
        while (temp != nullptr && temp != head)
            temp = temp->next;

        return (temp == head);
    }
};


