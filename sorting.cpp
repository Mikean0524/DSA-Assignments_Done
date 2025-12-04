#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int a[n1], b[n2];

    for(int i=0; i<n1; i++)
        a[i] = arr[left + i];
    for(int i=0; i<n2; i++)
        b[i] = arr[mid + 1 + i];

    int i=0, j=0, k=left;

    while(i<n1 && j<n2) {
        if(a[i] <= b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }

    while(i<n1)
        arr[k++] = a[i++];
    while(j<n2)
        arr[k++] = b[j++];
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return (i+1);
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;

    while(left < right) {
        int minIndex = left, maxIndex = right;

        for(int i = left; i <= right; i++) {
            if(arr[i] < arr[minIndex]) minIndex = i;
            if(arr[i] > arr[maxIndex]) maxIndex = i;
        }

        int temp = arr[left];
        arr[left] = arr[minIndex];
        arr[minIndex] = temp;

        if(maxIndex == left)
            maxIndex = minIndex;

        temp = arr[right];
        arr[right] = arr[maxIndex];
        arr[maxIndex] = temp;

        left++;
        right--;
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {8, 3, 1, 5, 9, 2};
    int n = 6;

    cout << "Original Array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}

