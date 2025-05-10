#include <stdio.h>
#include "LinkList.h"

int Fun(int *arr, int target, int start, int end)
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

int main()
{
    int arr[]={1,2,3,4,5,6};
    int a=6;
    BOOL d;
    pLinkList list=CreateLinkList(arr, a);
    PrintLinkList(list);
    d=InsertLinkList(list,7,6);
    PrintLinkList(list);
    // int b=GetLinkList(list,3);
    printf("%d\n",d);
    //BOOL c=RemoveLinkList(list,3);
    //printf("%d\n",c);
    // PrintLinkList(list);
    FreeLinkList(list);

    return 0;
}