#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; 
    }
    return -1;
}

int insertElement(int arr[], int *n, int position, int element) {
    if (position < 0 || position > *n || *n >= 100) {
        printf("Invalid position for insertion!\n");
        return -1;
    }

    for (int i = *n - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    arr[position] = element;
    (*n)++;
    return 1;
}

int deleteElement(int arr[], int *n, int position) {
    if (position < 0 || position >= *n) {
        printf("Invalid position for deletion!\n");
        return -1;
    }

    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
    return 1;
}

int main() {
    int arr[100];
    int n = 0;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    if (n > 100) {
        printf("The maximum number of elements allowed is 100.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    int key;
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);
    if (result != -1) {
        printf("Element %d found at position %d\n", key, result + 1);
    } else {
        printf("Element not found in the list.\n");
    }

    printf("Enter the position for insertion: ");
    int insertPosition;
    scanf("%d", &insertPosition);

    printf("Enter the element to insert: ");
    int insertElementValue;
    scanf("%d", &insertElementValue);

    if (insertElement(arr, &n, insertPosition - 1, insertElementValue) != -1) {
        printf("Element inserted successfully.\n");
        printf("Updated list:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    printf("Enter the position for deletion: ");
    int deletePosition;
    scanf("%d", &deletePosition);

    if (deleteElement(arr, &n, deletePosition - 1) != -1) {
        printf("Element deleted successfully.\n");
        printf("Updated list:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
