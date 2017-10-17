/**********************************************************************************************************

LeetCode----[easy] 66-Plus One

Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
The digits are stored such that the most significant digit is at the head of the list.

[Ans:]
Method:
1）需要malloc的情况只有一种，就是加一之前数组的所有元素都为9，这时将所有元素置0，高位malloc置1
2）其他情况就是两种
    一种是，最低位向次低位进位，次低位加1，低位置0
    一种是，不进位，地位加1

Author:tmw
date:2017-9-22

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i = 0;
    int mark = 0;
    int *array;//记录可能会进位的位置 =---为0

    if(digitsSize == 0)
        return 0;

    array = (int *)malloc(digitsSize*sizeof(int));
    memset(array,0,digitsSize);

    //需要malloc的情况
    for( i = 0 ; i < digitsSize ; i++ )
    {
        if( digits[i] == 9 )
        {
            array[i] = 1;
            mark++;
        }
    }
    i--;
//    printf("i = %d\n",i);
//    printf("mark = %d\n",mark);
    //高位进位的情况
    int j = 0;
    if( mark == digitsSize )
    {
        *returnSize = digitsSize + 1;
        digits = (int*)realloc(digits,(digitsSize+1)*sizeof(int));
        digits[0] = 1;
        for( j = 1 ; j < ( digitsSize + 1 ) ; j++ )
            digits[j] = 0;
    }
    //次低位进位的情况
    else
    {
        int markey = 0;
        *returnSize = digitsSize;
        while( digits[i] == 9 )
        {
            i--;
            markey++;//记录从低位开始，有多少个连续的9
        }
        printf("markey = %d\n",markey);
        if( markey ==0 )//没有进位
        {
            digits[digitsSize-1] = digits[digitsSize-1] + 1;
            for( j = 0 ; j < *returnSize ; j++ )
                printf("%d ",digits[j]);
            printf("\n");

            return digits;
        }
        else//低位有进位，记录低位连续为9的最高位位置，从低位到这个位置之后的所有元素置0，这个位置的元素自加1
        {
            for( j = digitsSize - markey ; j < digitsSize ; j++ )
                digits[j] = 0;
            digits[digitsSize - markey - 1] = digits[digitsSize - markey - 1] + 1;

            for( j = 0 ; j < *returnSize ; j++ )
                printf("%d ",digits[j]);
            printf("\n");

            return digits;
        }
    }
    for( j = 0 ; j < *returnSize ; j++ )
        printf("%d ",digits[j]);
    printf("\n");
    return digits;
}
int main()
{
    int* digits;
    int digitsSize;
    int* returnSize;
    int i = 0;
    printf("Please input your digitsSize\n");
    scanf("%d",&digitsSize);

    digits = (int*)malloc(digitsSize*sizeof(int));
    returnSize = (int*)malloc(sizeof(int));
    printf("input the digits:\n");
    for( i = 0 ; i < digitsSize ; i++ )
        scanf("%d",&digits[i]);
    *returnSize = digitsSize;
    plusOne(digits,digitsSize,returnSize);
    return 0;
}
