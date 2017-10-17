/**********************************************************************************************************
LeetCode----[easy] 104-MaximumDepthofBinaryTree
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

[Ans:]
DFS递归

Author:tmw
date:2017-10-13
***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>


//Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int maxDepth(struct TreeNode* root)
{
    if( root == NULL )
        return 0;
    if( root->left == NULL &&  root->right == NULL )
        return 1;
    int max_left = maxDepth(root->left);
    int max_right = maxDepth(root->right);
    return max_left>max_right?max_left+1:max_right+1;//+1是为了算上根节点
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
