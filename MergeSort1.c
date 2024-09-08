#include <stdio.h>
#include <stdlib.h>
#define N 10

void merge(int arr[], int start, int mid, int end){
	int temp[N];
	int i=start, j=mid+1, k=start;
	while(i<=mid && j<=end){
		if(arr[i]>arr[j]) temp[k++]=arr[j++];
		else temp[k++]=arr[i++];
	}
	while(i<=mid){
		temp[k++]=arr[i++];
	}
	while(j<=end){
		temp[k++]=arr[j++];
	}
	for(int p=start; p<=end; p++){
		arr[p]=temp[p];
	}
}

void mergeSort(int arr[], int start, int end){
	if(start<end){
		int mid = start + (end-start)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}

int main(){
	int n, arr[N];
	printf("Enter number of elements: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	mergeSort(arr, 0, n-1);
	
	printf("Sorted array: ");
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
