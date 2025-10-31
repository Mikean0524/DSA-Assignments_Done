#include <iostream>
using namespace std;

/*struct node {
    int data;
    node* next;
    node* prev;
};

class DoublyLinkedList {
    node* head;
    node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value) {
        node* newnode = new node;
        newnode->data = value;
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

    int size() {
        int count = 0;
        node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList list;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }

    cout << "Size of Doubly Linked List = " << list.size() << endl;
    return 0;
}
*/
struct node {
    int data;
    node* next;
};

class CircularLinkedList {
    node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        node* newnode = new node;
        newnode->data = value;

        if (head == nullptr) {
            head = newnode;
            newnode->next = head;
        } else {
            node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
        }
    }

    int size() {
        if (head == nullptr)
            return 0;

        int count = 1;
        node* temp = head->next;
        while (temp != head) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    CircularLinkedList list;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }

    cout << "Size of Circular Linked List = " << list.size() << endl;
    return 0;
}

