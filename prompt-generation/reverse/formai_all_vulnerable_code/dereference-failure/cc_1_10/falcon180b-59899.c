//Falcon-180B DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_FILE_SIZE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    FILE *file;
} File;

void open_file(File *file, const char *filename) {
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
    }
}

int read_line(File *file, char *buffer) {
    int length = fread(buffer, sizeof(char), MAX_NAME_LENGTH, file->file);
    if (ferror(file->file)) {
        printf("Error: Could not read line from file\n");
        exit(1);
    }
    buffer[length] = '\0';
    return length;
}

void print_name(const char *name) {
    printf("Name: %s\n", name);
}

int main() {
    File file;
    char buffer[MAX_NAME_LENGTH];
    int length;

    printf("Enter filename: ");
    scanf("%s", file.name);

    open_file(&file, file.name);

    while ((length = read_line(&file, buffer)) > 0) {
        print_name(buffer);
    }

    close_file(&file);

    return 0;
}