#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int min = arr[0];
    int max = arr[0];
    
    for(i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    
    printf("Minimum number: %d\n", min);
    printf("Maximum number: %d\n", max);
    
    return 0;
}