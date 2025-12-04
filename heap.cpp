#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool increasing) {
    int root = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (increasing) {
        if (left < n && arr[left] > arr[root]) root = left;
        if (right < n && arr[right] > arr[root]) root = right;
    } else {
        if (left < n && arr[left] < arr[root]) root = left;
        if (right < n && arr[right] < arr[root]) root = right;
    }

    if (root != i) {
        swap(arr[i], arr[root]);
        heapify(arr, n, root, increasing);
    }
}

void heapSort(int arr[], int n, bool increasing) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    heapSort(arr, n, true);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n, false);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

