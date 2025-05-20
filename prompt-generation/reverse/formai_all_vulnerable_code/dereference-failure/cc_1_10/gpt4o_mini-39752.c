//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

// Function to trim whitespace from both ends of a string
char *trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while(*str == ' ') str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && *end == ' ') end--;

    // Null terminate
    *(end + 1) = '\0';

    return str;
}

// Function to split a line into columns based on a delimiter
void split_line(char *line, char **columns, char delimiter, int *column_count) {
    char *token = strtok(line, &delimiter);
    *column_count = 0;

    while (token != NULL) {
        columns[*column_count] = trim_whitespace(token);
        (*column_count)++;
        token = strtok(NULL, &delimiter);
    }
}

// Function to read CSV file and print its content
void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open the file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char *columns[MAX_COLUMNS];
    int column_count;
    
    // Read header line
    if (fgets(line, sizeof(line), file)) {
        printf("Header: ");
        split_line(line, columns, ',', &column_count);
        for (int i = 0; i < column_count; i++) {
            printf("%s", columns[i]);
            if (i < column_count - 1) printf(", ");
        }
        printf("\n\n");
    } else {
        perror("Could not read header line");
        fclose(file);
        return;
    }

    // Read data lines
    while (fgets(line, sizeof(line), file)) {
        split_line(line, columns, ',', &column_count);
        printf("Row: ");
        for (int i = 0; i < column_count; i++) {
            printf("%s", columns[i]);
            if (i < column_count - 1) printf(", ");
        }
        printf("\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csvfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv(argv[1]);

    return EXIT_SUCCESS;
}