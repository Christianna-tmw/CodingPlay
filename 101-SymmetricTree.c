/**********************************************************************************************************
LeetCode----[easy] 101-SymmetricTree.c
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

[Ans:]
采用递归的方法，将所有可能为false的可能都列出来，留一个最终true的出口

Author:tmw
date:2017-10-12
***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//在root不为空的前提下运行此子函数，因为如果每次迭代都判定root是否为空很费时间，root是否为空判定一次就好
bool sub_isSymmetric(struct TreeNode* left , struct TreeNode* right)
{
    if( left == NULL && right == NULL )
        return true;//给定一个正确答案出口，把所有可能的false都列出来
    else if( left != NULL && right == NULL )
        return false;
    else if( left == NULL && right != NULL )
        return false;
    else if( ( left != NULL && right != NULL ) && ( left->val != right->val ) )
        return false;
    else
        return sub_isSymmetric(left->left,right->right)&&sub_isSymmetric(left->right,right->left);
}
bool isSymmetric(struct TreeNode* root)
{
    if(root == NULL)
        return true;
    else
        return sub_isSymmetric(root->left,root->right);
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
