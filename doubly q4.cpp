#include <iostream>
using namespace std;

struct node {
    char data;
    node* next;
    node* prev;
};

class doublyLinkedList {
    node* head;
    node* tail;

public:
    doublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    bool isPalindrome() {
        if (head == nullptr)
            return true;

        node* left = head;
        node* right = tail;

        while (left != nullptr && right != nullptr && left != right && right->next != left) {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }

        return true;
    }
};


