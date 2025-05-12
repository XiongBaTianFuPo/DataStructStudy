#include "Stack.h"
#include "LinkList.h"

pStack StackCreate()
{
    pStack stackhead= (pStack)malloc(sizeof(Stack));
    pLinkList head = (pLinkList)malloc(sizeof(LinkListNode));
    head->value = 12345678;
    head->next = NULL;
    stackhead->list=head;
    stackhead->top=head;
    stackhead->len = 0;
    return stackhead;
}

void StackFree(pStack stack)
{
    if(stack==NULL)
    {
        return;
    }
    LinkListFree(stack->list);
    stack->list = NULL;
    stack->top = NULL;
    free(stack);
    stack=NULL;
}

int StackTop(pStack stack)
{
    if(stack==NULL || stack->len==0)
    {
        return STACK_ERROR;
    }
    return stack->top->value;
}

void StackPush(pStack stack, int value)
{
    if (stack == NULL)
    {
        return;
    }
    pLinkList newlinknode = (pLinkList)malloc(sizeof(LinkListNode));
    newlinknode->value=value;
    newlinknode->next=NULL;
    stack->top->next=newlinknode;
    stack->len++;
    stack->top=newlinknode;
}

int StackPop(pStack stack)
{
    if (stack == NULL || stack->len == 0)
    {
        return STACK_ERROR;
    }
    int value = stack->top->value;
    pLinkList ptr = stack->list;
    for (int i=0; i<stack->len-1; i++)
    {
        ptr=ptr->next;
    }
    ptr->next=NULL;
    free(stack->top);
    stack->top=ptr;
    --stack->len;
    return value;

}

void StackPrint(pStack stack)
{
    if (stack == NULL)
    {
        return;
    }
    LinkListPrint(stack->list->next);
}

int StackGetLen(pStack stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    return stack->len;
}