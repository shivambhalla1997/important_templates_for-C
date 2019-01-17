#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>
#include<sstream>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

struct work{
    long long int index;
    long long int start;
    long long int end;
    
};

void sort_by_time_required(struct work* space, long long int i, long long int N)
{
    long long int l=(2*i)+1;
    long long int r=(2*i)+2;
    long long int smallest;
    if(l<N && (space[l].end-space[l].start)<(space[i].end-space[i].start)) // findind the smallest among the 3
        smallest=l;
    else
        smallest=i;
    if(r<N && (space[r].end-space[r].start)<(space[smallest].end-space[smallest].start))
        smallest=r;
    if(smallest!=i)
    {
        struct work a=space[i];
        space[i]=space[smallest];
        space[smallest]=a;
        sort_by_time_required(space,smallest,N);
    }
    return;
}

void Build_heap(struct work* space, long long int N) // build the heap
{
    for(long long int i=(floor(N/2))-1; i>=0;i--)
        sort_by_time_required(space,i,N);
    return;
}

void multiThreading(long long int* arr, long long int N, long long int M)
{
    if(N>=M)
    {
        for(long long int i=0;i<M; i++)
            cout<<i<<" "<<"0"<<endl;
    }
    else
    {
        long long int T=0; //time counter
        struct work* space=(struct work*)malloc(sizeof(struct work)*N);
        for(long long int i=0;i<N;i++)
            {
                space[i].index=i;
                space[i].start=0;
                space[i].end=arr[i];
                cout<<i<<" "<<"0"<<endl;
            }
            Build_heap(space,N);
        for(long long int i=N;i<M;i++)
        {
            T=(space[0].end - space[0].start);
            cout<<space[0].index<<" "<<T<<endl;
            space[0].start=T;
            space[0].end=T+arr[i];
            Build_heap(space,N);
        }
    }
}

int main()
{
    long long int N,M;
    cin>>N>>M;
    long long int* arr=(long long int*)malloc(sizeof(long long int)*M);
    for(long long int i=0;i<M;i++)
        cin>>arr[i];
    multiThreading(arr,N,M);
    return 0;
    
}
