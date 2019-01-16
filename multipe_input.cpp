#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>
#include<sstream>
#include<string>
#include<iostream>

using namespace std;

int main()
{
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
            stringstream ss(str);
        ss>>action>>phone_number>>name;
        cout<<action<<endl;
            
        }
    }
    return 0;
}
