//Falcon-180B DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
} File;

int create_file(const char *filename);
int open_file(const char *filename);
int close_file(File *file);
int write_file(File *file, const char *data);
int read_file(File *file, char *buffer);

int main() {
    char filename[MAX_LINE_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);

    File file;
    if (create_file(filename)) {
        printf("File created successfully!\n");
    } else {
        printf("File creation failed.\n");
        return 1;
    }

    char data[MAX_LINE_SIZE];
    printf("Enter data to write: ");
    scanf("%s", data);

    if (write_file(&file, data)) {
        printf("Data written successfully!\n");
    } else {
        printf("Data write failed.\n");
        return 1;
    }

    char buffer[MAX_LINE_SIZE];
    if (read_file(&file, buffer)) {
        printf("Data read successfully! (%s)\n", buffer);
    } else {
        printf("Data read failed.\n");
        return 1;
    }

    close_file(&file);
    return 0;
}

int create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return 0;
    } else {
        fclose(file);
        return 1;
    }
}

int open_file(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        return 0;
    } else {
        return 1;
    }
}

int close_file(File *file) {
    fclose(file->file);
    return 1;
}

int write_file(File *file, const char *data) {
    fprintf(file->file, "%s", data);
    return 1;
}

int read_file(File *file, char *buffer) {
    fgets(buffer, MAX_LINE_SIZE, file->file);
    return 1;
}