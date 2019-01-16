#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>
#include<sstream>
#include<string>
#include<iostream>
#include<vector>
#define mod 1000000007
#define x 263

using namespace std;

int main()
{
    long long int m,N;
    string name,action;
    long long int num;
    cin>>m>>N;
    vector<string>hash_table[m]; // creating hash table
    memset(hash_table,0,sizeof(hash_table));
    N++;
    for(long long int i=0;i<N;i++)
    {
        string str;
        getline(cin,str);
        if(i!=0)
        {
            if(str[0]=='c') // when we are checking 
            {
                stringstream ss(str);
                ss>>action>>num;
            }
            else  // when deleting and finding or inputing
            {
                stringstream ss(str);
                ss>>action>>name;
            }
            
            
            long long int key=0; // key making function
            for(int i=name.size()-1;i>=0;i--)
            {
                key=(key*(x*((int)name[i])))%mod;
            }
            key=key%m;
            
            if(action[0]=='a')
            {
                cout<<key<<endl;
                int flag=0;
                vector<string>::iterator it;
                for(it=hash_table[key].begin(); it!=hash_table[key].end(); it++) //finding the string
                {
                    string str1=*it;
                    if(str1[0]==name[0])
                    {
                        int flag2=0;
                        for(int i=0;i<name.size();i++)
                        {
                            if(str1[i]!=name[i])
                                {
                                    flag2++;
                                    break;
                                }
                        }
                        if(flag2==0)
                        {
                            flag++;
                            break;
                        }
                    }
                }
                if(flag==0)
                    hash_table[key].push_back(name);
            }
            else if(action[0]=='d')
            {
                int flag=0;
                vector<string>::iterator it;
                for(it=hash_table[key].begin(); it!=hash_table[key].end(); it++) //finding the string
                {
                    string str1=*it;
                    if(str1[0]==name[0])
                    {
                        int flag2=0;
                        for(int i=0;i<name.size();i++)
                        {
                            if(str1[i]!=name[i])
                                {
                                    flag2++;
                                    break;
                                }
                        }
                        if(flag2==0)
                        {
                            hash_table[key].erase(it);
                            flag++;
                            break;
                        }
                    }
                }
                
            }
            else if(action[0]=='f')
            {
                int flag=0;
                vector<string>::iterator it;
                for(it=hash_table[key].begin(); it!=hash_table[key].end(); it++) //finding the string
                {
                    string str1=*it;
                    if(str1[0]==name[0])
                    {
                        int flag2=0;
                        for(int i=0;i<name.size();i++)
                        {
                            if(str1[i]!=name[i])
                                {
                                    flag2++;
                                    break;
                                }
                        }
                        if(flag2==0)
                        {
                            cout<<"yes"<<endl;
                            flag++;
                            break;
                        }
                    }
                }
                if(flag==0)
                    cout<<"no"<<endl;
            }
            else
            {
                if(hash_table[key].size()==0)
                {
                    cout<<endl;
                }
                else
                {
                    vector<string>::reverse_iterator it;
                    for(it=hash_table[key].rbegin(); it!=hash_table[key].rend(); it++) //print the entire row
                        cout<<*it<<" ";
                    cout<<endl;    
                }
            }
        }
    }
    return 0;
}
