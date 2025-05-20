//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Cryptic
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    size_t size;
    unsigned char *data;
} File;

File *read_file(const char *path) {
    FILE *fp = fopen(path, "rb");
    if (!fp) return NULL;

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    File *file = malloc(sizeof(File));
    file->name = strdup(path);
    file->size = size;
    file->data = malloc(size);
    fread(file->data, 1, size, fp);
    fclose(fp);

    return file;
}

void free_file(File *file) {
    free(file->name);
    free(file->data);
    free(file);
}

int compare_files(File *file1, File *file2) {
    if (file1->size != file2->size) return 0;

    for (size_t i = 0; i < file1->size; i++) {
        if (file1->data[i] != file2->data[i]) return 0;
    }

    return 1;
}

void sync_files(File *file1, File *file2) {
    if (compare_files(file1, file2)) return;

    if (file1->size < file2->size) {
        file1->data = realloc(file1->data, file2->size);
        file1->size = file2->size;
    }

    memcpy(file1->data, file2->data, file2->size);
}

int main() {
    File *file1 = read_file("file1.txt");
    if (!file1) return EXIT_FAILURE;

    File *file2 = read_file("file2.txt");
    if (!file2) return EXIT_FAILURE;

    sync_files(file1, file2);

    FILE *fp = fopen("file1.txt", "wb");
    if (!fp) return EXIT_FAILURE;

    fwrite(file1->data, 1, file1->size, fp);
    fclose(fp);

    free_file(file1);
    free_file(file2);

    return EXIT_SUCCESS;
}