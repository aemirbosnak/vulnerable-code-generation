//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximum length of file path
#define MAX_PATH_LEN 255

// structure to hold metadata
struct Metadata {
    char file_name[MAX_PATH_LEN];
    int file_size;
    char file_type[MAX_PATH_LEN];
    char last_modified[MAX_PATH_LEN];
};

// function to parse metadata from file
struct Metadata parse_metadata(char *file_path) {
    struct Metadata metadata;
    strcpy(metadata.file_name, file_path);

    // determine file size
    FILE *file = fopen(file_path, "rb");
    fseek(file, 0L, SEEK_END);
    metadata.file_size = ftell(file);
    fclose(file);

    // determine file type
    char *extension = strrchr(file_path, '.');
    if (extension != NULL) {
        strcpy(metadata.file_type, extension + 1);
    } else {
        strcpy(metadata.file_type, "unknown");
    }

    // determine last modified date
    char command[MAX_PATH_LEN + 20] = "date -r ";
    strcat(command, file_path);
    FILE *date_output = popen(command, "r");
    fgets(metadata.last_modified, MAX_PATH_LEN, date_output);
    pclose(date_output);

    return metadata;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: metadata <file_path>\n");
        return 1;
    }

    char *file_path = argv[1];
    struct Metadata metadata = parse_metadata(file_path);
    printf("File name: %s\nFile size: %d bytes\nFile type: %s\nLast modified: %s", metadata.file_name, metadata.file_size, metadata.file_type, metadata.last_modified);

    return 0;
}