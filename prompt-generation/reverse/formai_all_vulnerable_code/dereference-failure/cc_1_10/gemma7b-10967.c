//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_ROW {
    char **data;
    int num_cols;
} CSV_ROW;

CSV_ROW **read_csv(char *filename)
{
    CSV_ROW **rows = NULL;
    FILE *fp = NULL;
    int num_rows = 0;
    char line[MAX_ROWS][MAX_COLS];

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    while (fgets(line[num_rows], MAX_COLS, fp) != NULL)
    {
        num_rows++;
    }

    rows = malloc(num_rows * sizeof(CSV_ROW));
    if (rows == NULL)
    {
        fclose(fp);
        return NULL;
    }

    rewind(fp);

    for (int i = 0; i < num_rows; i++)
    {
        rows[i] = malloc(sizeof(CSV_ROW));
        rows[i]->data = malloc((MAX_COLS - 1) * sizeof(char *));
        rows[i]->num_cols = 0;

        while (fgets(line[i], MAX_COLS, fp) != NULL)
        {
            char *token = strtok(line[i], ",");
            rows[i]->data[rows[i]->num_cols++] = token;
        }
    }

    fclose(fp);

    return rows;
}

int main()
{
    CSV_ROW **rows = read_csv("data.csv");

    for (int i = 0; rows[i] != NULL; i++)
    {
        for (int j = 0; rows[i]->data[j] != NULL; j++)
        {
            printf("%s, ", rows[i]->data[j]);
        }
        printf("\n");
    }

    return 0;
}