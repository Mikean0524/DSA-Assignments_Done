#include <iostream>
#include <string.h>
using namespace std;
/* QUESTION 1.
int main(){
	
	cout<<"Enter how many elements you want to add: ";
	int n;
	cin>>n;
	int stack[n];
	int menu;
	int top=0;
	int i;
	do{
		cout<<"\n-------STACK MENU-------\n";
		cout<<"1.Push\n";
		cout<<"2.Pop\n";
		cout<<"3.Display\n";
		cout<<"4.Peek\n";
		cout<<"5.Exit\n";
		cout<<"What do you want to do: ";
		cin>>menu;
		switch(menu){
			case 1:
				if(top==n){
					cout<<"STACK IS FULL!\n";
					break;
				}
				else{
					cout<<"Enter the number: ";
					cin>>stack[top];
					top++;
					break;
				}
			case 2:
				if(top==0){
					cout<<"STACK IS EMPTY\n";
					break;
				}
				else{
					cout<<"This element is deleted: "<<stack[top-1];
					top--;
					break;
				}
			case 3:
				if(top==0){
					cout<<"STACK IS EMPTY\n";
					break;
				}
				else{
					for(i=top-1;i>=0;i--){
						cout<<stack[i]<<endl;
					}
					break;
				}
			case 4:
				if(top==0){
					cout<<"STACK IS EMPTY\n";
					break;
				}
				else{
					cout<<stack[top-1];
					break;
				}
			case 5:
				menu=5;
				cout<<"\n-------EXITING-------\n";
				break;
		}
		}while(menu!=5);
	
	
	
	
	
	
	return 0;
}*/






/* QUESTION 2
int main(){
	cout<<"Enter how many elements you want: ";
	int n;
	cin>>n;
	char stack[n];
	int menu;
	int top=0;
	int i;
	do{
		cout<<"\n-------STACK MENU-------\n";
		cout<<"1.Push\n";
		cout<<"2.Pop\n";
		cout<<"3.Display\n";
		cout<<"4.Peek\n";
		cout<<"5.Exit\n";
		cout<<"What do you want to do: ";
		cin>>menu;
		switch(menu){
			case 1:
				if(top==n){
					cout<<"STACK IS FULL!\n";
					break;
				}
				else{
					cout<<"Enter the letter: ";
					cin>>stack[top];
					top++;
					break;
				}
			case 2:
				if(top==0){
					cout<<"STACK IS EMPTY\n";
					break;
				}
				else{
					cout<<"This element is deleted: "<<stack[top-1];
					top--;
					break;
				}
			case 3:
				if(top==0){
					cout<<"STACK IS EMPTY\n";
					break;
				}
				else{
					for(i=top-1;i>=0;i--){
						cout<<stack[i];
					}
					cout<<endl;
					break;
				}
			case 4:
				if(top==0){
					cout<<"STACK IS EMPTY\n";
					break;
				}
				else{
					cout<<stack[top-1];
					break;
				}
			case 5:
				menu=5;
				cout<<"\n-------EXITING-------\n";
				break;
		}
		}while(menu!=5);
	
	
	
	
	
	
	return 0;
}*/

/*int main(){
	cout<<"Enter how many strings you want: ";
	int n;
	cin>>n;
	//cout<<"Enter how many elements you want: ";
	//int e;
	//cin>>e;
	char stack[n][10];
	int menu;
	int top=0;
	int i;
	do{
		cout<<"\n-------STACK MENU-------\n";
		cout<<"1.Push\n";
		cout<<"2.Pop\n";
		cout<<"3.Display\n";
		cout<<"4.Peek\n";
		cout<<"5.Exit\n";
		cout<<"What do you want to do: ";
		cin>>menu;
		if(menu>=6){
			cout<<"Enter valid query!\n";
		}
		switch(menu){
			case 1:
				if(top==n){
					cout<<"STACK IS FULL!\n";
					break;
				}
				else{
					cout<<"Enter the word: ";
					cin>>stack[top];
					top++;
					break;
				}
			case 2:
				if(top==0){
					cout<<"STACK IS EMPTY\n";
					break;
				}
				else{
					cout<<"This element is deleted: "<<stack[top-1];
					top--;
					break;
				}
			case 3:
				if(top==0){
					cout<<"STACK IS EMPTY\n";
					break;
				}
				else{
					for(i=top-1;i>=0;i--){
						cout<<stack[i]<<" ";
					}
					cout<<endl;
					break;
				}
			case 4:
				if(top==0){
					cout<<"STACK IS EMPTY\n";
					break;
				}
				else{
					cout<<stack[top-1];
					break;
				}
			case 5:
				menu=5;
				cout<<"\n-------EXITING-------\n";
				break;
		}
		}while(menu!=5);
	
	
	
	
	
	
	return 0;
}*/
/*
Question 3.
int main(){
	string n;
	int right=0;
	int left=0;
	
	cout<<"Enter your expression: ";
	getline(cin,n);
	for(int i=0;i<n.length();i++){
		if(n[i]=='('){
			right++;
		}
		if(n[i]==')'){
			left++;
		}
			
	}
	if(right==left){
		cout<<"All the parenthesis are closed!";
	}
	else{
		cout<<"all the parenthesis aren't closed!";
	}
}*/

/*
Question 5.
const int n = 10;
int stack[n]; 
int top = 0;

void display() {
    if (top == 0) {
        cout << "STACK IS EMPTY\n";
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

void push(int a) {
    if (top == n) {
        cout << "STACK IS FULL!\n";
    } else {
        stack[top] = a;
        top++;
    }
}

int pop() {
    if (top == 0) {
        cout << "STACK IS EMPTY\n";
        return -1;
    } else {
        top--;
        return stack[top];
    }
}

void peek() {
    if (top == 0) {
        cout << "STACK IS EMPTY\n";
    } else {
        cout << stack[top - 1] << endl;
    }
}

int main() {
    cout << "Enter the postfix expression: ";
    string exp;
    getline(cin, exp);

    for (int i = 0; i < exp.length(); i++) {
        char c= exp[i];

        if (isdigit(c)) {
            push(c- '0');
        } else if (c == '+' || c == '-' || c == '/' || c == '*') {
            int a = pop();
            int b = pop();
            int result;

            if (a == -1 || b == -1) {
                cout << "Invalid expression: not enough operands for operator " << c << endl;
                return 1;
            }

            switch (c) {
                case '+':
                    result = b + a;
                    break;
                case '-':
                    result = b - a;
                    break;
                case '/':
                    if (a == 0) {
                        cout << "Error: Division by zero." << endl;
                        return 1;
                    }
                    result = b / a;
                    break;
                case '*':
                    result = b * a;
                    break;
            }
            push(result);
        }
    }
    
    if (top == 1) {
        cout << "Result: " << pop() << endl;
    } else {
        cout << "Invalid expression: too many operands or not enough operators." << endl;
    }

    return 0;
}*/

