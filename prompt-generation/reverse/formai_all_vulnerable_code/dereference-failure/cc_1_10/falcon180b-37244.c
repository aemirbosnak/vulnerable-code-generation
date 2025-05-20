//Falcon-180B DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000
#define MAX_LINE_SIZE 1000

int main() {
    FILE *file;
    char *filename = "example.txt";
    char buffer[MAX_FILE_SIZE];
    char line[MAX_LINE_SIZE];
    int num_lines = 0;
    int line_size = 0;
    int i = 0;

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read the file into a buffer
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    if (fread(buffer, 1, file_size, file)!= file_size) {
        printf("Error reading file %s\n", filename);
        exit(1);
    }

    // Count the number of lines in the file
    char *p = strtok(buffer, "\n");
    while (p!= NULL) {
        num_lines++;
        p = strtok(NULL, "\n");
    }

    // Print the number of lines in the file
    printf("The file %s contains %d lines.\n", filename, num_lines);

    // Print the contents of the file
    rewind(file);
    p = strtok(buffer, "\n");
    while (p!= NULL) {
        strcpy(line, p);
        line_size = strlen(line);
        if (line_size > MAX_LINE_SIZE) {
            printf("Line truncated: %s\n", line);
        } else {
            printf("%s\n", line);
        }
        p = strtok(NULL, "\n");
    }

    // Close the file
    fclose(file);

    return 0;
}