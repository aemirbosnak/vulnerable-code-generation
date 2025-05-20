//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to split a string by a delimiter
char **split(char *string, char delimiter) {
    int count = 0;
    char **tokens = (char **)malloc(sizeof(char *));
    char *token = strtok(string, delimiter);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, delimiter);
    }

    tokens[count] = NULL;
    return tokens;
}

// Function to read a CSV file
void read_csv_file(FILE *file) {
    char line[MAX_LINE_LENGTH];
    char delimiter = ',';
    char **tokens;

    // Read the first line (header)
    fgets(line, MAX_LINE_LENGTH, file);
    printf("Header:\n");
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == delimiter) {
            printf("Column %d\n", i + 1);
        }
    }

    // Read the rest of the lines (data)
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        tokens = split(line, delimiter);
        for (int i = 0; tokens[i]!= NULL; i++) {
            printf("Value in column %d: %s\n", i + 1, tokens[i]);
        }
        free(tokens);
    }
}

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];

    // Get the filename from the user
    printf("Enter the filename: ");
    fgets(filename, MAX_LINE_LENGTH, stdin);

    // Open the file
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the CSV file
    read_csv_file(file);

    // Close the file
    fclose(file);

    return 0;
}