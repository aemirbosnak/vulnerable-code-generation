//GEMINI-pro DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// A simple struct to hold a file's contents
typedef struct {
    char *data;
    size_t size;
} FileContents;

// Read the contents of the file specified by `filename` into a `FileContents` struct
FileContents *read_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    // Allocate memory for the file data
    char *data = malloc(size + 1);
    if (!data) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    // Read the file data
    if (fread(data, 1, size, fp) != size) {
        perror("fread");
        free(data);
        fclose(fp);
        return NULL;
    }

    data[size] = '\0'; // null-terminate the string

    FileContents *fc = malloc(sizeof(FileContents));
    if (!fc) {
        perror("malloc");
        free(data);
        fclose(fp);
        return NULL;
    }

    fc->data = data;
    fc->size = size;

    fclose(fp);

    return fc;
}

// Write the contents of a `FileContents` struct to the file specified by `filename`
int write_file(const char *filename, FileContents *fc) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    if (fwrite(fc->data, 1, fc->size, fp) != fc->size) {
        perror("fwrite");
        fclose(fp);
        return -1;
    }

    fclose(fp);

    return 0;
}

// Free the memory allocated for a `FileContents` struct
void free_file_contents(FileContents *fc) {
    free(fc->data);
    free(fc);
}

int main(void) {
    // Read the contents of the file "input.txt"
    FileContents *fc = read_file("input.txt");
    if (!fc) {
        return EXIT_FAILURE;
    }

    // Convert the file contents to uppercase
    for (size_t i = 0; i < fc->size; i++) {
        fc->data[i] = toupper(fc->data[i]);
    }

    // Write the converted contents to the file "output.txt"
    if (write_file("output.txt", fc) != 0) {
        return EXIT_FAILURE;
    }

    // Free the memory allocated for the `FileContents` struct
    free_file_contents(fc);

    return EXIT_SUCCESS;
}