/*************************************************************************
	> File Name: inert_sort.c
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Aug 2018 02:17:52 PM CST
 ************************************************************************/

#include<stdio.h>


int main(int argc, char **argv)
{
    int array[10] = {9,0,2,3,5,4,6,8,7,1};
    int len = 10, i = 0, j = 0;

    for (i = 1; i < len; i++)
    {
        if (array[i] < array[i-1])
        {
            int temp = array[i];
            int low = 0, high = i - 1, mid = 0;
            while(low <= high)
            {
                mid = (low + high)/2;
                if (temp < array[mid])
                {
                    high = mid -1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            for (j = i; j > low; j--)
            {
                array[j] = array[j - 1];
            }

            array[low] = temp;
        }
    }
    
    for (i = 0; i < len; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");

    return 0;
}


