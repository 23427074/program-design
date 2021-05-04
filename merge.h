#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000
#ifndef HEADER_FILE
#define HEADER_FILE

void mergeInt(int *number, int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - mid;
    int *A = malloc(sizeof(int)*lenA);
    int *B = malloc(sizeof(int)*lenB);
    int i, j, k;
    for(i = 0; i < lenA; i++)
    {
        A[i] = number[head + i];
    }
    for(j = 0; j < lenB; j++)
    {
        B[j] = number[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = head;
    while(i < lenA && j < lenB)
    {
        if(A[i] < B[j])
        {
            number[k] = A[i];
            i++;
        }
        else
        {
            number[k] = B[j];
            j++;
        }
        k++;
    }
    while(i < lenA)
    {
        number[k] = A[i];
        i++;
        k++;
    }
    while(j < lenB)
    {
        number[k] = B[j];
        j++;
        k++;
    }
}

void mergeString(char **str, int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - mid;
    char **A = malloc(sizeof(char*)*lenA);
    char **B = malloc(sizeof(char*)*lenB);
    for(int r=0;r<MAX;r++)
    {
    	*(A+r) = malloc(sizeof(char)*101);
    	*(B+r) = malloc(sizeof(char)*101);
    }
    int i, j, k;
    for(i = 0; i < lenA; i++)
    {
        strcpy(A[i],str[head + i]);
    }
    for(j = 0; j < lenB; j++)
    {
        strcpy(B[j],str[mid + 1 + j]);
    }
    i = 0;
    j = 0;
    k = head;
    while(i < lenA && j < lenB)
    {
        if(strcmp(A[i] , B[j])<0)
        {
            strcpy(str[k],  A[i]);
            i++;
        }
        else
        {
            strcpy(str[k],  B[j]);
            j++;
        }
        k++;
    }
    while(i < lenA)
    {
        strcpy(str[k],  A[i]);
        i++;
        k++;
    }
    while(j < lenB)
    {
        strcpy(str[k],  B[j]);
        j++;
        k++;
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
