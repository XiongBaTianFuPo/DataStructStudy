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

/**
 * 创建二叉树结点
*/
BiNode *BiNodeCreate();

/**
 * 释放整个二叉树
*/
void BiTreeFree(pBiTree bitree);

/**
 * 前序遍历
*/
void BiTreePreVisit(pBiTree bitree, VisitCb visit);

/**
 * 中序遍历
*/
void BiTreeMidVisit(pBiTree bitree, VisitCb visit);

/**
 * 后序遍历
*/
void BiTreePostVisit(pBiTree bitree, VisitCb visit);

/**
 * 层序遍历
*/
void BiTreeLevelVisit(pBiTree bitree, VisitCb visit);

/**
 * 获取二叉树的深度（高度）
*/
int BiTreeGetHeight(pBiTree bitree);

/**
 * 通过前序和中序遍历序列创建二叉树，二叉树结点的值保证不重复
*/
pBiTree BiTreeCreateByPreAndMid(int *preArr, int preStart, int preEnd, int *midArr, int midStart, int midEnd);

#endif

