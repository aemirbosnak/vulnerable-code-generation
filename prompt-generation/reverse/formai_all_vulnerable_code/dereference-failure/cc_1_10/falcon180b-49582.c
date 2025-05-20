//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int line_number;
    char line[MAX_LINE_LENGTH];
} LineInfo;

void process_line(char *line, int line_number) {
    // Do something with the line...
    printf("Line %d: %s\n", line_number, line);
}

int main(int argc, char *argv[]) {
    FILE *input_file = NULL;
    char file_name[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open the input file
    strcpy(file_name, argv[1]);
    input_file = fopen(file_name, "r");

    if (input_file == NULL) {
        printf("Error opening file: %s\n", file_name);
        return 1;
    }

    // Read each line and process it
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_number++;
        process_line(line, line_number);
    }

    // Close the input file
    fclose(input_file);

    return 0;
}