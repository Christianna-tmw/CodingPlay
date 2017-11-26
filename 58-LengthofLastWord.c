/**********************************************************************************************************

LeetCode----[easy] 58-LengthofLastWord

    Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
    If the last word does not exist, return 0.

    Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

[Ans:]
Method:
������ַ����м��������Ҫ����
1�� Ϊ�մ� --- ����0
2�� ȫ�ǿո�----����0
3�� û��һ���ո� ---- ���ش���
4�� �пո�������--- �������һ���ֳ�
OK 这是一个测试

Author:tmw
date:2017-9-22

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s)
{
    int len = sizeof(s);

    int count = 0;

    if( len == 0 )
        return 0;

    int i = 0;
    int ok = 1;
    while(i<len)
    {
        if( s[i] != 32 )
        {
            ok = 0;
            break;
        }
        i++;
    }
    if( ok == 1 )
        return 0;
    i = 0;
    int mark = 0;
    while(i<len)
    {
        if(s[i] == ' ')
            mark++;
        i++;
    }
    if( mark == 0 )
        return i;

    i = len-1;
    while( i >= 0 )
    {
        if( s[i] != ' ' )
            break;
        i--;
    }
    int k = i;
    while( k >= 0 )
    {
        if( s[k] == ' ' )
            break;
        k--;
        count++;
    }
    return count;
}


int main()
{
    char* s;
    printf("input the string num \n");

    s = (char*)malloc(100*sizeof(char));

    int i = 0;
    for( i = 0 ; i < 4 ; i++ )
        scanf("%c",&s[i]);
    printf("i = %d\n",i);
    int res = 0;
    res = lengthOfLastWord(s);

    return res;
}

