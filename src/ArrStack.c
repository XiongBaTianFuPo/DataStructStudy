#include "ArrStack.h"
#include <stdio.h>
#include <stdlib.h>

pArrStack ArrStackCreate()
{
    pArrStack stack = (pArrStack)malloc(sizeof(ArrStack));
    stack->top = 0;
    return stack;
}

void ArrStackFree(pArrStack stack)
{
    if (!stack)
    {
        return;
    }
    stack->top = 0;
    free(stack);
    stack = NULL;
}

int ArrStackTop(pArrStack stack)
{
    if (!stack || stack->top == 0)
    {
        return STACK_ERROR;
    }
    return stack->arr[stack->top - 1];
}

void ArrStackPush(pArrStack stack, int value)
{
    if (!stack || stack->top >= MAX_STACK_SIZE)
    {
        return;
    }
    stack->arr[stack->top++] = value;
}

int ArrStackPop(pArrStack stack)
{
    if (!stack || stack->top == 0)
    {
        return STACK_ERROR;
    }
    return stack->arr[--stack->top];
}

void ArrStackPrint(pArrStack stack)
{
    if (!stack)
    {
        return;
    }
    for (int i = 0; i < stack->top; ++i)
    {
        printf("%d ", stack->arr[i]);
    }
}

int ArrStackGetLen(pArrStack stack)
{
    if (!stack)
    {
        return STACK_ERROR;
    }
    return stack->top;
}
