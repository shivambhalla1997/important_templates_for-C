#include<stdio.h>
#include<algorithm>
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

void buildHeap(long long int* arr, long long int N)
{
    long long int count=0; //total number of swaps
    vector<pair<long long int,long long int>> index; //vector of parirs to store the pair of indexes
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); //fast input 
    
    long long int N;
    cin>>N;
    long long int* arr=(long long int*)malloc(sizeof(long long int*)*N);
    for(long long int i=0;i<N;i++)
        cin>>arr[i];
    buildHeap(arr,N);    
    return 0;
}
