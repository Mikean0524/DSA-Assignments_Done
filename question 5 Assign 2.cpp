#include <iostream>
using namespace std;
/*int main(){
	int n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	int arr[n]={};
	for(int i=0;i<n;i++){
		cout<<"Enter the numbers row-wise: \n";
		cin>>arr[i];
	}
	for(int row=0;row<n;row++){
		for(int col=0;col<n;col++){
			if(row==col){
				cout<<arr[row]<<" ";
				
			}
			else{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
	return 0;
}
*/


/*
int main() {
    int n;
    cout << "Enter the number of rows (n): ";
    cin >> n;


    int size = 3 * n - 2;
    int arr[size];
    
    cout << "Enter the " << size << " elements for the tridiagonal matrix:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int k = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row == col || row + 1 == col || col + 1 == row) {
                if (k < size) {
                    cout << arr[k] << " ";
                    k++;
                }
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}*/
int main() {
    int n;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    int size=0;
    while(n>0){
    	size=size+n;
    	n--;
	}
    int arr[size];
    cout << "Enter the " << size << " elements for the tridiagonal matrix:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int k = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row == col || row<col) {
                if (k < size) {
                    cout << arr[k] << " ";
                    k++;
                }
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
