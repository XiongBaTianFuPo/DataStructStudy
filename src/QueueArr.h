#ifndef _XIONG_QUEUEARR_H
#define _XIONG_QUEUEARR_H
#include "BiTree.h"
#include "Constant.h"

typedef struct QueueArrTag
{
    int front;
    int rear;
    int len;
    pBiTree arr[MAX_QUEUE_SIZE];
} QueueArr, *pQueueArr;

pQueueArr QueueArrCreate();

void QueueArrFree(pQueueArr queue);

int QueueArrPush(pQueueArr queue, pBiTree value);

pBiTree QueueArrPop(pQueueArr queue);

int QueueArrGetLen(pQueueArr queue);

pBiTree QueueArrFront(pQueueArr queue);

void QueueArrPrint(pQueueArr queue);

#endif
