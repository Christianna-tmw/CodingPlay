/**********************************************************************************************************

LeetCode----[easy] 70-Climbing Stairs.c

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.

[Ans:]
方法：【动态规划】
F(0) = 1
F(1) = 1
n>1时，对于每一个台阶i，要到达台阶，最后一步都有两种方法：从i-1迈一步，或从i-2迈两步。
也就是说到达台阶i的方法数=达台阶i-1的方法数+达台阶i-2的方法数。即：
F(i) = F(i-1) + F(i-2)
所以，最终序列变成了：1 1 2 3 5 8 ....变成了斐波拉契数列 求第n-1个位置上的值

Author:tmw
date:2017-10-11

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n)
{
    if( n == 0 || n == 1 )
        return 1;
    int i = 0;
    int pre_step1 = 1;//指最靠近current_step的那个元素
    int pre_step2 = 1;
    int current_step = 0;

    for( i = 2 ; i <= n ; i++ )
    {
        current_step = pre_step1 + pre_step2;
        pre_step2 = pre_step1;
        pre_step1 = current_step;
    }
    return current_step;
}


int main()
{
    int n = 0;
    int result = 0;
    printf("Please input your total steps:\n");
    scanf("%d",&n);
    printf("There are %d ways to climb to the top!\n",result = climbStairs(n));
    return 0;
}
