//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} File;

int compare_files(const void *a, const void *b) {
    const File *file1 = a;
    const File *file2 = b;

    return strcmp(file1->name, file2->name);
}

void read_file(const char *path, File *file) {
    FILE *fp = fopen(path, "rb");

    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", path);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (file->size > MAX_FILE_SIZE) {
        fprintf(stderr, "File is too large: %s\n", path);
        exit(1);
    }

    file->data = malloc(file->size);
    if (!file->data) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    fread(file->data, 1, file->size, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    File files[100];
    int num_files = 0;

    for (int i = 1; i < argc; i++) {
        File file;
        strcpy(file.name, argv[i]);
        read_file(argv[i], &file);
        files[num_files++] = file;
    }

    qsort(files, num_files, sizeof(File), compare_files);

    for (int i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }

    return 0;
}