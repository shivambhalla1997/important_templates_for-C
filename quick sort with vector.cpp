#include <iostream>
#include <vector>
using namespace std;

int Parition(vector<int>&A, int start, int end)
{
    int pivot=A[end];
    int partition_Index=start;
    for(int i=start;i<end;i++)
    {
        if(A[i]<=pivot)
        {
            swap(A[i],A[partition_Index]);
            partition_Index++;
        }
    }
    swap(A[partition_Index],A[end]);
    return partition_Index;
}


void QuickSort_vector(vector<int>&A, int start, int end)
{
    if(start<end)
    {
        int partition_Index=Parition(A,start,end);
        QuickSort_vector(A,start,partition_Index-1);
        QuickSort_vector(A,partition_Index+1,end);
    }
}




int main() {
    vector<int>A;
    A.push_back(3);
    A.push_back(5);
    A.push_back(8);
    A.push_back(1);
    A.push_back(4);
    A.push_back(-1);
    A.push_back(0);
    A.push_back(15);

    QuickSort_vector(A,0,A.size()-1);
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<" ";
    }

	return 0;
}
