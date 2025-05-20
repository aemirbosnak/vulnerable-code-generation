//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Function to read a CSV file and return the data as an array of strings
char** readCSV(FILE* file) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    // Count the number of lines in the file
    int numLines = 0;
    while ((read = getline(&line, &len, file))!= -1) {
        numLines++;
    }

    // Allocate memory for the array of strings
    char** data = malloc(numLines * sizeof(char*));

    // Reset the file pointer to the beginning
    rewind(file);

    // Read each line of the file and store it in the array
    int i = 0;
    while ((read = getline(&line, &len, file))!= -1) {
        data[i] = line;
        i++;
    }

    // Add a null terminator to the end of the array
    data[i] = NULL;

    return data;
}

// Function to print the contents of a CSV file
void printCSV(char** data) {
    for (int i = 0; data[i]!= NULL; i++) {
        printf("%s\n", data[i]);
    }
}

int main() {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read the CSV data from the file
    char** csvData = readCSV(file);

    // Print the CSV data
    printCSV(csvData);

    // Free the memory allocated for the CSV data
    for (int i = 0; csvData[i]!= NULL; i++) {
        free(csvData[i]);
    }
    free(csvData);

    // Close the file
    fclose(file);

    return 0;
}