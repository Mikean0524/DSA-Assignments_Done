#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
class LinkedList{
	Node* head;
	public:
		LinkedList(){
			head=nullptr;
		}
		void insertAtB(int value){
			Node* newnode=new Node;
			newnode->data=value;
			newnode->next=head;
			head=newnode;
		}
		void insertAtE(int value){
			Node* newnode=new Node;
			newnode->data=value;
			newnode->next=nullptr;
			if(head==nullptr){
				head=newnode;
				return;
			}
			Node* current=head;
			while(current->next!=nullptr){
				current=current->next;
			}
			current->next=newnode;
		}
		void insertInB(int value, int target,bool after){
			Node* current=head;
			if(head==nullptr){
				cout<<"List is empty!\n";
				return;
			}
			if(after){
				while(current!=nullptr&&current->data!=target){
					current=current->next;
				}
				if(current==nullptr){
					cout<<"Target not found!\n";
					return;
				}
				Node* newnode=new Node;
				newnode->data=value;
				newnode->next=current->next;
				current->next=newnode;
			}
			else{
				if(head->data==target){
					Node* newnode=new Node;
					newnode->data=value;
					newnode->next=head;
					head=newnode;
					return;
				}
				Node* prev=head;
				while(prev->next!=nullptr&&prev->next->data!=target){
					prev=prev->next;
				}
				if(prev->next==nullptr){
					cout<<"The target not found in the list!\n";
					return;
				}
				Node* newnode=new Node;
				newnode->data=value;
				newnode->next=prev->next;
				prev->next=newnode;
			}
		}
		void deleteFB(){
			if(head==nullptr){
				cout<<"List is empty!\n";
				return;
			}
			Node* temp=head;
			head=head->next;
			delete temp;
		}		
		void deleteFE(){
			if(head==nullptr){
				cout<<"The list is empty!\n";
				return;
			}
			if(head->next==nullptr){
				delete head;
				head=nullptr;
				return;
			}
			Node* current=head;
			while(current->next->next!=nullptr){
				current=current->next;
			}
			delete current->next;
			current->next=nullptr;
		}
		void deleteSN(int value){
			if(head==nullptr){
				cout<<"List is empty!\n";
				return;
			}
			if(head->data==value){
				Node* temp=head;
				head=head->next;
				delete temp;
				return;
			}
			Node* current=head;
			while(current->next!=nullptr&&current->next->data!=value){
				current=current->next;
			}
			if(current->next==nullptr){
				cout<<"Node not found\n";
				return;
			}
			Node* temp=current->next;
			current->next=temp->next;
			delete temp;
		}
		void search(int value){
			int pos=0;
			Node* current=head;
			if(head==nullptr){
				cout<<"The list is empty!\n";
				return;
			}
			while(current!=nullptr){
				if(current->data==value){
					cout<<"Target found at position: "<<pos+1<<endl;
					return;
				}
				current=current->next;
				pos++;
			}
			cout<<"Not found in the list!\n";
		}
		void display(){
			if(head==nullptr){
				cout<<"List is empty!\n";
				return;
			}
			Node* current=head;
			while(current!=nullptr){
				cout<<current->data<<"->";
				current=current->next;
			}
			cout<<"nullptr\n;";
		}
		void reverse(){
			if(head==nullptr){
				cout<<"List is empty!\n";
				return;
			}
			Node*prev=nullptr;
			Node*current=head;
			Node*next=nullptr;
			while(current!=nullptr){
				next=current->next;
				current->next=prev;
				prev=current;
				current=next;
			}
			head=prev;
			cout<<"Linked list is successfully reversed!\n";
		}
		void occur(int value){
			int count=0;
			if(head==nullptr){
				cout<<"List is Empty!\n";
				return;
			}
			Node* prev=nullptr;
			Node* current=head;
			while(current!=nullptr){
				if(current->data==value){
					count++;
					if(current==head){
						Node* temp=head;
						head=head->next;
						current=head;
						delete temp;
					}
					else{
						prev->next=current->next;
						Node* temp=current;
						current=current->next;
						delete temp;
					}
					
				}
				else{
					prev=current;
					current=current->next;
				}
			}
			if(head==nullptr){
				cout<<"Count: "<<count<<" ,list is emptied!\n";
				return;
			}
			current=head;
			cout<<"Count: "<<count<<", ";
			while(current!=nullptr){
				cout<<current->data<<"->";
				current=current->next;
			}
			cout<<"nullptr\n";
			
		}
		void middle(){
			int n=0;
			if(head==nullptr){
				cout<<"The list is empty!\n";
				return;
			}
			Node* current=head;
			while(current!=nullptr){
				n++;
				current=current->next;
			}
			current=head;
			int temp=0;
			if(n%2!=0){
				while(temp!=(n/2)){
					temp++;
					current=current->next;
				}
				cout<<"The middle value is: "<<current->data<<endl;
				return;
			}
			if(n%2==0){
				cout<<"The number of Nodes are even, can't find middle term.\n";
				return;
			}
			
		}
};

int main() {
    LinkedList list;
    int choice, value, target;
    bool after;

    do {
        cout<<"\nMenu:" << endl;
        cout<<"1. Insert at the beginning" << endl;
        cout<<"2. Insert at the end" << endl;
        cout<<"3. Insert in between (before/after a specific node)" << endl;
        cout<<"4. Delete from the beginning" << endl;
        cout<<"5. Delete from the end" << endl;
        cout<<"6. Delete a specific node" << endl;
        cout<<"7. Search for a node" << endl;
        cout<<"8. Display all nodes" << endl;
        cout<<"9. Reverse the linked list" << endl;
        cout<<"10.Delete the reoccuring ones"<<endl;
        cout<<"11.Middle of the Linked list"<<endl;
        cout<<"0. Exit" << endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtB(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtE(value);
                break;
            case 3:
                cout << "Enter new value to insert: ";
                cin >> value;
                cout << "Enter target value: ";
                cin >> target;
                cout << "Insert after (1 for yes, 0 for no)? ";
                cin >> after;
                list.insertInB(value, target, after);
                break;
            case 4:
                list.deleteFB();
                break;
            case 5:
                list.deleteFE();
                break;
            case 6:
                cout << "Enter value of node to delete: ";
                cin >> value;
                list.deleteSN(value);
                break;
            case 7:
                cout << "Enter value of node to search: ";
                cin >> value;
                list.search(value);
                break;
            case 8:
                list.display();
                break;
            case 9:
                list.reverse();
                break;
            case 10:
            	int key;
            	cout<<"Enter the key: ";
            	cin>>key;
            	list.occur(key);
            	break;
            case 11:
            	list.middle();
            	break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
