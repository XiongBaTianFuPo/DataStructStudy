#ifndef _XIONG_QUEUEARR_H
#define _XIONG_QUEUEARR_H
#include "Constant.h"

typedef struct QueueArrTag
{
    int front;
    int rear;
    int len;
    int arr[MAX_QUEUE_SIZE];
} QueueArr, *pQueueArr;

pQueueArr QueueArrCreate();

void QueueArrFree(pQueueArr queue);

int QueueArrPush(pQueueArr queue, int value);

int QueueArrPop(pQueueArr queue);

int QueueArrGetLen(pQueueArr queue);

int QueueArrFront(pQueueArr queue);

void QueueArrPrint(pQueueArr queue);

#endif
