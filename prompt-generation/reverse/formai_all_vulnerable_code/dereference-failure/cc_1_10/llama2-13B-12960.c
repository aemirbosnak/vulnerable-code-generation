//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10

void read_file(const char* file_name, char** lines) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        *lines = realloc(*lines, (strlen(*lines) + strlen(line) + 1) * sizeof(char));
        strcat(*lines, line);
    }

    fclose(file);
}

void write_file(const char* file_name, char* lines) {
    FILE* file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    fprintf(file, "%s", lines);
    fclose(file);
}

void append_file(const char* file_name, char* lines) {
    FILE* file = fopen(file_name, "a");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    fprintf(file, "%s", lines);
    fclose(file);
}

int main() {
    char* lines = NULL;

    // Example 1: Read a file and print its contents
    read_file("example1.txt", &lines);
    printf("File contents: %s\n", lines);
    free(lines);

    // Example 2: Write a file with a given content
    char content[] = "This is a sample content";
    write_file("example2.txt", content);

    // Example 3: Append a line to an existing file
    char append_content[] = "This is an append content";
    append_file("example3.txt", append_content);

    return 0;
}