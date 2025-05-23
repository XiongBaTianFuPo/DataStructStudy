#include "LinkList.h"

int LinkListGet(pLinkList list, int index)
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

BOOL LinkListRemove(pLinkList list, int index)
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

void LinkListPrint(pLinkList list)
{
    pLinkList ptr = list;
    while (ptr != NULL)
    {   
        printf("%d ",ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

pLinkList LinkListCreate(int *arr, int len)
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

void LinkListFree(pLinkList list)
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

BOOL LinkListInsert(pLinkList list, int value, int index)
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