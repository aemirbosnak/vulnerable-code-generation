//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to parse csv line and return values as array of strings
char** parse_csv_line(char* line, const char* delimiter, int num_columns) {
    char** values = (char**) malloc(num_columns * sizeof(char*));
    char* token = strtok(line, delimiter);
    int i = 0;
    while (token != NULL && i < num_columns) {
        values[i++] = strdup(token);
        token = strtok(NULL, delimiter);
    }
    return values;
}

int main() {
    // Open csv file for reading
    FILE* fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }
    
    // Read header line to determine number of columns
    char header[MAX_LINE_LENGTH];
    if (fgets(header, MAX_LINE_LENGTH, fp) == NULL) {
        printf("Error: could not read header line\n");
        return 1;
    }
    int num_columns = 0;
    char* token = strtok(header, ",");
    while (token != NULL) {
        num_columns++;
        token = strtok(NULL, ",");
    }
    
    // Read each line of csv file and parse into values
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char** values = parse_csv_line(line, ",", num_columns);
        
        // Print values for each column
        for (int i = 0; i < num_columns; i++) {
            printf("%s ", values[i]);
        }
        printf("\n");
        
        // Free memory
        for (int i = 0; i < num_columns; i++) {
            free(values[i]);
        }
        free(values);
    }
    
    // Close file
    fclose(fp);
    
    return 0;
}