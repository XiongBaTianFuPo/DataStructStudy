#include <stdio.h>
#include "LinkList.h"
#include "Stack.h"


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

void TestLinkList()
{
    int arr[]={1,2,3,4,5,6};
    int a=6;
    BOOL d;
    pLinkList list=LinkListCreate(arr, a);
    LinkListPrint(list);
    d=LinkListInsert(list,7,6);
    LinkListPrint(list);
    // int b=LinkListGet(list,3);
    printf("%d\n",d);
    //BOOL c=LinkListRemove(list,3);
    //printf("%d\n",c);
    // LinkListPrint(list);
    LinkListFree(list);
}

void TestStack()
{
    int arr[]={1,2,3,4,5,6};
    pStack stack=StackCreate();
    for(int i=0;i<6;i++)
    {
        StackPush(stack,arr[i]);
    }
    StackPrint(stack);
    printf("pre_len: %d\n",StackGetLen(stack));
    printf("pop: %d\n", StackPop(stack));
    printf("post_len: %d\n",StackGetLen(stack));
    StackPrint(stack);
}

int main()
{
    // TestLinkList();
    TestStack();
    return 0;
}