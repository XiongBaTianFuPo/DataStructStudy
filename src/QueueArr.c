#include "QueueArr.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

pQueueArr QueueArrCreate()
{
    pQueueArr queue= (pQueueArr)malloc(sizeof(QueueArr));
    memset(queue, 0x00, sizeof(QueueArr));
    return queue;
}

void QueueArrFree(pQueueArr queue)
{
    if(queue==NULL)
    {
        return;
    }
    free(queue);
    queue=NULL;
}

int QueueArrPush(pQueueArr queue, pBiTree value)
{
    if(queue==NULL || queue->len>=MAX_QUEUE_SIZE)
    {
        return QUEUE_ARR_ERROR;
    }
    queue->arr[queue->rear]=value;
    ++queue->len;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    return 0;
}

pBiTree QueueArrPop(pQueueArr queue)
{
    if(queue==NULL || queue->len==0)
    {
        return NULL;
    } 
    pBiTree value = queue->arr[queue->front];
    --queue->len;
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return value;
}

int QueueArrGetLen(pQueueArr queue)
{
    if(queue==NULL)
    {
        return QUEUE_ARR_ERROR;
    } 
    return queue->len;
}

pBiTree QueueArrFront(pQueueArr queue)
{
    if(queue==NULL|| queue->len==0)
    {
        return NULL;
    } 
    return queue->arr[queue->front];
}

void QueueArrPrint(pQueueArr queue)
{
    if(queue==NULL|| queue->len==0)
    {
        return ;
    }
    int idx=queue->front;
    for(int i=0;i<queue->len;i++)
    {
        printf("%d ",queue->arr[idx]->value);
        idx = (idx + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}


