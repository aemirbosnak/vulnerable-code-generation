//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_ROW_LEN 1000

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: csvreader <filename>\n");
        exit(1);
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("can't open %s\n", filename);
        exit(1);
    }

    char input[MAX_ROW_LEN];
    int row_count = 0;
    int col_count = 0;
    char *row[MAX_COLS];

    while (fgets(input, MAX_ROW_LEN, fp))
    {
        row[col_count++] = strdup(strtok(input, ",\n"));

        while (col_count < MAX_COLS && (row[col_count] = strtok(NULL, ",\n")))
        {
            col_count++;
        }

        if (col_count == MAX_COLS && strtok(NULL, ",\n"))
        {
            printf("Error: Too many columns in row %d\n", row_count);
            exit(1);
        }

        row_count++;
        col_count = 0;
    }

    for (int i = 0; i < row_count; i++)
    {
        for (int j = 0; j < MAX_COLS && row[i][j]; j++)
        {
            printf("%s ", row[i][j]);
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}