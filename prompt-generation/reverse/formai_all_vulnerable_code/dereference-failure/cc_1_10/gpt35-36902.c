//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of a CSV row
#define MAX_CSV_ROW_SIZE 100

// Define maximum size of a CSV field
#define MAX_CSV_FIELD_SIZE 20

// Function to read a CSV file
int readCSV(char *filename)
{
    // Declare variables
    char csvRow[MAX_CSV_ROW_SIZE];
    char csvField[MAX_CSV_FIELD_SIZE];
    int csvFieldIndex = 0;
    int csvRowIndex = 0;
    int csvFieldCount = 0;
    int csvRowCount = 0;
    int i, j;

    // Open the CSV file
    FILE *file = fopen(filename, "r");

    // Check if file exists
    if (file == NULL) {
        printf("Error: Could not open file '%s'", filename);
        return -1;
    }

    // Read each line of the CSV file
    while (fgets(csvRow, MAX_CSV_ROW_SIZE, file) != NULL) {

        // Remove newline character from the CSV row
        csvRow[strcspn(csvRow, "\r\n")] = 0;

        // Check if the CSV row size is greater than MAX_CSV_ROW_SIZE
        if (strlen(csvRow) > MAX_CSV_ROW_SIZE) {
            printf("Error: CSV row size is greater than allowed maximum\n");
            return -1;
        }

        // Initialize the CSV field index and field count
        csvFieldIndex = 0;
        csvFieldCount = 0;

        // Read each character of the CSV row
        for (i = 0; i < strlen(csvRow); i++) {

            // Check if the CSV field size is greater than MAX_CSV_FIELD_SIZE
            if (csvFieldIndex >= MAX_CSV_FIELD_SIZE) {
                printf("Error: CSV field size is greater than allowed maximum\n");
                return -1;
            }

            // Check if the character is a comma or end of line
            if (csvRow[i] == ',' || csvRow[i] == '\0') {

                // Null-terminate the CSV field
                csvField[csvFieldIndex] = '\0';

                // Check if the CSV field is empty
                if (csvFieldIndex == 0) {
                    printf("Error: CSV field is empty\n");
                    return -1;
                }

                // Increment the CSV field count
                csvFieldCount++;

                // Reset the CSV field index
                csvFieldIndex = 0;

            } else {

                // Add the character to the CSV field
                csvField[csvFieldIndex] = csvRow[i];

                // Increment the CSV field index
                csvFieldIndex++;

            }
        }

        // Check if the CSV row has the correct number of fields
        if (csvFieldCount != 3) {
            printf("Error: CSV row does not have the correct number of fields\n");
            return -1;
        }

        // Print the CSV row
        printf("CSV Row %d: ", csvRowCount + 1);
        for (j = 0; j < csvFieldCount; j++) {
            printf("%s, ", csvField);
        }
        printf("\n");

        // Increment the CSV row count
        csvRowCount++;

    }

    // Close the CSV file
    fclose(file);

    // Print the number of CSV rows read
    printf("Read %d CSV row(s) from file '%s'\n", csvRowCount, filename);

    // Return success
    return 0;
}

// Main function
int main()
{
    // Read the CSV file
    if (readCSV("data.csv") != 0) {
        printf("CSV read failed\n");
        return -1;
    }

    // Return success
    return 0;
}