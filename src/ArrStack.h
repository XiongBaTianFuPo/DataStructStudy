#ifndef _XIONG_STACK_BY_ARR
#define _XIONG_STACK_BY_ARR
#include "Constant.h"

typedef struct ArrStackTag
{
    int arr[MAX_STACK_SIZE];
    int top;
} ArrStack, *pArrStack;

pArrStack ArrStackCreate();

void ArrStackFree(pArrStack stack);

int ArrStackTop(pArrStack stack);

void ArrStackPush(pArrStack stack, int value);

int ArrStackPop(pArrStack stack);

void ArrStackPrint(pArrStack stack);

int ArrStackGetLen(pArrStack stack);

#endif