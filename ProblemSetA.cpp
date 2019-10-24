/*Counting Inversions*/
#include<bits/stdc++.h>
using namespace std;
long long int ans=0;
void merge(int arr[],int l, int m, int r){
	int i=l,j=m+1,k=0;
	int temp[r-l+1];
	while(i<=m&&j<=r){
		if(arr[i]<=arr[j]){
			temp[k]=arr[i];
			k++;i++;
		}
		else{
			temp[k]=arr[j];
			k++;j++;
			ans+=(m+1-i);
		}
	}
	while(i<=m){temp[k]=arr[i];k++;i++;}
	while(j<=r){temp[k]=arr[j];k++;j++;}
	for(int x=l;x<=r;x++){arr[x]=temp[x-l];}
}
void mergeSort(int arr[],int l, int r){
	if(l<r){
	int m=l+(r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
	}
}
int main(){
	ifstream fin("IntegerArray .txt");
	int n=100000;
	int arr[n];
	for(int i=0;i<n;i++)fin>>arr[i];
	mergeSort(arr,0,n-1);
	cout<<ans;
	return 0;
}
