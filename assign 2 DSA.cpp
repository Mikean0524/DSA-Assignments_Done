#include <iostream>
#include <string.h>


using namespace std;

/* QUESTION 1: Binary Search
int main() {
    int arr[100], n, i, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " sorted elements:\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to search: ";
    cin >> key;

    int low = 0, high = n - 1, mid;
    int found = 0;
    int pos = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            found = 1;
            pos = mid;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found == 1) {
        cout << "Element found at position " << pos << ".\n";
    } else {
        cout << "Element not found in the array.\n";
    }

    return 0;
}
*/


/* QUESTION 2: Bubble Sort
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array is: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
*/


/* QUESTION 3(a): Find Missing Number (Linear Time)
int main() {
    int arr[100], n, i;
    cout << "Enter the size of the array (n-1): ";
    cin >> n;
    cout << "Enter " << n << " distinct sorted elements from 1 to " << n + 1 << ":\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            cout << "The missing number is " << i + 1 << ".\n";
            return 0;
        }
    }

    cout << "The missing number is " << n + 1 << ".\n";

    return 0;
}
*/


/* QUESTION 3(b): Find Missing Number (Binary Search)
int main() {
    int arr[100], n, i;
    cout << "Enter the size of the array (n-1): ";
    cin >> n;
    cout << "Enter " << n << " distinct sorted elements from 1 to " << n + 1 << ":\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 0, high = n - 1, mid;
    int ans = n + 1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            ans = mid + 1;
            high = mid - 1;
        }
    }

    cout << "The missing number is " << ans << ".\n";

    return 0;
}
*/


/* QUESTION 4(a): Concatenate Strings
int main() {
    char str1[100], str2[100];
    int i, j;

    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    i = 0;
    while (str1[i] != '\0') {
        i++;
    }

    j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';

    cout << "The concatenated string is: " << str1 << endl;

    return 0;
}
*/


/* QUESTION 4(b): Reverse String
int main() {
    char str[100], temp;
    int i, j;

    cout << "Enter a string: ";
    cin >> str;

    j = 0;
    while(str[j] != '\0'){
        j++;
    }
    j = j - 1;

    i = 0;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    cout << "The reversed string is: " << str << endl;

    return 0;
}
*/


/* QUESTION 4(c): Delete Vowels
int main() {
    char str[100], result[100];
    int i, j = 0;

    cout << "Enter a string: ";
    cin >> str;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            result[j] = str[i];
            j++;
        }
    }
    result[j] = '\0';

    cout << "String after deleting vowels: " << result << endl;

    return 0;
}
*/


/* QUESTION 4(d): Sort Strings
int main() {
    char str[10][50], temp[50];
    int i, j, n;

    cout << "Enter the number of strings: ";
    cin >> n;

    cout << "Enter " << n << " strings:\n";
    for (i = 0; i < n; i++) {
        cin >> str[i];
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (i = 0; i < n; i++) {
        cout << str[i] << endl;
    }

    return 0;
}
*/


/* QUESTION 4(e): Uppercase to Lowercase
int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
        cout << "The lowercase character is: " << ch << endl;
    } else {
        cout << "The character is not an uppercase letter.\n";
    }

    return 0;
}
*/




/* QUESTION 7: Count Inversions
int main() {
    int arr[100], n, i, j;
    int count = 0;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }

    cout << "The number of inversions is: " << count << endl;

    return 0;
}
*/


/* QUESTION 8: Count Distinct Elements
int main() {
    int arr[100], n, i, j;
    int count = 0;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n; i++) {
        int is_distinct = 1;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                is_distinct = 0;
                break;
            }
        }
        if (is_distinct == 1) {
            count++;
        }
    }

    cout << "The total number of distinct elements is: " << count << endl;

    return 0;
}
*/



