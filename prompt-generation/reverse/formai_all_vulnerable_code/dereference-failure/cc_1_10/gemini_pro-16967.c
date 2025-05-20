//GEMINI-pro DATASET v1.0 Category: File handling ; Style: future-proof
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Custom error handling macro.
#define CHECK(expr)                                                                 \
    do {                                                                            \
        if (!(expr)) {                                                               \
            perror(#expr);                                                           \
            exit(EXIT_FAILURE);                                                      \
        }                                                                           \
    } while (0)

// Custom file handling macro.
#define FILE_CHECK(expr)                                                              \
    do {                                                                            \
        if ((expr) == NULL) {                                                        \
            perror(#expr);                                                           \
            exit(EXIT_FAILURE);                                                      \
        }                                                                           \
    } while (0)

// Function to create a temporary file in the current working directory.
FILE *create_temp_file(void) {
    char *template = "XXXXXX";
    int fd;

    fd = mkstemp(template);
    FILE_CHECK(fd != -1);

    return fdopen(fd, "w+");
}

// Function to write a string to a file.
void write_to_file(FILE *file, const char *str) {
    size_t len = strlen(str);

    CHECK(fwrite(str, 1, len, file) == len);
}

// Function to read a string from a file.
char *read_from_file(FILE *file) {
    char *buf = NULL;
    size_t len;

    fseek(file, 0, SEEK_END);
    len = ftell(file);
    fseek(file, 0, SEEK_SET);

    buf = malloc(len + 1);
    CHECK(buf != NULL);

    CHECK(fread(buf, 1, len, file) == len);
    buf[len] = '\0';

    return buf;
}

// Function to delete a file.
void delete_file(const char *path) {
    CHECK(remove(path) == 0);
}

int main(void) {
    FILE *temp_file;

    // Create a temporary file.
    temp_file = create_temp_file();

    // Write a string to the file.
    write_to_file(temp_file, "Hello, world!\n");

    // Read a string from the file.
    char *str = read_from_file(temp_file);

    // Print the string.
    printf("%s", str);

    // Delete the file.
    delete_file(temp_file);

    // Free the string.
    free(str);

    return 0;
}