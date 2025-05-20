//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *filename;
    char *data;
    int size;
} file_t;

file_t *files = NULL;
int num_files = 0;

void add_file(char *filename, char *data, int size) {
    file_t *new_file = (file_t *) malloc(sizeof(file_t));
    new_file->filename = strdup(filename);
    new_file->data = (char *) malloc(size);
    memcpy(new_file->data, data, size);
    new_file->size = size;
    files = realloc(files, sizeof(file_t) * ++num_files);
    files[num_files - 1] = *new_file;
    free(new_file);
}

int main() {
    char input_buffer[1024];
    char *filename = NULL;
    char *data = NULL;
    int size = 0;

    printf("Enter file name: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    filename = strtok(input_buffer, "\n");

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: File not found.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    data = (char *) malloc(size);
    fread(data, size, 1, file);
    fclose(file);

    add_file(filename, data, size);

    printf("Data recovery successful!\n");
    return 0;
}