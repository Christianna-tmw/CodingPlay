/**********************************************************************************************************

LeetCode----[easy] 67-Add Binary

Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".

[Ans:]
Method:
将a数组指定为最长数组（实际非最长可替换），将a、b数组每一位char型变成int型，并与进位相加，和数取模为新进位，
取余为新a数组当前结果位（注意放入结果位前把int转回char）；若最后一位有进位，则用aa申请新内存，最后一位置1，
并将a strcpy至aa除最后一位（数组中表现为首位）的所有对应位。Game over~

obstacle:
1）在构造的main函数里，使用如下语句输入字符串，发现strlen与实际char数组长度有出入（实际长度为4，但程序strlen反馈结果为5）
 printf("请输入第1个二进制数组\n");
    char ch;
    while( ( ch = getchar() ) != '\n' );
    for( i = 0 ; i < len_a ; i++ )
        scanf("%c",&a[i]);
    printf("strlen_a = %d\n",strlen(a));
解决：
    while( ( ch = getchar() ) != '\n' );
    i = 0;
    for( i = 0 ; i < len_b ; i++ )
        scanf("%c",&b[i]);
    printf("bi = %d\n",i);
    b[i] = '\0';
Author:tmw
date:2017-10-9

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    if(len_a == 0 && len_b == 0 )
        return 0;
    //将a当成长度最大的数组
    if( len_a < len_b )
    {
        char *tmp = a;
        a = b;
        b = tmp;
        int tmpVal = len_a;
        len_a = len_b;
        len_b = tmpVal;
    }
    int array = 0;//记录进位
    int long_len = len_a-1;
    int short_len = len_b-1;
    while( short_len >= 0 )
    {
        int a_val = a[long_len] - '0';
        int b_val = b[short_len] - '0';
        a_val = a_val + b_val + array;
        a[long_len] = a_val%2 + '0';//注意是char型的
        array = a_val/2;
        short_len--;
        long_len--;
    }
    int long_len_temp_val = 0;
    while( long_len >= 0 )
    {
        if(array == 1)
        {
            long_len_temp_val = a[long_len] - '0';
            a[long_len] = ( long_len_temp_val + array ) % 2 + '0';
            array =  ( long_len_temp_val + array ) / 2;
        }
        long_len--;
    }
    if(array == 1)//最高位有进位
    {
        char* aa = (char*)malloc(sizeof(char)*(len_a+2));
        aa[0] = '1';
        strcpy(aa+1,a);
        aa[len_a+1] = '\0';
        int i = 0;
        for( i = 0 ; i < (len_a+1) ; i++ )
            printf("%c ",aa[i]);
        printf("\n");
        return aa;
    }
    int i = 0;
    for( i = 0 ; i < len_a ; i++ )
    {
        printf("%c ",a[i]);
    }
    printf("\n");
    a[len_a] = '\0';
    return a;

}

int main()
{
    char* a;
    char* b;
    int len_a = 0;
    int len_b = 0;

    printf("please input the a size\n");
    scanf("%d",&len_a);
    printf("please input the b size\n");
    scanf("%d",&len_b);

    a = (char*)malloc(100*sizeof(char));
    b = (char*)malloc(100*sizeof(char));
    memset(a,'\0',len_a);
    memset(b,'\0',len_b);


    int i = 0;

    printf("请输入第1个二进制数组\n");
    char ch;
    while( ( ch = getchar() ) != '\n' );
    for( i = 0 ; i < len_a ; i++ )
        scanf("%c",&a[i]);
    printf("ai = %d\n",i);
    a[i] = '\0';

    printf("strlen_a = %d\n",strlen(a));

    printf("请输入第2个二进制数组\n");

    /*********************************
    字符数组scanf输入方法
    *********************************/
    while( ( ch = getchar() ) != '\n' );
    i = 0;
    for( i = 0 ; i < len_b ; i++ )
        scanf("%c",&b[i]);
    printf("bi = %d\n",i);
    b[i] = '\0';
    printf("strlen_b = %d\n",strlen(b));

    addBinary(a,b);
    return 0;
}
