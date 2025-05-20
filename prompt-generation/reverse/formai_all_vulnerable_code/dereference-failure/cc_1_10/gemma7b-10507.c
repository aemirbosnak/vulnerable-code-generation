//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void csv_reader(char **arr, int *size, FILE *fp)
{
    char line[1024];
    int i = 0;
    int flag = 0;

    if (*size == 0)
    {
        *size = 1;
        arr = malloc(*size * sizeof(char *));
    }

    getline(fp, line, 1024);

    for (i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == ',')
        {
            arr[*size - 1] = malloc((i - flag) * sizeof(char));
            memcpy(arr[*size - 1], line + flag, i - flag);
            *size++;
            flag = i + 1;
        }
    }

    arr[*size - 1] = malloc((i - flag) * sizeof(char));
    memcpy(arr[*size - 1], line + flag, i - flag);

    csv_reader(arr, size, fp);
}

int main()
{
    char **arr = NULL;
    int size = 0;
    FILE *fp = fopen("data.csv", "r");

    csv_reader(arr, &size, fp);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; arr[i][j] != '\0'; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}