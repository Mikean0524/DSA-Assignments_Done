#include <iostream>
using namespace std;

int n;
static int i = 0;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr)
        return createNode(data);
    if (root->left == nullptr)
        root->left = createNode(data);
    else if (root->right == nullptr)
        root->right = createNode(data);
    else
        insert(root->left, data);
    return root;
}


void inorder(Node* root, int arr[]) {
    if (root != nullptr) {
        inorder(root->left, arr);
        arr[i] = root->data;
        i++;
        inorder(root->right, arr);
    }
}

bool isSorted(int arr[], int n) {
    if (n<=1) {
        return true;
    }
    for (int i=1; i<n; i++) {
        if (arr[i]<arr[i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    Node* root = nullptr;
    int data;
    for (int j = 0; j < n; j++) {
        cout << "Enter data for node: ";
        cin >> data;
        root = insert(root, data);
    }

    i=0;
    inorder(root, arr);
    if(isSorted(arr,n)){
    	cout<<"The binary tree is a BST\n";
	}
	else{
		cout<<"The binary tree is not a BST\n";
	}	 
    return 0;
}

