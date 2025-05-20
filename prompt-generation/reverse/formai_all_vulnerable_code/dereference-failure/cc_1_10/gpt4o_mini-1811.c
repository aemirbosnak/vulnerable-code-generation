//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

// Function to trim whitespace from the start and end of a string
char* trim_whitespace(char* str) {
    while (str[0] != '\0' && (str[0] == ' ' || str[0] == '\t')) str++;
    
    if (strlen(str) == 0) return str;

    char* end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t')) end--;
    
    *(end + 1) = '\0';
    return str;
}

// Function to split a line into columns based on delimiter
int split_line(char* line, char delimiter, char*** columns) {
    char* token;
    int count = 0;

    token = strtok(line, &delimiter);
    while (token != NULL) {
        (*columns)[count] = malloc(sizeof(char) * (strlen(token) + 1));
        if ((*columns)[count] == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        strcpy((*columns)[count], trim_whitespace(token));
        count++;

        token = strtok(NULL, &delimiter);
    }
    return count;
}

// Function to read a CSV file
void read_csv(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char** columns = malloc(MAX_COLUMNS * sizeof(char*));
    if (columns == NULL) {
        perror("Failed to allocate memory for columns");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    printf("Reading file: %s\n", filename);
    while (fgets(line, sizeof(line), file)) {
        int column_count = split_line(line, ',', &columns);
        
        for (int i = 0; i < column_count; i++) {
            printf("Column %d: %s\n", i + 1, columns[i]);
            free(columns[i]); // Free memory for each column
        }
    }

    free(columns);
    fclose(file);
}

// Main function to execute the program
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename.csv>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    read_csv(argv[1]);
    return 0;
}