//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_LINE_SIZE 1024

// Function to get file size
long int get_file_size(char *filename) {
    struct stat st;
    if(stat(filename, &st) != 0) {
        fprintf(stderr, "Error getting file size\n");
        exit(EXIT_FAILURE);
    }
    return st.st_size;
}

// Function to check if file has extension
int has_extension(char *filename, char *extension) {
    int len = strlen(extension);
    if(len > strlen(filename)) {
        return 0;
    }
    return strncmp(&filename[strlen(filename)-len], extension, len) == 0;
}

// Function to extract metadata from file
void extract_metadata(char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char line[MAX_LINE_SIZE];
    int line_number = 0;
    while(fgets(line, MAX_LINE_SIZE, file) != NULL) {
        line_number++;
        if(line[0] == '/') {
            char *end = strchr(line, '\n');
            if(end != NULL) {
                *end = '\0';
            }
            printf("Line %d: %s\n", line_number, line);
        }
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <filename(s)>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for(int i=1; i<argc; i++) {
        char *filename = argv[i];
        if(has_extension(filename, ".c")) {
            long int file_size = get_file_size(filename);
            printf("%s (%ld bytes):\n", filename, file_size);
            extract_metadata(filename);
            printf("\n");
        }
    }
    return 0;
}