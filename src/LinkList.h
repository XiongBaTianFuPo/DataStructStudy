#ifndef _XYF_LINK_LIST_H
#define _XYF_LINK_LIST_H
#include <stdio.h>
#include <stdlib.h>

#ifndef BOOL
#define BOOL int
#define TRUE 1
#define FALSE 0
#endif

typedef struct LinkListNodeTag
{
    int value;
    struct LinkListNodeTag *next;
} LinkListNode, *pLinkList;

int GetLinkList(pLinkList list, int index)
{
    pLinkList ptr = list;
    int i = 0;
    while (ptr != NULL && i < index + 1)
    {
        ptr = ptr->next;
        i++;
    }
    return ptr->value;
}

BOOL RemoveLinkList(pLinkList list, int index)
{
    pLinkList ptr = list;
    int i = 0;
    while (ptr != NULL && i < index)
    {
        ptr = ptr->next;
        i++;
    }
    if(ptr != NULL&&ptr->next!=NULL)
    {
        pLinkList p=ptr->next;
        ptr->next=p->next;
        free(p);
        return TRUE; 
    }
    return FALSE;
}

void PrintLinkList(pLinkList list)
{
    pLinkList ptr = list;
    while (ptr != NULL)
    {   
        printf("%d ",ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

pLinkList CreateLinkList(int *arr, int len)
{
    // 头插法创建链表
    pLinkList head = (pLinkList)malloc(sizeof(LinkListNode));
    head->value = 12345678;
    head->next = NULL;
    for (int i = 0; i < len; ++i)
    {
        pLinkList new_node = (pLinkList)malloc(sizeof(LinkListNode));
        new_node->value = arr[len-1-i];
        new_node->next = head->next;
        head->next = new_node;
    }
    return head;

    // // 尾插法创建链表
    // pLinkList head = (pLinkList)malloc(sizeof(LinkListNode));
    // head->value = 12345678;
    // head->next = NULL;
    // pLinkList ptr = head;
    // for (int i = 0; i < len; ++i)
    // {
    //     pLinkList new_node = (pLinkList)malloc(sizeof(LinkListNode));
    //     new_node->value = arr[i];
    //     new_node->next = NULL;
    //     ptr->next = new_node;
    //     ptr = new_node;
    // }
    // return head;
}

void FreeLinkList(pLinkList list)
{
    pLinkList ptr=list;
    while(ptr!=NULL)
    {
        pLinkList ptrnext=ptr->next;
        free(ptr);
        ptr=ptrnext;
    }
    list = NULL;
}

BOOL InsertLinkList(pLinkList list, int value, int index)
{
    pLinkList ptr=list;
    int i=0;
    while(ptr!=NULL&&i<index)
    {
        ptr=ptr->next;
        i++;
    } 
    if(ptr==NULL)
    {
        return FALSE;
    }
    pLinkList new_node = (pLinkList)malloc(sizeof(LinkListNode));
    new_node->value=value;
    new_node->next=ptr->next;
    ptr->next=new_node;
    return TRUE;
}



#endif