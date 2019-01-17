#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>
#include<sstream>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

void min_heapify(long long int* arr, long long int i, long long int N, vector<pair<long long int, long long int>>&index)
{
    long long int l=(2*i)+1; // left child of the node
    long long int r=(2*i)+2; // right child of the node
    long long int smallest;
    if(l<=N && arr[l]<arr[i]) // findind the smallest among the 3
        smallest=l;
    else
        smallest=i;
    if(r<=N && arr[r]<arr[smallest])
        smallest=r;
    if(smallest!=i)
    {
        if(smallest==l)
        {
            index.push_back(make_pair(l,i)); // insering the pair
            long long int a=arr[i]; // exchanging the nodes
            arr[i]=arr[smallest];
            arr[smallest]=a;
        }
        else
        {
            index.push_back(make_pair(r,i)); // insering the pair
            long long int a=arr[i]; // exchanging the nodes
            arr[i]=arr[smallest];
            arr[smallest]=a;
        }
        min_heapify(arr,smallest,N,index);
    }
    return;
}

void Build_heap(long long int* arr, long long int N)
{
    vector<pair<long long int, long long int>>index;
    for(long long int i=(floor(N/2))-1; i>=0; i--) // iterating over the array
    {
        min_heapify(arr,i,N,index);
    }
    cout<<index.size()<<endl;
    vector<pair<long long int, long long int>>::iterator it;
    for(it=index.begin(); it!=index.end(); it++)
        cout<<it->second<<" "<<it->first<<endl;
}

int main()
{
    long long int N;
    cin>>N;
    long long int* arr=(long long int*)malloc(sizeof(long long int)*N);
    for(long long int i=0;i<N;i++)
        cin>>arr[i];
    Build_heap(arr,N);    
        
    return 0;
    
}
