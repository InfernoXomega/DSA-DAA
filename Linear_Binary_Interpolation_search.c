#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Element not found
}

// Binary Search (Assumes the array is sorted)
int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return -1; // Element not found
}

// Interpolation Search (Assumes the array is uniformly distributed)
int interpolationSearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right && key >= arr[left] && key <= arr[right]) {
        int pos = left + ((key - arr[left]) * (right - left) / (arr[right] - arr[left]));
        
        if (arr[pos] == key) {
            return pos;
        }
        if (arr[pos] < key) {
            left = pos + 1;
        }
        else {
            right = pos - 1;
        }
    }
    
    return -1; // Element not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf ("Enter key to search: ");
    scanf ("%d",&key);
    int linearResult = linearSearch(arr, n, key);
    int binaryResult = binarySearch(arr, n, key);
    int interpolationResult = interpolationSearch(arr, n, key);
    
    if (linearResult != -1)
        printf("Linear Search: Element found at index %d\n", linearResult);
    else
        printf("Linear Search: Element not found\n");
    
    if (binaryResult != -1)
        printf("Binary Search: Element found at index %d\n", binaryResult);
    else
        printf("Binary Search: Element not found\n");
    
    if (interpolationResult != -1)
        printf("Interpolation Search: Element found at index %d\n", interpolationResult);
    else
        printf("Interpolation Search: Element not found\n");
    
    return 0;
}
