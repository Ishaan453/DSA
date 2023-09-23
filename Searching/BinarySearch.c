#include<stdio.h>

void binSearch(int arr[], int len, int num){
	int l=0, u=len-1;
	while(l<=u){
		int mid=(l+u)/2;
		if(arr[mid] == num){
			printf("Number found at position: %d", mid+1);
			break;
		}
		
		else if(arr[mid] > num){
			u = mid-1;
		}
		else if(arr[mid] < num){
			l = mid+1;
		}
	}
	if(l>u){
		printf("Number not found");
	}
}

void recBin(int arr[], int l, int u, int num){
	int mid = (l+u)/2;
	if(l>u){
		return;
	}
	if(arr[mid] == num){
		printf("Number found at position: %d", mid+1);
		return;
	}
	else if(arr[mid] > num){
		u = mid-1;
		recBin(arr, l, u, num);
	}
	else if(arr[mid] < num){
		l = mid+1;
		recBin(arr, l, u, num);
	}
}

int main(){
	int len, i;
	printf("Enter length of array: ");
	scanf("%d", &len);
	int arr[len];
	printf("Enter elements of array in  ascending order: ");
	for(i=0; i<len; i++){
		scanf("%d", &arr[i]);
	}
	
	int num=0;
	printf("Enter number to be searched: ");
	scanf("%d", &num);
	
	int ch=0;
	printf("Enter 1 for normal Binary Search or 2 for recursive binary search: ");
	scanf("%d", &ch);
	
	switch(ch){
		case 1: binSearch(arr, len, num);
				break;
		
		case 2: recBin(arr, 0, len-1, num);
	}
}
