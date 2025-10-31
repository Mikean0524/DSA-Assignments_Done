#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

class linkedlist {
    node* head;
    node* tail;
public:
    linkedlist() {
        head = nullptr;
        tail = nullptr;
    }

    void insertatb(int value) {
        node* newnode = new node;
        newnode->data = value;
        if (head == nullptr) {
            newnode->next = nullptr;
            newnode->prev = nullptr;
            head = tail = newnode;
        } else {
            newnode->prev = nullptr;
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void insertate(int value) {
        node* newnode = new node;
        newnode->data = value;
        if (head == nullptr) {
            head = tail = newnode;
            newnode->next = newnode->prev = nullptr;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = nullptr;
            tail = newnode;
        }
    }

    void insertatm(int value, int target) {
        if (head == nullptr) return;
        node* temp = head;
        while (temp != nullptr && temp->data != target) temp = temp->next;
        if (temp == nullptr) return;
        node* newnode = new node;
        newnode->data = value;
        newnode->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = newnode;
        else
            tail = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }

    void deletefb() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = tail = nullptr;
            cout << "Deleted!\n";
            return;
        }
        node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        cout << "Deleted!\n";
    }

    void deletefe() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = tail = nullptr;
            cout << "Deleted!\n";
            return;
        }
        node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        cout << "Deleted!\n";
    }

    void deletefm(int target) {
        if (head==nullptr) {
            cout<<"List is empty!\n";
            return;
        }
        node* temp=head;
        while(temp!=nullptr && temp->data!=target) temp = temp->next;
        if (temp==nullptr) {
            cout<<"Target not found in the list!\n";
            return;
        }
        if (temp==head) {
            head=head->next;
            if(head) head->prev=nullptr;
        } else if(temp==tail) {
            tail=tail->prev;
            if(tail) tail->next=nullptr;
        } else {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
        }
        delete temp;
        cout<<"Target deleted!\n";
    }

    void search(int target) {
        if(head==nullptr) {
            cout<<"List is empty!\n";
            return;
        }
        node* temp=head;
        int count=0;
        while(temp!=nullptr&&temp->data!=target) {
            temp=temp->next;
            count++;
        }
        if (temp==nullptr)
            cout<<"Not found in the list!\n";
        else
            cout<<"Found at: "<<count<<" location!\n";
    }

    void display() {
        node* temp=head;
        while(temp!=nullptr) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

