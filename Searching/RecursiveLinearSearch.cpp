#include<iostream>
using namespace std;

void linear(int arr[], int n, int num){
	static int i=0;
	int flag = 0;
	if(i > n){
		if(flag == 1){
			cout<<"Element not found"<<endl;
		}
	}
	else{
		if(arr[i] == num){
			cout<<i+1<<",";
			flag = 1;
		}	
		i=i+1;
		linear(arr, n, num);
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
	cout<<"Elements found at ";
	linear(arr, n, num);
}
