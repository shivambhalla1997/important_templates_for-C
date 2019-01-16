#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>
#include<sstream>
#include<string>
#include<iostream>
#include<vector>
#define mod 1000000007
#define hash_size 100000

using namespace std;

int main()
{
    vector<pair<string,long long int>>hash_table[hash_size]; // creating hash table
    memset(hash_table,0,sizeof(hash_table));
    long long int N,phone_number;
    char name[16],action[5];
    cin>>N;
    N++;
    for(long long int i=0;i<N;i++)
    {
        string str;
        getline(cin,str);
        if(i!=0)
        {
            if(str[0]=='a') // when we are adding the number 3 input
            {
                stringstream ss(str);
                ss>>action>>phone_number>>name;
            }
            else  // when deleting and finding only 2 inputs
            {
                stringstream ss(str);
                ss>>action>>phone_number;
            }
            
            
            if(action[0]=='a') // during add command
            {
                long long int key=(((phone_number)%mod)%hash_size);
                hash_table[key].push_back(make_pair(name,phone_number));
            }
        }
    }
    return 0;
}
