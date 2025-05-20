//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

int main()
{
    // Allocate memory for the CSV reader
    char **csv_reader = (char **)malloc(MAX_ROWS * sizeof(char *));
    for (int r = 0; r < MAX_ROWS; r++)
    {
        csv_reader[r] = (char *)malloc(MAX_COLS * sizeof(char));
    }

    // Read the CSV file
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL)
    {
        return -1;
    }

    // Get the number of rows and columns
    int num_rows = 0;
    int num_cols = 0;
    char line[MAX_COLS];
    while (fgets(line, MAX_COLS, fp) != NULL)
    {
        num_rows++;
    }
    rewind(fp);
    while (fgets(line, MAX_COLS, fp) != NULL)
    {
        char **words = (char **)malloc(num_cols * sizeof(char *));
        int i = 0;
        for (char *word = strtok(line, ","); word; word = strtok(NULL, ","))
        {
            words[i++] = word;
        }
        num_cols = i;
        for (int r = 0; r < num_rows; r++)
        {
            csv_reader[r][num_cols - 1] = words[r];
        }
    }

    // Print the CSV data
    for (int r = 0; r < num_rows; r++)
    {
        for (int c = 0; c < num_cols - 1; c++)
        {
            printf("%s,", csv_reader[r][c]);
        }
        printf("\n");
    }

    // Free memory
    for (int r = 0; r < MAX_ROWS; r++)
    {
        free(csv_reader[r]);
    }
    free(csv_reader);

    // Close the file
    fclose(fp);

    return 0;
}