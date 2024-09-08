#include <stdio.h>
int binarySearch(int arr[], int n, int key) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (right + left) / 2;

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
return -1; 
}

int main() {

int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the elements:\n");
	
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	int key;

	printf ("Enter key to search: ");
	scanf ("%d",&key);
	int binaryResult = binarySearch(arr, n, key);


	if (binaryResult != -1)
		printf("Binary Search: Element found at index %d\n", binaryResult);
	else
		printf("Binary Search: Element not found\n");

return 0;
}
