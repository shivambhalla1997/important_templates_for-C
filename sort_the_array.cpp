#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
    int arr[]={3,4,2,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,greater<int>()); // sort the array in desending order
    sort(arr,arr+n); // sorting array in ascending array
    
    
    for(int i=0; i<n; i++) //printing the array
    cout<<arr[i]<<" ";
    return 0;
}
