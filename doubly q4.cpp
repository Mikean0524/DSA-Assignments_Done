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

    void insert(char ch) {
        node* newnode = new node;
        newnode->data = ch;
        newnode->next = nullptr;
        newnode->prev = nullptr;

        if (head == nullptr) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
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

int main() {
    doublyLinkedList list;
    char ch;
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        list.insert(ch);
    }

    if (list.isPalindrome())
        cout << "The list is a palindrome.\n";
    else
        cout << "The list is not a palindrome.\n";

    return 0;
}

