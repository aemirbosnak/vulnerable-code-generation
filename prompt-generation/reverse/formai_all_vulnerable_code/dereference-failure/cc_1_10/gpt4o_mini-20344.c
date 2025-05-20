//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 1024

typedef struct {
    FILE *file;
    char *filename;
} FileHandler;

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

FileHandler *open_file(const char *filename, const char *mode) {
    FileHandler *fh = malloc(sizeof(FileHandler));
    if (!fh) {
        handle_error("Failed to allocate memory for FileHandler");
    }

    fh->filename = strdup(filename);
    if (!fh->filename) {
        free(fh);
        handle_error("Failed to allocate memory for filename");
    }

    fh->file = fopen(filename, mode);
    if (!fh->file) {
        free(fh->filename);
        free(fh);
        handle_error("Could not open file");
    }

    return fh;
}

void close_file(FileHandler *fh) {
    if (fh) {
        if (fh->file) {
            fclose(fh->file);
            printf("Closed the file: %s\n", fh->filename);
        }
        free(fh->filename);
        free(fh);
    } else {
        printf("FileHandler is NULL, nothing to close.\n");
    }
}

void write_to_file(FileHandler *fh, const char *data) {
    if (!fh || !fh->file) {
        handle_error("FileHandler is NULL or file pointer is invalid");
    }

    if (fputs(data, fh->file) == EOF) {
        handle_error("Failed to write to file");
    }
    printf("Wrote to file: %s\n", fh->filename);
}

void read_from_file(FileHandler *fh) {
    if (!fh || !fh->file) {
        handle_error("FileHandler is NULL or file pointer is invalid");
    }

    char buffer[256];
    printf("Contents of %s:\n", fh->filename);
    
    while (fgets(buffer, sizeof(buffer), fh->file)) {
        printf("%s", buffer);
    }

    if (ferror(fh->file)) {
        handle_error("Error reading from file");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <data>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    const char *data = argv[2];

    FileHandler *fh = open_file(filename, "w+");
    write_to_file(fh, data);
    close_file(fh);

    fh = open_file(filename, "r");
    read_from_file(fh);
    close_file(fh);

    return EXIT_SUCCESS;
}