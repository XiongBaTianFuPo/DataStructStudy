#include "QueueLinkList.h"
#include "LinkList.h"

pQueueLinkList QueueLinkListCreate()
{
    pQueueLinkList queue = (pQueueLinkList)malloc(sizeof(QueueLinkList));
    pLinkList head = (pLinkList)malloc(sizeof(LinkListNode));
    head->value = 12345678;
    head->next = NULL;
    queue->head = head;
    queue->tail = head;
    queue->len = 0;
    return queue;
}

void QueueLinkListFree(pQueueLinkList queue)
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

void QueueLinkListPush(pQueueLinkList queue, int value)
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

int QueueLinkListPop(pQueueLinkList queue)
{
    if(queue==NULL || queue->len==0)
    {
        return QUEUE_LINKLIST_ERROR;
    }
    int value = queue->head->next->value;
    pLinkList ptr=queue->head->next;
    queue->head->next = queue->head->next->next;
    free(ptr);
    --queue->len;
    return value;
}

int QueueLinkListGetLen(pQueueLinkList queue)
{
    if(queue==NULL)
    {
        return QUEUE_LINKLIST_ERROR;
    }
    return queue->len;
}

int QueueLinkListFront(pQueueLinkList queue)
{
    if(queue==NULL || queue->len==0)
    {
        return QUEUE_LINKLIST_ERROR;
    }
    return queue->head->next->value;
}

void QueueLinkListPrint(pQueueLinkList queue)
{
    if(queue==NULL || queue->len==0)
    {
        return;
    }
    LinkListPrint(queue->head->next);
}
