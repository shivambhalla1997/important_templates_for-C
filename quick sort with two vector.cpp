#include <iostream>
#include <vector>
using namespace std;

int Parition(vector<int>&A, vector<int>&B, int start, int end)
{
    int pivot=A[end]/B[end];
    int partition_Index=start;
    for(int i=start;i<end;i++)
    {
        if((A[i]/B[i])<=pivot)
        {
            swap(A[i],A[partition_Index]);
            swap(B[i],B[partition_Index]);
            partition_Index++;
        }
    }
    swap(A[partition_Index],A[end]);
    swap(B[partition_Index],B[end]);
    return partition_Index;
}



void QuickSort_vector(vector<int>&A,vector<int>&B, int start, int end)  // quicksort wrt the ration between the two vectors
{
    if(start<end)
    {
        int partition_Index=Parition(A,B,start,end);
        QuickSort_vector(A,B,start,partition_Index-1);
        QuickSort_vector(A,B,partition_Index+1,end);
    }
}



int main() {
    vector<int>A;
    vector<int>B;
    A.push_back(300);  //first vector
    A.push_back(500);
    A.push_back(800);
    A.push_back(100);
    A.push_back(400);
    
    B.push_back(6);  //second vector
    B.push_back(5);
    B.push_back(2);
    B.push_back(4);
    B.push_back(20);
    
    QuickSort_vector(A,B,0,A.size()-1);
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<" ";
    }

	return 0;
}
