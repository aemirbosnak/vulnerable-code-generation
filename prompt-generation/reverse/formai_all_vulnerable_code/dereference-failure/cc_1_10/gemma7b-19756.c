//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void csv_read(char **csv_data)
{
    FILE *fp;
    fp = fopen("data.csv", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Allocate memory for the CSV data
    *csv_data = malloc(1000 * sizeof(char *));
    if (*csv_data == NULL)
    {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the CSV data line by line
    char line[1000];
    int i = 0;
    while (fgets(line, 1000, fp) != NULL)
    {
        // Split the line into columns
        char **columns = malloc(1000 * sizeof(char *));
        char *column = strtok(line, ",");
        while (column)
        {
            columns[i++] = column;
            column = strtok(NULL, ",");
        }

        // Store the columns in the CSV data
        (*csv_data)[i - 1] = columns;
    }

    fclose(fp);
}

int main()
{
    char **csv_data;
    csv_read(&csv_data);

    // Print the CSV data
    for (int i = 0; csv_data[i] != NULL; i++)
    {
        for (int j = 0; csv_data[i][j] != NULL; j++)
        {
            printf("%s,", csv_data[i][j]);
        }
        printf("\n");
    }

    // Free the CSV data
    for (int i = 0; csv_data[i] != NULL; i++)
    {
        for (int j = 0; csv_data[i][j] != NULL; j++)
        {
            free(csv_data[i][j]);
        }
        free(csv_data[i]);
    }
    free(csv_data);

    return 0;
}