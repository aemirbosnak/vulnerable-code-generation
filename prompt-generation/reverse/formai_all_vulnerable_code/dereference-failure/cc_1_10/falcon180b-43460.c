//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include <sys/stat.h>

// Function to extract metadata from a file
void extract_metadata(const char* filename, char* buffer, size_t size) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        snprintf(buffer, size, "Error: Could not open file '%s'", filename);
        return;
    }

    struct stat file_stat;
    if (fstat(fileno(file), &file_stat) == -1) {
        snprintf(buffer, size, "Error: Could not get file status for '%s'", filename);
        fclose(file);
        return;
    }

    time_t creation_time = file_stat.st_ctime;
    char* creation_date = ctime(&creation_time);
    creation_date[strcspn(creation_date, "\n")] = '\0';

    size_t file_size = file_stat.st_size;

    snprintf(buffer, size, "File: %s\nFile size: %zu bytes\nCreation date: %s", filename, file_size, creation_date);

    fclose(file);
}

// Function to extract metadata for multiple files
void extract_metadata_multiple(int argc, char* argv[], char* buffer, size_t size) {
    if (argc < 2) {
        snprintf(buffer, size, "Error: No files specified");
        return;
    }

    for (int i = 1; i < argc; i++) {
        char filename[1024];
        snprintf(filename, sizeof(filename), "%s", argv[i]);
        extract_metadata(filename, buffer, size);
    }
}

int main(int argc, char* argv[]) {
    char output[1024];
    extract_metadata_multiple(argc, argv, output, sizeof(output));
    printf("%s", output);
    return 0;
}