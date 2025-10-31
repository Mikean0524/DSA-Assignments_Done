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

    void insert(int value) {
        node* newnode = new node;
        newnode->data = value;
        newnode->next = nullptr;

        if (head == nullptr) {
            head = newnode;
        } else {
            node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newnode;
        }
    }

    void makeCircular() {
        if (head == nullptr)
            return;

        node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = head;
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

int main() {
    linkedList list;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }

    char choice;
    cout << "Do you want to make it circular? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
        list.makeCircular();

    if (list.isCircular())
        cout << "The linked list is circular.\n";
    else
        cout << "The linked list is not circular.\n";

    return 0;
}

