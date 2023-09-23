#include<stdio.h>

void selection(int arr[], int len){
	int i,j,min;
	for(i=0; i<len-1; i++){
		min = i;
		
		for(j=i+1; j<len; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		int t = arr[i];
		arr[i] = arr[min];
		arr[min] = t;
		
		printf("Pass %d: ", i+1);
		for(j=0; j<len; j++){
			printf("%d, ", arr[j]);
		}
		printf("\n");
		
	}
}

int main(){
	int len, i;
	printf("Enter length of array: ");
	scanf("%d", &len);
	int arr[len];
	for(i=0; i<len; i++){
		scanf("%d", &arr[i]);
	}
	
	selection(arr, len);
	
	printf("Sorted Array: ");
	for(i=0; i<10; i++){
		printf("%d, ", arr[i]);
	}
}
