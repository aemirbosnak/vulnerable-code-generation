//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 50
#define MAX_NUM_FIELDS 10

char *trim_whitespace(char *str) {
    // Remove leading whitespace
    while (*str == ' ' || *str == '\t') {
        str++;
    }

    // Remove trailing whitespace
    char *end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t')) {
        end--;
    }
    *(end + 1) = '\0';

    return str;
}

int main() {
    FILE *fptr;
    char *filename = "example.csv";
    char line[MAX_LINE_LENGTH];
    char *tokens[MAX_NUM_FIELDS];
    int num_fields = 0;

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }

    // Read and process each line
    while (fgets(line, MAX_LINE_LENGTH, fptr) != NULL) {
        // Split line into tokens
        num_fields = 0;
        char *token = strtok(line, ",");
        while (token != NULL) {
            // Trim whitespace from token
            token = trim_whitespace(token);

            // Copy token to array
            tokens[num_fields] = malloc(strlen(token) + 1);
            strcpy(tokens[num_fields], token);

            num_fields++;

            // Check if too many fields
            if (num_fields > MAX_NUM_FIELDS) {
                printf("Error: too many fields\n");
                return 1;
            }

            // Get next token
            token = strtok(NULL, ",");
        }

        // Do something with fields
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");

        // Free memory used by tokens
        for (int i = 0; i < num_fields; i++) {
            free(tokens[i]);
        }
    }

    // Close file
    fclose(fptr);

    return 0;
}