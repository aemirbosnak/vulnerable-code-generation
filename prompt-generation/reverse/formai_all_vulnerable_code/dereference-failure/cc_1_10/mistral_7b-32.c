//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LENGTH 100
#define FILE_PERMISSIONS 0644

// Custom error handling function
void custom_error(char *msg, int err_num) {
    fprintf(stderr, "%s: %s\n", msg, strerror(err_num));
    exit(EXIT_FAILURE);
}

// Function to check if file exists and has read permissions
int file_exists_and_readable(char *filename) {
    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) {
        custom_error("Error opening file:", errno);
    }
    if (S_ISREG(file_stat.st_mode) && (file_stat.st_mode & S_IRUSR)) {
        return 1;
    } else {
        custom_error("File not readable:", errno);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char filename[MAX_LENGTH];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc != 2) {
        custom_error("Usage: ./program filename", 1);
    }

    strcpy(filename, argv[1]);

    if (!file_exists_and_readable(filename)) {
        custom_error("Error: File not found or not readable.", 1);
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        custom_error("Error opening file:", errno);
    }

    while ((read = getline(&line, &len, file)) != -1) {
        // Process each line here
    }

    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}