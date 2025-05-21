#include "Utils.h"

int BinarySearch(int *arr, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
    // if(start>end)
    // {
    //     return -1;
    // }
    // int mid = (start + end) / 2;

    // if(arr[mid]==target)
    // {
    //     return mid;
    // }

    // if(arr[mid]>target)
    // {
    //     return Fun(arr,target,start,mid-1);
    // }

    // if (arr[mid] < target)
    // {
    //     return Fun(arr,target,mid+1,end);
    // }
}

int SequentialSearch(int *arr, int target, int start, int end)
{
    for(int i=start; i<=end; i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}