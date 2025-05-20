//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FILES 1000
#define MAX_FILE_NAME_LENGTH 100

struct file_metadata {
    char file_name[MAX_FILE_NAME_LENGTH];
    int line_count;
};

void extract_metadata(char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", file_name);
        exit(1);
    }

    struct file_metadata metadata;
    memset(&metadata, 0, sizeof(metadata));

    char line[MAX_LINE_LENGTH];
    int line_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_count++;
    }

    metadata.line_count = line_count;
    strncpy(metadata.file_name, file_name, MAX_FILE_NAME_LENGTH - 1);

    printf("File: %s\n", metadata.file_name);
    printf("Line Count: %d\n", metadata.line_count);

    fclose(file);
}

int main() {
    char *file_names[MAX_NUM_FILES];
    int num_files = 0;

    printf("Enter file names (press enter when done):\n");

    while (num_files < MAX_NUM_FILES && fgets(file_names[num_files], MAX_FILE_NAME_LENGTH, stdin)!= NULL) {
        file_names[num_files][strcspn(file_names[num_files], "\n")] = '\0';
        num_files++;
    }

    for (int i = 0; i < num_files; i++) {
        extract_metadata(file_names[i]);
    }

    return 0;
}