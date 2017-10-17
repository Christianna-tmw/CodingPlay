/**********************************************************************************************************
LeetCode----[easy] 88-MergeSortedArray.c
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional
elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

[Ans:]
方法：题目已经给出条件说明a数组的长度不止m长，至少为m+n长，因此在把Merge后的元素放到a数组时，不用考虑a数组是否容纳不下
本题采用”从后往前“的比较方法，因为总共有m+n个元素，从后往前把a数组填满不会受到”从前往后“遍历的约束而重新向内存申请额外空间。

Author:tmw
date:2017-10-12
***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int m, int* nums2, int n)
{
    int i = m-1;//i指向nums1数组最后一个元素
    int j = n-1;//j指向nums2数组最后一个元素
    int k = n+m-1;//k指向新nums1数组最后一个元素

    if( n == 0 )
        return;
    if( m == 0 && n != 0 )
    {
        int s;
        for( s = 0 ; s < n ; s++ )
            nums1[s] = nums2[s];
        return;
    }

    while( i >= 0 && j >= 0 )
    {
        if( nums1[i] < nums2[j] )
        {
            nums1[k] = nums2[j];
            j--;
        }
        else
        {
            nums1[k] = nums1[i];
            i--;
        }
        k--;
    }
    while( i >= 0 )//说明nums1比nums2长
    {
        nums1[k] = nums1[i];
        i--;
        k--;
    }
    while( j >= 0 )//说明nuns2比nums1长
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
