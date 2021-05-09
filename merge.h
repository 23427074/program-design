#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000
#ifndef MERGE_H
#define MERGE_H

int result[MAX];

void mergeInt(int number[], int head, int mid, int tail)
{
    int i, j, k;
    k = 0;
    i = head;
    j = mid + 1;
    while(i <= mid && j <= tail)
    {
        if(number[i] < number[j])
        {
            result[k++] = number[i++];    // same as b[k]=a[i]; k++; i++;
        }
        else
        {
            result[k++] = number[j++];
        }
    }
  
    while(i <= mid)
    {
        result[k++] = number[i++];
    }
  
    while(j <= tail)
    {
        result[k++] = number[j++];
    }
  
    for(i=tail; i >= head; i--)
    {
        number[i] = result[--k];  // copying back the sorted list to a[]
    } 
}

char resultstring[MAX][101];
void mergeString(char **str, int head, int mid, int tail)
{
    int i, j, k;
    k = 0;
    i = head;
    j = mid + 1;
    while(i <= mid && j <= tail)
    {
        if(strcmp(str[i],str[j])<0)
        {
            strcpy(resultstring[k++],str[i++]);
        }
        else
        {
            strcpy(resultstring[k++],str[j++]);
        }
    }
  
    while(i <= mid)
    {
        strcpy(resultstring[k++],str[i++]);
    }
  
    while(j <= tail)
    {
        strcpy(resultstring[k++],str[j++]);
    }
  
    for(i=tail; i >= mid; i--)
    {
        strcpy(str[i],resultstring[--k]); 
    }
}

void mergeSortInt(int *number, int head, int tail)
{
    if(head < tail)
    {
        int mid = (head + tail) / 2;
        mergeSortInt(number, head, mid);
        mergeSortInt(number, mid+1, tail);
        mergeInt(number, head, mid, tail);
    }
}

void mergeSortString(char **str, int head, int tail)
{
    if(head < tail)
    {
        int mid = (head + tail) / 2;
        mergeSortString(str, head, mid);
        mergeSortString(str, mid+1, tail);
        mergeString(str, head, mid, tail);
    }
}

#endif
