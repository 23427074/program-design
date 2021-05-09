#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef HEAP_H
#define HEAP_H

void swapInt(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapString(char *x, char *y)
{
    char *tmp = malloc(sizeof(char)*101);
    strcpy(tmp, x);
    strcpy(x,y);
    strcpy(y,tmp);
    free(tmp);
}

void heapifyInt(int *number, int n, int i)
{
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if (left < n && *(number+left) > *(number+largest))
    {
        largest = left;
    }
    if (right < n && *(number+right) > *(number+largest))
    {
        largest = right;
    }
    if (largest != i)
    {
        swapInt(&*(number+i), &*(number+largest));
        heapifyInt(number, n, largest);
    }
}

void heapifyString(char **str, int n, int i)
{
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if (left < n && (strcmp(*(str+left) , *(str+largest))>0))
    {
        largest = left;
    }
    if (right < n && (strcmp(*(str+right) , *(str+largest))>0))
    {
        largest = right;
    }
    if (largest != i)
    {
        swapString(*(str+i), *(str+largest));
        heapifyString(str, n, largest);
    }
}

void heapSortInt(int *number, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyInt(number, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swapInt(&*(number+0), &*(number+i));
        heapifyInt(number, i, 0);
    }
}

void heapSortString(char **str, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyString(str, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swapString(*(str+0), *(str+i));
        heapifyString(str, i, 0);
    }
}

#endif
