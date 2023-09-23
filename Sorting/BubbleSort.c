#include<stdio.h>

void bubblesort(int arr[], int len){
	int i,j;
	for(i=0; i<len; i++){
		for(j=0; j<len-i; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(){
	int len, i;
	printf("Enter length of array: ");
	scanf("%d", &len);
	int arr[len];
	printf("Enter elements of array: ");
	for(i=0; i<len; i++){
		scanf("%d", &arr[i]);
	}
	bubblesort(arr, len);
	printf("Sorted Array: ");
	for(i=0; i<len; i++){
		printf("%d, ", arr[i]);
	}
}
