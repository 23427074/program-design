#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef QUICK_H
#define QUICK_H

#define SWAPInt(x,y) {int t; t = x; x = y; y = t;}


void SWAPString(char *x, char *y)
{
    char *tmp = malloc(sizeof(char)*101);
    strcpy(tmp, x);
    strcpy(x,y);
    strcpy(y,tmp);
    free(tmp);
}

int partitionInt(int *number, int left, int right)
{
    int i = left - 1;
    int j;
    for(j = left; j < right; j++)
    {
        if(*(number+j) <= *(number+right))
        {
            i++;
            SWAPInt(*(number+i), *(number+j));
        }
    }
    SWAPInt(*(number+i+1), *(number+right));
    return i+1;
}

int partitionString(char **str, int left, int right)
{
    int i = left - 1;
    int j;
    for(j = left; j < right; j++)
    {
        if(strcmp(*(str+j),*(str+right))<=0)
        {
            i++;
            SWAPString(*(str+i), *(str+j));
        }
    }
    SWAPString(*(str+i+1), *(str+right));
    return i+1;
}

void quickSortInt(int *number, int left, int right)
{
    if(left < right)
    {
        int q = partitionInt(number, left, right);
        quickSortInt(number, left, q-1);
        quickSortInt(number, q+1, right);
    }
}

void quickSortString(char **str, int left,int right)
{
    if(left<right)
    {
       int q = partitionString(str, left, right);
       quickSortString(str, left, q-1);
       quickSortString(str, q+1, right);
    }
}

#endif
