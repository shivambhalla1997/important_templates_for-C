#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>
#include<sstream>
#include<string>
#include<iostream>
#include<vector>
#define mod 1000000007
#define hash_size 10000

using namespace std;

struct compare{
    bool operator()(const pair<long long int,string>& value, const long long int& key)
    {
        return key==value.first;
    }
};

int main()
{
    vector<pair<long long int,string>>hash_table[hash_size]; // creating hash table
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
            
            long long int key=(((phone_number)%mod)%hash_size); //creating the key
            if(action[0]=='a') // during add command
            {
                vector<pair<long long int,string>>::iterator it;
                int flag=0;
                for(it=hash_table[key].begin(); it!=hash_table[key].end(); it++)
                {
                    if(it->first==phone_number)
                    {
                        it->second=name;
                        flag++;
                        break;
                    }
                }
                if(flag==0)
                    hash_table[key].push_back(make_pair(phone_number,name));
            }
            else if(action[0]=='d')
            {
                vector<pair<long long int,string>>::iterator it;
                for(it=hash_table[key].begin(); it!=hash_table[key].end(); it++)
                {
                    if(it->first==phone_number)
                    {
                        hash_table[key].erase(it);
                        break;
                    }
                }
            }
            else
            {
                vector<pair<long long int,string>>::iterator it;
                int flag=0;
                for(it=hash_table[key].begin(); it!=hash_table[key].end(); it++)
                {
                    if(it->first==phone_number)
                    {
                        cout<<it->second<<endl;
                        flag++;
                        break;
                    }
                }
                if(flag==0)
                    cout<<"not found"<<endl;
            }
        }
    }
    return 0;
}
