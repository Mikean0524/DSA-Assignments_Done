#include<iostream>
#include <string.h>
using namespace std;
 

const int n = 10;
int queue[n]; 
int i = 0;
int j=0;
void enqueue(){
	if (i == n) {
        cout << "QUEUE IS FULL!\n";
    } else {
    	cout<<"Enter the number: ";
    	cin>> queue[i];
        i++;
    }
}
void dequeue(){
	if (j == n||j==i) {
        cout << "QUEUE IS EMPTY\n";
        
    } else {
        
        cout<< queue[j]<<" is deleted.\n";
        j++;
    }
}
void display(){
	if (j == n||j==i) {
        cout << "QUEUE IS EMPTY\n";
    }
    else{
    	for(int k=j;k<i;k++){
		cout<<queue[k]<<" ";
	}
	}
	
}
void peek(){
	if (j == n||j==i) {
        cout << "QUEUE IS EMPTY\n";
    }
    else{
    	cout<<queue[j];
	}
}
/*
Q1.
int main(){
	int menu;
	do{
		cout<<"\n-------QUEUE MENU-------\n";
		cout<<"1.enqueue\n";
		cout<<"2.dequeue\n";
		cout<<"3.Display\n";
		cout<<"4.Peek\n";
		cout<<"5.Exit\n";
		cout<<"What do you want to do: ";
		cin>>menu;
		switch(menu){
			case 1:
				enqueue();
				break;
				
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
				
			case 4:
				peek();
				break;
			case 5:
				menu=5;
				cout<<"\n-------EXITING-------\n";
				break;
		}
		}while(menu!=5);
		return 0;
}
*/







void interleaveDisplay() {
    if (j == i) {
        cout << "QUEUE IS EMPTY\n";
        return;
    }

    int size = i - j;
    if (size % 2 != 0) {
        cout << "Odd number of elements! Cannot interleave.\n";
        return;
    }

    cout << "Interleaved output is: ";
    int front = j;
    int rear = j + size / 2;

    while (front < j + size / 2) {
        cout << queue[front] << " " << queue[rear] << " ";
        front++;
        rear++;
    }
    cout << "\n";
}



int main() {
    int menu;
    do {
        cout << "\n-------QUEUE MENU-------\n";
        cout << "1.Enqueue\n";
        cout << "2.Dequeue\n";
        cout << "3.Display (normal)\n";
        cout << "4.Peek\n";
        cout << "5.Interleave Display\n";
        cout << "6.Exit\n";
        cout << "What do you want to do: ";
        cin >> menu;

        switch (menu) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: interleaveDisplay(); break;
            case 6: cout << "\n-------EXITING-------\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (menu != 6);

    return 0;
}

