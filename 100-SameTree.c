/**********************************************************************************************************
LeetCode----[easy] 100-SameTree.c
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

[Ans:]
方法一：
分别先序、中序遍历树，将遍历结果分别存储到字符串中，比较先序、中序遍历后的字符串是否完全相等。
注意：仅先序或者中序是无法确定一棵树的，所以要对比两种遍历情况下的结果才能得出肯定答案
这种使用了两个递归，会导致run time error
方法二：
写成递归判断---递归求解。先判断终止条件，然后左右子树递归。

Author:tmw
date:2017-10-12
***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 //Definition for a binary tree node.
 struct TreeNode
 {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
/*******
方法一
*******/
//int i = 0;
//int j = 0;
//char a[100];
//char b[100];
//char* pre_order_travel(struct TreeNode* T)
//{
//    if(T==NULL)
//        return;//返回上一层递归
//    a[i] = T->val - '0';i++; //将树的val值转存到字符串中
//    pre_order_travel(T->left);
//    pre_order_travel(T->right);
//    return a;
//}
//char* in_order_travel(struct TreeNode* T)
//{
//    if(T==NULL)
//        return;
//    in_order_travel(T->left);
//    b[j] = T->val - '0';j++;
//    in_order_travel(T->right);
//    return b;
//}
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//    if( p == NULL && q == NULL )
//        return true;
//    //先序比较
//    char *p_pre; p_pre = (char*)malloc(100*sizeof(char));
//    char *p_in; p_in = (char*)malloc(100*sizeof(char));
//    char *q_pre; q_pre = (char*)malloc(100*sizeof(char));
//    char *q_in; q_in = (char*)malloc(100*sizeof(char));
//
//    p_pre = pre_order_travel(p);
//    i = 0;memset(a,'\0',100);//由于i与a都是全局变量，得归零
//    q_pre = pre_order_travel(q);
//    if( strcmp(p_pre,q_pre) != 0 )
//        return false;
//
//    p_in = in_order_travel(p);
//    j = 0;memset(b,'\0',100);//由于j与b都是全局变量，得归零
//    q_in = in_order_travel(q);
//    if( strcmp(p_in,q_in) != 0 )
//        return false;
//    return true;
//}
/*******
方法二---accept  但是时间复杂度高了
*******/
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if( p == NULL && q == NULL )
        return true;
    if( p == NULL || q == NULL )
        return false;
    if( p->val != q->val )
        return false;
    bool left_result = isSameTree(p->left,q->left);
    bool right_result = isSameTree(p->right,q->right);
    return left_result&&right_result;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
