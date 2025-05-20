//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

// Function to trim whitespace from a string
char* trimWhitespace(char* str) {
    char* end;

    // Trim leading space
    while (*str == ' ') str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\n' || *end == '\r')) end--;
    end[1] = '\0';

    return str;
}

// Function to read a CSV file
void readCSV(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int lineCount = 0;

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Trim whitespace and newline characters
        char* trimmedLine = trimWhitespace(line);
        char* columns[MAX_COLUMNS];

        // Tokenize the line into columns
        int columnCount = 0;
        char* token = strtok(trimmedLine, ",");
        while (token != NULL && columnCount < MAX_COLUMNS) {
            columns[columnCount++] = token;
            token = strtok(NULL, ",");
        }

        // Print the columns read from the line
        printf("Line %d: ", ++lineCount);
        for (int i = 0; i < columnCount; i++) {
            if (i > 0) {
                printf(" | ");
            }
            printf("%s", columns[i]);
        }
        printf("\n");
    }

    fclose(file);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    readCSV(argv[1]);

    return EXIT_SUCCESS;
}