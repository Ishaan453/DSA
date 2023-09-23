#include<iostream>
using namespace std;

int linear(int arr[], int n, int num){
	for(int i=0; i<n; i++){
		if(arr[i] == num){
			return(i+1);
		}
	}
	return(-1);
}

int main(){
	int n=0;
	cout<<"Enter Number of elements in array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements of array"<<endl;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int num=0;
	cout<<"Enter element to be found"<<endl;
	cin>>num;
	int pos = linear(arr, n, num);
	if(pos != -1){
		cout<<"Number found at position "<<pos<<endl;
	}
	else{
		cout<<"Number not found"<<endl;
	}
}
