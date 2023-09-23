#include<iostream>
using namespace std;

void linear(int arr[], int n, int num){
	int pos[n];
	int j=0;
	for(int i=0; i<n; i++){
		if(arr[i] == num){
			pos[j] = i+1;
			j++;
		}
	}
	if(j!=0){
		cout<<"Elements found at position ";
		for(int i=0; i<j; i++){
			cout<<pos[i]<<",";
		}
	}
	else{
		cout<<"Elements not found"<<endl;
	}
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
	linear(arr, n, num);
}
