//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *filename;
    int size;
    char *data;
} FILE_DATA;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read!= file_size) {
        printf("Error reading file.\n");
        free(buffer);
        fclose(file);
        return 1;
    }

    FILE_DATA *file_data = malloc(sizeof(FILE_DATA));
    if (file_data == NULL) {
        printf("Error allocating memory.\n");
        free(buffer);
        fclose(file);
        return 1;
    }

    file_data->filename = strdup(argv[1]);
    file_data->size = file_size;
    file_data->data = buffer;

    printf("File data recovered successfully.\n");
    printf("Filename: %s\n", file_data->filename);
    printf("File size: %ld bytes\n", file_data->size);

    free(buffer);
    fclose(file);
    return 0;
}