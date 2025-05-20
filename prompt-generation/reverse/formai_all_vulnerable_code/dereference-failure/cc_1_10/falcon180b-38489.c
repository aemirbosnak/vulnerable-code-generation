//Falcon-180B DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_FILE_LENGTH 1000000

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char *buffer = malloc(MAX_FILE_LENGTH);
    char *result = malloc(MAX_FILE_LENGTH);
    int length = 0;

    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        if (length + strlen(buffer) >= MAX_FILE_LENGTH) {
            printf("Error: file is too long\n");
            exit(1);
        }
        strcat(result, buffer);
        length += strlen(buffer);
    }

    fclose(file);
    return result;
}

void write_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    if (fwrite(data, strlen(data), 1, file)!= 1) {
        printf("Error writing to file %s\n", filename);
        exit(1);
    }

    fclose(file);
}

int main() {
    char *filename = "example.txt";
    char *data = read_file(filename);
    printf("File contents:\n%s\n", data);

    char *new_data = strdup(data);
    strcat(new_data, "This is a new line of text.");
    write_file(filename, new_data);

    printf("New file contents:\n%s\n", new_data);
    free(new_data);
    free(data);
    return 0;
}