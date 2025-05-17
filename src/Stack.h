#ifndef _XIONG_STACK_H
#define _XIONG_STACK_H
#include "LinkList.h"
#include "Constant.h"

typedef struct StackTag
{
    pLinkList list;
    pLinkList top;
    int len;
} Stack, *pStack;

pStack StackCreate();

void StackFree(pStack stack);

int StackTop(pStack stack);

void StackPush(pStack stack, int value);

int StackPop(pStack stack);

void StackPrint(pStack stack);

int StackGetLen(pStack stack);

#endif