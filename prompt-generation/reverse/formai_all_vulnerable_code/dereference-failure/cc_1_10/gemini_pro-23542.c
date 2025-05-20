//GEMINI-pro DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent a file
struct file {
    char *name;
    char *contents;
    size_t size;
};

// A function to create a new file
struct file *file_new(const char *name, const char *contents) {
    struct file *file = malloc(sizeof(struct file));
    if (!file) {
        return NULL;
    }

    file->name = strdup(name);
    if (!file->name) {
        free(file);
        return NULL;
    }

    file->size = strlen(contents) + 1;
    file->contents = malloc(file->size);
    if (!file->contents) {
        free(file->name);
        free(file);
        return NULL;
    }

    strcpy(file->contents, contents);

    return file;
}

// A function to open a file
struct file *file_open(const char *name) {
    FILE *fp = fopen(name, "r");
    if (!fp) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    char *contents = malloc(size + 1);
    if (!contents) {
        fclose(fp);
        return NULL;
    }

    fread(contents, 1, size, fp);
    fclose(fp);

    contents[size] = '\0';

    return file_new(name, contents);
}

// A function to save a file
int file_save(struct file *file) {
    FILE *fp = fopen(file->name, "w");
    if (!fp) {
        return -1;
    }

    fwrite(file->contents, 1, file->size, fp);
    fclose(fp);

    return 0;
}

// A function to close a file
void file_close(struct file *file) {
    free(file->name);
    free(file->contents);
    free(file);
}

// A function to print a file
void file_print(struct file *file) {
    printf("File: %s\n", file->name);
    printf("Contents: %s\n", file->contents);
}

int main() {
    // Create a new file
    struct file *file = file_new("test.txt", "Hello, world!");
    if (!file) {
        return -1;
    }

    // Open a file
    struct file *file2 = file_open("test2.txt");
    if (!file2) {
        return -1;
    }

    // Save a file
    if (file_save(file) == -1) {
        return -1;
    }

    // Print a file
    file_print(file);
    file_print(file2);

    // Close the files
    file_close(file);
    file_close(file2);

    return 0;
}