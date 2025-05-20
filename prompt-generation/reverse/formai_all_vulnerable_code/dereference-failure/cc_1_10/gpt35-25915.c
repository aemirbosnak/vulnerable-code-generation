//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define BUFFER_SIZE 1024

int main()
{
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    char *token;
    int row = 0;
    int col = 0;
    char *data[MAX_ROWS][MAX_COLS];

    while (fgets(buffer, BUFFER_SIZE, fp))
    {
        col = 0;
        token = strtok(buffer, ",");
        while (token != NULL)
        {
            if (col > MAX_COLS)
            {
                printf("Error: Too many columns\n");
                exit(EXIT_FAILURE);
            }
            data[row][col] = malloc(strlen(token) + 1);
            if (data[row][col] == NULL)
            {
                printf("Error: Out of memory\n");
                exit(EXIT_FAILURE);
            }
            strcpy(data[row][col++], token);
            token = strtok(NULL, ",");
        }
        row++;
    }

    fclose(fp);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            free(data[i][j]);
        }
    }

    return 0;
}