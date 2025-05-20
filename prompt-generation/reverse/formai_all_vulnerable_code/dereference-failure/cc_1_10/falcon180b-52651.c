//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1 MB
#define VIRUS_SIGNATURE "VIRUS"
#define VIRUS_SIGNATURE_LENGTH strlen(VIRUS_SIGNATURE)
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    FILE *file;
    char *filename;
    char *buffer;
    size_t buffer_size;
    size_t file_size;
} FileScanner;

int is_infected(FileScanner *scanner) {
    char *buffer = scanner->buffer;
    size_t buffer_size = scanner->buffer_size;
    size_t file_size = scanner->file_size;

    for (size_t i = 0; i < file_size; i++) {
        if (strncmp(buffer + i, VIRUS_SIGNATURE, VIRUS_SIGNATURE_LENGTH) == 0) {
            printf("Virus found in file: %s\n", scanner->filename);
            return 1;
        }
    }

    return 0;
}

void scan_file(char *filename, FileScanner *scanner) {
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;

    if ((scanner->file = fopen(filename, "rb")) == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    scanner->filename = filename;
    scanner->buffer = buffer;
    scanner->buffer_size = sizeof(buffer);
    scanner->file_size = 0;

    while ((bytes_read = fread(buffer, 1, scanner->buffer_size, scanner->file)) > 0) {
        scanner->buffer_size = bytes_read;
        scanner->file_size += bytes_read;
    }

    is_infected(scanner);

    fclose(scanner->file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    FileScanner scanner;
    char *filename = argv[1];

    if (strlen(filename) >= MAX_FILE_NAME_LENGTH) {
        printf("Error: filename is too long.\n");
        exit(1);
    }

    scan_file(filename, &scanner);

    return 0;
}