//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define a CSV file pointer
    FILE *csvFile = NULL;

    // Open the CSV file
    csvFile = fopen("data.csv", "r");

    // Check if the file is open
    if (csvFile == NULL)
    {
        printf("Error opening CSV file.\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for the CSV data
    char **csvData = NULL;

    // Get the number of rows in the CSV file
    int numRows = 0;

    // Iterate over the rows in the CSV file
    while (fgets(csvData, 1024, csvFile) != NULL)
    {
        // Increment the number of rows
        numRows++;
    }

    // Allocate memory for the CSV data with the number of rows
    csvData = (char **)malloc(numRows * sizeof(char *));

    // Read the CSV data from the file
    rewind(csvFile);

    // Iterate over the rows in the CSV file
    for (int i = 0; i < numRows; i++)
    {
        fgets(csvData[i], 1024, csvFile);
    }

    // Close the CSV file
    fclose(csvFile);

    // Print the CSV data
    for (int i = 0; i < numRows; i++)
    {
        printf("%s\n", csvData[i]);
    }

    // Free the memory allocated for the CSV data
    free(csvData);

    return EXIT_SUCCESS;
}