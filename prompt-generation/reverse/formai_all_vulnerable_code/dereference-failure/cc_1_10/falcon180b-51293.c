//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
    char buffer[BUFFER_SIZE];
    int buffer_index;
    int file_size;
} FileData;

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FileData file_data = {
       .filename = filename,
       .file = fopen(filename, "rb"),
       .buffer_index = 0,
       .file_size = 0
    };

    if (file_data.file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    fseek(file_data.file, 0, SEEK_END);
    file_data.file_size = ftell(file_data.file);
    rewind(file_data.file);

    char *buffer = malloc(file_data.file_size + 1);
    if (buffer == NULL) {
        printf("Error: Could not allocate memory\n");
        return 1;
    }

    fread(buffer, file_data.file_size, 1, file_data.file);
    buffer[file_data.file_size] = '\0';

    printf("Original file content:\n%s\n", buffer);

    free(buffer);
    fclose(file_data.file);

    return 0;
}