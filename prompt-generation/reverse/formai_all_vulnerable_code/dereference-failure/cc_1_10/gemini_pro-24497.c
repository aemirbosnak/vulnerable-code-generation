//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *filename;
    size_t size;
    char *data;
} File;

File *read_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(size);
    if (!data) {
        fclose(fp);
        return NULL;
    }

    fread(data, 1, size, fp);
    fclose(fp);

    File *file = malloc(sizeof(File));
    if (!file) {
        free(data);
        return NULL;
    }

    file->filename = filename;
    file->size = size;
    file->data = data;

    return file;
}

void write_file(char *filename, File *file) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }

    fwrite(file->data, 1, file->size, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    
    char *filename = argv[1];
    File *file = read_file(filename);
    if (!file) {
        printf("Error: Could not read file %s\n", filename);
        return 1;
    }

    char *new_filename = strtok(filename, ".");
    strcat(new_filename, "_recovered.txt");
    write_file(new_filename, file);

    printf("File %s recovered to %s\n", filename, new_filename);
    return 0;
}