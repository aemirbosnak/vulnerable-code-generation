//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *pbuffer = NULL;
    char *pline = NULL;
    int lines = 0;
    int line_num = 1;
    FILE *fp = NULL;

    printf("Enter the file name: ");
    scanf("%s", buffer);

    fp = fopen(buffer, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    pbuffer = malloc(MAX_BUFFER_SIZE);
    if (pbuffer == NULL)
    {
        printf("Error allocating memory.\n");
        exit(1);
    }

    pline = malloc(MAX_BUFFER_SIZE);
    if (pline == NULL)
    {
        printf("Error allocating memory.\n");
        exit(1);
    }

    while (fgets(pline, MAX_BUFFER_SIZE, fp) != NULL)
    {
        lines++;
        printf("Line %d: %s", line_num, pline);
        line_num++;
    }

    free(pbuffer);
    free(pline);
    fclose(fp);

    return 0;
}