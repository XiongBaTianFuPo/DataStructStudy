#include "BiTree.h"



BiNode *BiNodeCreate()
{
    pBiTree bitree=(pBiTree)malloc(sizeof(BiNode));
    bitree->left=NULL;
    bitree->right=NULL;
    return bitree;
}

void BiTreeFree(pBiTree bitree)
{
    if(bitree==NULL)
    {
        return;
    }
    BiTreeFree(bitree->left);
    BiTreeFree(bitree->right);
    free(bitree);
    bitree = NULL;
}

void BiTreePreVisit(pBiTree bitree, VisitCb visit)
{
    if(bitree==NULL)
    {
        return;
    }
    visit(bitree);
    BiTreePreVisit(bitree->left, visit);
    BiTreePreVisit(bitree->right, visit);
}

void BiTreeMidVisit(pBiTree bitree, VisitCb visit)
{
    if(bitree==NULL)
    {
        return;
    }
    BiTreeMidVisit(bitree->left, visit);
    visit(bitree);
    BiTreeMidVisit(bitree->right, visit);
}

void BiTreePostVisit(pBiTree bitree, VisitCb visit)
{
    if(bitree==NULL)
    {
        return;
    }
    BiTreePostVisit(bitree->left, visit);
    BiTreePostVisit(bitree->right, visit);
    visit(bitree);
}

int BiTreeGetHeight(pBiTree bitree)
{
    if(bitree==NULL)
    {
        return 0;
    }
    int left=BiTreeGetHeight(bitree->left);
    int right=BiTreeGetHeight(bitree->right);
    int len = left > right ? left : right;
    return len + 1;
}