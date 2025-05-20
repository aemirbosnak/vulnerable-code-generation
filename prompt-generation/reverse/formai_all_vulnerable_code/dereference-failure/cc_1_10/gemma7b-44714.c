//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FNSH 0
#define LO 1
#define HI 2
#define MSG 3

int main()
{
    char **arr = NULL;
    int n = 0;
    char str[1000] = "This is a resume parsing system. Please provide the path to the resume file: ";

    printf("%s", str);
    scanf("%s", str);

    FILE *fp = fopen(str, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    arr = malloc(n * sizeof(char *));
    if (arr == NULL)
    {
        printf("Memory allocation error.\n");
        return 1;
    }

    n = 0;
    char line[1000];
    while (fgets(line, 1000, fp) != NULL)
    {
        arr[n] = strdup(line);
        n++;
    }

    fclose(fp);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }

    free(arr);

    return 0;
}