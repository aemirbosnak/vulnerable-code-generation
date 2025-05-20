//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **csv_data = NULL;
    int num_rows = 0;
    char csv_file_name[] = "data.csv";

    FILE *csv_file = fopen(csv_file_name, "r");
    if (csv_file == NULL)
    {
        printf("Error opening CSV file: %s\n", csv_file_name);
        return EXIT_FAILURE;
    }

    // Allocate memory for CSV data
    csv_data = malloc(10 * sizeof(char *));
    if (csv_data == NULL)
    {
        printf("Error allocating memory for CSV data\n");
        fclose(csv_file);
        return EXIT_FAILURE;
    }

    // Read CSV data
    char line[1024];
    while (fgets(line, 1024, csv_file) != NULL)
    {
        // Count the number of rows
        num_rows++;

        // Parse the line into columns
        char *column = strtok(line, ",");
        csv_data[num_rows - 1] = malloc(100 * sizeof(char));
        int col_num = 0;
        while (column)
        {
            csv_data[num_rows - 1][col_num++] = column;
            column = strtok(NULL, ",");
        }
    }

    // Print CSV data
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; csv_data[i][j]; j++)
        {
            printf("%s, ", csv_data[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; csv_data[i][j]; j++)
        {
            free(csv_data[i][j]);
        }
        free(csv_data[i]);
    }

    free(csv_data);
    fclose(csv_file);

    return EXIT_SUCCESS;
}