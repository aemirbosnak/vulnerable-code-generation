//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to read CSV file
void readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Opps! The file seems to be playing hide and seek.");
        return;
    }

    char buffer[BUFFER_SIZE];

    // Max columns we can handle at a time
    int columnCount = 0;
    char *columns[100];

    printf("Welcome to CSV Reader 3000 - where even data has a sense of style!\n");
    printf("----------------------------------------------------------\n");

    // Read each line from the CSV file
    while (fgets(buffer, BUFFER_SIZE, file)) {
        char *value = strtok(buffer, ",");
        columnCount = 0;

        printf("Here's a new line of code!\n");

        // Process each value in the line
        while (value) {
            // Allocate memory for the column value and copy it
            columns[columnCount] = (char *)malloc(strlen(value) + 1);
            if (!columns[columnCount]) {
                perror("Memory allocation failed! Did we run out of snacks?");
                fclose(file);
                return;
            }
            strcpy(columns[columnCount], value);
            columnCount++;

            printf("Column %d: %s\n", columnCount, columns[columnCount - 1]);
            value = strtok(NULL, ",");
        }

        // Print a wacky summary
        printf("We just read %d columns from this line. Data is powerful, folks!\n\n", columnCount);
        
        // Free allocated memory for this line
        for (int i = 0; i < columnCount; i++) {
            free(columns[i]);
        }
    }

    printf("Finished reading the CSV file. It's been a rollercoaster of commas!\n");
    fclose(file);
}

int main() {
    const char *filename = "data.csv";
    // A hint on CSV naming conventions one should follow!
    printf("A CSV file is probably named '%s'. Guess what it's about?\n", filename);
    
    readCSV(filename);

    return 0;
}