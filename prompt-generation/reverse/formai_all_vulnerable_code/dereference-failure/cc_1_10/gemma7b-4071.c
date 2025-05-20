//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

int main()
{
    // Allocate memory for the CSV data
    char **csv_data = (char**)malloc(MAX_ROWS * sizeof(char*));
    for (int r = 0; r < MAX_ROWS; r++)
    {
        csv_data[r] = (char*)malloc(MAX_COLS * sizeof(char));
    }

    // Open the CSV file
    FILE* csv_file = fopen("my_csv.csv", "r");

    // Read the CSV data
    int row = 0;
    while (!feof(csv_file))
    {
        // Read the header row
        char* header = fgets(csv_data[row], MAX_COLS, csv_file);

        // Remove the newline character from the header
        header[strcspn(header, "\n")] = '\0';

        // Increment the row number
        row++;
    }

    // Close the CSV file
    fclose(csv_file);

    // Print the CSV data
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < MAX_COLS; c++)
        {
            printf("%s,", csv_data[r][c]);
        }
        printf("\n");
    }

    // Free the memory allocated for the CSV data
    for (int r = 0; r < MAX_ROWS; r++)
    {
        free(csv_data[r]);
    }
    free(csv_data);

    return 0;
}