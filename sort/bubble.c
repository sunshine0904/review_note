/*************************************************************************
	> File Name: bubble.c
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Aug 2018 08:36:37 PM CST
 ************************************************************************/

#include<stdio.h>

#define N 10

int main(int argc, char **argv)
{
    int a[N] = {10,1,5,6,2,7,3,4,9,8};
    int i = 0,j = 0,temp = 0;


    for (i = 0; i < N - 1; i++)
    {
        for(j = 0;j < N - 1 - i; j++)
        {
            if (a[j] < a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

}
