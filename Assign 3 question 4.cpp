#include <iostream>
using namespace std;
#include<stack>
int prec(char c){
	if(c=='*'||c=='/'){
		return 2;
	}
	if(c=='+'||c=='-'){
		return 1;
	}
	return -1;
}
int main(){
	string infix;
	cout<<"Enter the expression: ";
	cin>>infix;
	string postfix="";
	stack<char> s;
	s.push('(';
	postfix=postfix+")";
	for(char c:infix){
		if(c=='('){
			s.push(c);
		}
		else if(isalnum(c)){
			postfix=postfix+c;
		}
		else if(c==')'){
			while(!s.empty()&&s.top()!='('){
				postfix=postfix+s.top();
				s.pop();
			}
			s.pop();
		}
		else{
			while(!s.empty()&&prec(s.top())>=prec(c)){
				postfix=postfix+s.top();
				s.pop();
			}
			s.push(c);
		}
		
		
	}
	cout<<"Postfix: "<<postfix;
	return 0;
}
