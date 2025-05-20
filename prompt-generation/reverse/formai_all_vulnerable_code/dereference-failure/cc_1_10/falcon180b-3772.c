//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to split a string by a delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **result = NULL;
    char *token;
    char *saveptr = NULL;

    // Count number of tokens
    char *line = strdup(str);
    char *ptr = strtok_r(line, delimiter, &saveptr);
    while (ptr!= NULL) {
        count++;
        ptr = strtok_r(NULL, delimiter, &saveptr);
    }

    // Allocate memory for result array
    result = malloc(sizeof(char *) * (count + 1));
    if (result == NULL) {
        fprintf(stderr, "Error: Could not allocate memory.\n");
        exit(1);
    }

    // Split string and store tokens in result array
    count = 0;
    line = strdup(str);
    ptr = strtok_r(line, delimiter, &saveptr);
    while (ptr!= NULL) {
        result[count] = strdup(ptr);
        count++;
        ptr = strtok_r(NULL, delimiter, &saveptr);
    }
    result[count] = NULL;

    return result;
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE *file) {
    char line[MAX_LINE_LENGTH];
    char **tokens;

    // Read each line of the file
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Split line by comma delimiter
        tokens = split(line, ',');

        // Print each token
        for (int i = 0; tokens[i]!= NULL; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");

        // Free memory allocated for tokens
        for (int i = 0; tokens[i]!= NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: Please provide a CSV file as an argument.\n");
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", argv[1]);
        exit(1);
    }

    read_csv_file(file);

    fclose(file);
    return 0;
}