//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to split a string by a delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **result;
    char *token;

    // Count the number of substrings
    for (count = 0; *str; str++) {
        if (*str == delimiter) {
            count++;
        }
    }

    // Allocate memory for the result array
    result = malloc(sizeof(char *) * (count + 1));

    // Initialize the result array
    for (int i = 0; i < count; i++) {
        result[i] = NULL;
    }

    // Split the string into substrings
    token = strtok(str, delimiter);
    int j = 0;
    while (token!= NULL) {
        result[j++] = token;
        token = strtok(NULL, delimiter);
    }

    // Add a null terminator to the result array
    result[count] = NULL;

    return result;
}

// Function to read a CSV file recursively
void readCSV(FILE *file) {
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char **values = split(line, ',');
        for (int i = 0; values[i]!= NULL; i++) {
            printf("%s ", values[i]);
        }
        printf("\n");
        for (int i = 0; values[i]!= NULL; i++) {
            free(values[i]);
        }
        free(values);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    readCSV(file);

    fclose(file);

    return 0;
}