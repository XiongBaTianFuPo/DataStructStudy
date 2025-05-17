#ifndef _XIONG_LINK_LIST_H
#define _XIONG_LINK_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "Constant.h"


typedef struct LinkListNodeTag
{
    int value;
    struct LinkListNodeTag *next;
} LinkListNode, *pLinkList;

int LinkListGet(pLinkList list, int index);

BOOL LinkListRemove(pLinkList list, int index);

void LinkListPrint(pLinkList list);

pLinkList LinkListCreate(int *arr, int len);

void LinkListFree(pLinkList list);

BOOL LinkListInsert(pLinkList list, int value, int index);



#endif