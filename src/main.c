#include <stdio.h>
#include "LinkList.h"
#include "QueueLinkList.h"
#include "QueueArr.h"
#include "Stack.h"
#include "BiTree.h"


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
    StackFree(stack);
}

void TestQueueLinkList()
{
    int arr[] = {1,2,3,4,5,6};
    int len = sizeof(arr) / sizeof(int);
    pQueueLinkList queue = QueueLinkListCreate();
    for (int i = 0; i < len; ++i)
    {
        QueueLinkListPush(queue, arr[i]);
    }
    QueueLinkListPrint(queue);
    int front = QueueLinkListFront(queue);
    int pop = QueueLinkListPop(queue);
    int now_len = QueueLinkListGetLen(queue);
    printf("remove: %d == %d, queue length: %d\n", front, pop, now_len);
    QueueLinkListPrint(queue);
    QueueLinkListFree(queue);
}

// void TestQueueArr()
// {
//     int arr[] = {1,2,3,4,5,6};
//     int len = sizeof(arr) / sizeof(int);
//     pQueueArr queue = QueueArrCreate();
//     for (int i = 0; i < len; ++i)
//     {
//         QueueArrPush(queue, arr[i]);
//     }
//     QueueArrPrint(queue);
//     int front = QueueArrFront(queue);
//     int pop = QueueArrPop(queue);
//     int now_len = QueueArrGetLen(queue);
//     printf("remove: %d == %d, queue length: %d\n", front, pop, now_len);
//     QueueArrPrint(queue);
//     for (int i = 0; i < 3; ++i)
//     {
//         QueueArrPop(queue);
//         QueueArrPush(queue, i);
//     }
//     QueueArrPrint(queue);
//     QueueArrFree(queue);
// }

void VisitBiNode(pBiTree bitree)
{
    if (bitree == NULL)
    {
        return;
    }
    printf("%d ", bitree->value);
}

void TestBiTree()
{
    int preArr[] = {1, 2, 4, 5, 3, 6};
    int midArr[] = {4, 2, 5, 1, 3, 6};
    pBiTree bitree = BiTreeCreateByPreAndMid(preArr, 0, 5, midArr, 0, 5);
    BiTreePreVisit(bitree, VisitBiNode);
    BiTreeMidVisit(bitree, VisitBiNode);
    BiTreePostVisit(bitree, VisitBiNode);
    BiTreeLevelVisit(bitree, VisitBiNode);
}

int main()
{
    // TestLinkList();
    // TestStack();
    // TestQueueLinkList();
    // TestQueueArr();
    TestBiTree();
    return 0;
}