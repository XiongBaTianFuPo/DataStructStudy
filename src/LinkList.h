#ifndef _XIONG_LINK_LIST_H
#define _XIONG_LINK_LIST_H
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

int GetLinkList(pLinkList list, int index);

BOOL RemoveLinkList(pLinkList list, int index);

void PrintLinkList(pLinkList list);

pLinkList CreateLinkList(int *arr, int len);

void FreeLinkList(pLinkList list);

BOOL InsertLinkList(pLinkList list, int value, int index);



#endif