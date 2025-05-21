#include "BiTree.h"
#include "QueueArr.h"
#include "Utils.h"



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

void BiTreeLevelVisit(pBiTree bitree, VisitCb visit)
{
    pQueueArr queue = QueueArrCreate();
    int rc=QueueArrPush(queue, bitree);
    if(rc != 0)
    {
        QueueArrFree(queue);
        return;
    }
    while(queue->len != 0)
    {
        pBiTree node = QueueArrPop(queue);
        visit(node);
        if(node->left != NULL)
        {
            rc=QueueArrPush(queue, node->left);
            if(rc != 0)
            {
                QueueArrFree(queue);
                return;
            }
        }
        if(node->right != NULL)
        {
            rc=QueueArrPush(queue, node->right);
            if(rc != 0)
            {
                QueueArrFree(queue);
                return;
            }
        }
    }

    QueueArrFree(queue);

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

pBiTree BiTreeCreateByPreAndMid(int *preArr, int preStart, int preEnd, int *midArr, int midStart, int midEnd)
{
    if(preStart > preEnd)
    {
        return NULL;
    }
    pBiTree root = BiNodeCreate();
    root->value = preArr[preStart];
    int index = SequentialSearch(midArr, root->value, midStart, midEnd);
    int lPreStart = preStart+1;
    int lPreEnd = index;
    int lMidStart = midStart;
    int lMidEnd = index-1;
    root->left = BiTreeCreateByPreAndMid(preArr,lPreStart,lPreEnd,midArr,lMidStart,lMidEnd);
    int rPreStart = index+1;
    int rPreEnd = preEnd;
    int rMidStart = index+1;
    int rMidEnd = midEnd;
    root->right = BiTreeCreateByPreAndMid(preArr,rPreStart,rPreEnd,midArr,rMidStart,rMidEnd);
    return root;
}