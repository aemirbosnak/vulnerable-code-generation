//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function to split a string into an array of strings based on a delimiter
void split(char* str, char delimiter, char*** output) {
    char* token = strtok(str, delimiter);
    int count = 0;
    while (token!= NULL) {
        count++;
        // Reallocate memory for output array if necessary
        if (count == 1) {
            *output = (char**) malloc(sizeof(char*));
        } else {
            *output = (char**) realloc(*output, sizeof(char*) * count);
        }
        // Add token to output array
        (*output)[count-1] = token;
        // Get next token
        token = strtok(NULL, delimiter);
    }
}

// Function to read a CSV file and print its contents
void readCSV(FILE* file) {
    char line[1024];
    char delimiter = ',';
    char** fields;
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';
        // Split line into fields based on delimiter
        split(line, delimiter, &fields);
        // Print each field
        for (int i = 0; fields[i]!= NULL; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");
        // Free memory allocated for fields array
        for (int i = 0; fields[i]!= NULL; i++) {
            free(fields[i]);
        }
        free(fields);
    }
}

int main() {
    FILE* file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    readCSV(file);
    fclose(file);
    return 0;
}