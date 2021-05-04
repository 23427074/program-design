#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define MAX 100

int main()
{
    int i,j;
    FILE *file = NULL;
    srand(time(NULL));
    file = fopen("dataset1.txt","w");
    int *number = malloc(sizeof(int)*MAX);
    for(i = 0; i < MAX; i++)
    {
        number[i] = rand() % MAX;
    }

    for(i = 0; i < MAX; i++)
    {
        fprintf(file, "%d\n",number[i]);
    }

    fclose(file);
    return 0;
}
