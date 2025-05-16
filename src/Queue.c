#include "Queue.h"
#include "LinkList.h"

pQueue QueueCreate()
{
    pQueue queue = (pQueue)malloc(sizeof(Queue));
    pLinkList head = (pLinkList)malloc(sizeof(LinkListNode));
    head->value = 12345678;
    head->next = NULL;
    queue->head = head;
    queue->tail = head;
    queue->len = 0;
    return queue;
}

void QueueFree(pQueue queue)
{
    if(queue == NULL)
    {
        return;
    }
    LinkListFree(queue->head);
    queue->head = NULL;
    queue->tail = NULL;
    free(queue);
    queue = NULL;
}

void QueuePush(pQueue queue, int value)
{
    if(queue == NULL)
    {
        return;
    }
    pLinkList newNode = (pLinkList)malloc(sizeof(LinkListNode));
    newNode->value = value;
    newNode->next = NULL;
    queue->tail->next = newNode;
    queue->tail = newNode;
    ++queue->len;
}

int QueuePop(pQueue queue)
{
    if(queue==NULL || queue->len==0)
    {
        return QUEUE_ERROR;
    }
    int value = queue->head->next->value;
    pLinkList ptr=queue->head->next;
    queue->head->next = queue->head->next->next;
    free(ptr);
    --queue->len;
    return value;
}

int QueueGetLen(pQueue queue)
{
    if(queue==NULL)
    {
        return QUEUE_ERROR;
    }
    return queue->len;
}

int QueueFront(pQueue queue)
{
    if(queue==NULL || queue->len==0)
    {
        return QUEUE_ERROR;
    }
    return queue->head->next->value;
}

void QueuePrint(pQueue queue)
{
    if(queue==NULL || queue->len==0)
    {
        return;
    }
    LinkListPrint(queue->head->next);
}
