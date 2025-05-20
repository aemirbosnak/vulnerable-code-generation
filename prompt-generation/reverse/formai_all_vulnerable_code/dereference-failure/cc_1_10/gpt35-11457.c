//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_CHARS_PER_COL 50
#define MAX_INPUT_BUFFER 1000

int main(int argc, char *argv[]) {
    FILE *fp;
    char *delim;
    char input_buffer[MAX_INPUT_BUFFER];
    char *col_positions[MAX_COLS];
    char *col_vals[MAX_COLS];
    int col_count = 0;

    // Get file name and delimiter from command-line arguments
    if (argc < 3) {
        printf("Usage: csv_reader <file_name> <delimiter>\n");
        return 1;
    }
    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    delim = argv[2];

    // Read first line of file (header row)
    if (!fgets(input_buffer, MAX_INPUT_BUFFER, fp)) {
        printf("Error reading file %s\n", argv[1]);
        return 1;
    }

    // Parse header row to get column positions
    char *pos = strtok(input_buffer, delim);
    while (pos) {
        col_positions[col_count++] = pos;
        if (col_count >= MAX_COLS) {
            printf("Too many columns in file %s\n", argv[1]);
            return 1;
        }
        pos = strtok(NULL, delim);
    }

    // Loop through remaining lines of file
    while (fgets(input_buffer, MAX_INPUT_BUFFER, fp)) {
        char *val = strtok(input_buffer, delim);
        col_count = 0;
        while (val) {
            col_vals[col_count++] = val;
            if (col_count >= MAX_COLS) {
                printf("Too many columns in file %s\n", argv[1]);
                return 1;
            }
            val = strtok(NULL, delim);
        }

        // Print values for this row
        for (int i = 0; i < col_count; i++) {
            printf("%s: %s\n", col_positions[i], col_vals[i]);
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}