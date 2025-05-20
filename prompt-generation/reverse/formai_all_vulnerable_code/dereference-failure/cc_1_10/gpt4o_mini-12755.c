//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 64

void parseCSVLine(char *line, char **columns, int *columnCount) {
    char *token;
    int count = 0;
    int inQuotes = 0;
    char *ptr = line;

    while (*ptr) {
        if (*ptr == '\"') {
            inQuotes = !inQuotes;
        } else if (*ptr == ',' && !inQuotes) {
            *ptr = '\0';
            columns[count++] = token ? token : ptr + 1;
            token = NULL;
        }
        if (!token && *ptr != '\"' && *ptr != ' ') {
            token = ptr;  // Mark start of a new token
        }
        ptr++;
    }
    if (token) {
        columns[count++] = token; // Last token
    }
    *columnCount = count;
}

void trim(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0'; // Null terminate string after last character
}

void readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char *columns[MAX_COLUMNS];
    int columnCount;

    // Read each line from the CSV file
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        // Parse the line into columns
        parseCSVLine(line, columns, &columnCount);
        
        // Print the parsed columns
        for (int i = 0; i < columnCount; i++) {
            trim(columns[i]); // Trim whitespace
            printf("[%s] ", columns[i]);
        }
        printf("\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    readCSV(argv[1]);
    return 0;
}