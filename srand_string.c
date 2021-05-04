#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

const unsigned char allChar[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    FILE *file = NULL;
    const unsigned int len = 100;
    unsigned char str[len+1][len+1];
    int i;
    unsigned int cnt, randNo;
    srand((unsigned int)time(NULL));
    file = fopen("dataset2.txt","w");
    for(i=0;i<MAX;i++)
    {
        for (cnt = 0; cnt<len; cnt++)
        {
            randNo = rand() % 52;
            fprintf(file, "%c",allChar[randNo]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    return 0;
}
