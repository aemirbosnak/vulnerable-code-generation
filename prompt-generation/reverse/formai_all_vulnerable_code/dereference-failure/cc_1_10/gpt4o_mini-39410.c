//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define DELIMITER ","

// Function to trim newline character
void trim_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

// Function to read CSV file
void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        trim_newline(line);
        
        char *fields[MAX_FIELD_LENGTH];
        int field_count = 0;

        // Tokenize the line based on the delimiter
        char *token = strtok(line, DELIMITER);
        while (token != NULL && field_count < MAX_FIELD_LENGTH) {
            fields[field_count] = malloc(strlen(token) + 1);
            if (fields[field_count] == NULL) {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }
            strcpy(fields[field_count], token);
            field_count++;
            token = strtok(NULL, DELIMITER);
        }

        // Process read fields
        printf("Read %d fields:\n", field_count);
        for (int i = 0; i < field_count; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
            free(fields[i]); // Free allocated memory
        }
        printf("\n");
    }
    
    fclose(file);
}

// Function to display usage information
void display_usage() {
    fprintf(stderr, "Usage: ./csv_reader <filename>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    read_csv(argv[1]);
    return EXIT_SUCCESS;
}