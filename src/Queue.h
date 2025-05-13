#ifndef _XIONG_QUEUE_H
#define _XIONG_QUEUE_H
#include "LinkList.h"
#define QUEUE_ERROR (-2141242141)

typedef struct QueueTag
{
    pLinkList head;
    pLinkList tail;
    int len;
} Queue, *pQueue;

pQueue QueueCreate();

void QueueFree(pQueue queue);

void QueuePush(pQueue queue, int value);

int QueuePop(pQueue queue);

int QueueGetLen(pQueue queue);

int QueueFront(pQueue queue);

void QueuePrint(pQueue queue);

#endif