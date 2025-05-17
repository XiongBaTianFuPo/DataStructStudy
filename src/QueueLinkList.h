#ifndef _XIONG_QUEUELINKLIST_H
#define _XIONG_QUEUELINKLIST_H
#include "Constant.h"
#include "LinkList.h"

typedef struct QueueLinkListTag
{
    pLinkList head;
    pLinkList tail;
    int len;
} QueueLinkList, *pQueueLinkList;

pQueueLinkList QueueLinkListCreate();

void QueueLinkListFree(pQueueLinkList queue);

void QueueLinkListPush(pQueueLinkList queue, int value);

int QueueLinkListPop(pQueueLinkList queue);

int QueueLinkListGetLen(pQueueLinkList queue);

int QueueLinkListFront(pQueueLinkList queue);

void QueueLinkListPrint(pQueueLinkList queue);

#endif