#ifndef _XIONG_BITREE_H
#define _XIONG_BITREE_H
#include <stdio.h>
#include <stdlib.h>
#include "Constant.h"

typedef struct BiNodeTag BiNode, *pBiTree;

typedef void (*VisitCb)(pBiTree bitree);

struct BiNodeTag
{
    int value;
    pBiTree left;
    pBiTree right;
};

BiNode *BiNodeCreate();

void BiTreeFree(pBiTree bitree);

void BiTreePreVisit(pBiTree bitree, VisitCb visit);

void BiTreeMidVisit(pBiTree bitree, VisitCb visit);

void BiTreePostVisit(pBiTree bitree, VisitCb visit);

int BiTreeGetHeight(pBiTree bitree);

#endif

