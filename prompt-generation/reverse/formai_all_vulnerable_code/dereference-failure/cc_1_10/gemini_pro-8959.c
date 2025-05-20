//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    char *data;
    size_t size;
} file_t;

file_t *files;
size_t num_files;

void add_file(char *name, char *data, size_t size) {
    files = realloc(files, sizeof(file_t) * (num_files + 1));
    files[num_files].name = strdup(name);
    files[num_files].data = malloc(size);
    memcpy(files[num_files].data, data, size);
    files[num_files].size = size;
    num_files++;
}

void recover_files(char *path) {
    FILE *fp = fopen(path, "rb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    char *data = malloc(size);
    if (data == NULL) {
        perror("malloc");
        fclose(fp);
        return;
    }

    if (fread(data, 1, size, fp) != size) {
        perror("fread");
        fclose(fp);
        free(data);
        return;
    }

    fclose(fp);

    char *ptr = data;
    while (ptr < data + size) {
        char *name = ptr;
        ptr += strlen(name) + 1;

        char *data = ptr;
        size_t size = *(size_t *)ptr;
        ptr += sizeof(size_t);

        add_file(name, data, size);
    }

    free(data);
}

void save_file(char *path, file_t *file) {
    FILE *fp = fopen(path, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fwrite(file->name, 1, strlen(file->name) + 1, fp);
    fwrite(&file->size, sizeof(size_t), 1, fp);
    fwrite(file->data, 1, file->size, fp);

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <path to recovery file> <path to save recovered file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    recover_files(argv[1]);

    for (size_t i = 0; i < num_files; i++) {
        char path[256];
        snprintf(path, sizeof(path), "%s/%s", argv[2], files[i].name);
        save_file(path, &files[i]);
    }

    for (size_t i = 0; i < num_files; i++) {
        free(files[i].name);
        free(files[i].data);
    }
    free(files);

    return EXIT_SUCCESS;
}