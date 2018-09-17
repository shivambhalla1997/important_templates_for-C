#include <iostream>
#include <vector>
using namespace std;

int Parition(int *arr, int start, int end)  // for array
{
    int pivot=arr[end];
    int partition_Index=start;
    for(int i= start; i< end ; i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i],arr[partition_Index]);
            partition_Index++;
        }
    }
    swap(arr[partition_Index],arr[end]);
    return partition_Index;
}

void QuickSort_array(int *arr, int start, int end)  //Quick Sort function for array
{
    if(start<end)
    {
        int partition_Index=Parition(arr,start,end);
        QuickSort_array(arr,start,partition_Index-1);
        QuickSort_array(arr,partition_Index+1,end);
    }
}



int main() {
	int arr[]={3,5,8,1,4,-1,-10,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	QuickSort_array(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
	    cout<<arr[i]<<" ";
	}
    
	return 0;
}
