#include<stdio.h>

void insert(int a[], int n){  
    int i, j, temp;  
    for (i = 1; i < n; i++) {  
        temp = a[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= a[j]) {    
            a[j+1] = a[j];     
            j = j-1;    
        }    
        a[j+1] = temp;    
        
        printf("Pass %d: ", i);
		for(j=0; j<n; j++){
			printf("%d, ", a[j]);
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
	
	insert(arr, len);

	for(i=0; i<10; i++){
		printf("%d, ", arr[i]);
	}
}
