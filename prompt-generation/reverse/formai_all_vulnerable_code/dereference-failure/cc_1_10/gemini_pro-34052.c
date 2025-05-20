//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *data;
    size_t size;
} File;

File *file_open(const char *name) {
    FILE *fp = fopen(name, "rb");
    if (!fp) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(size + 1);
    fread(data, 1, size, fp);
    data[size] = '\0';

    fclose(fp);

    File *file = malloc(sizeof(File));
    file->name = strdup(name);
    file->data = data;
    file->size = size;

    return file;
}

void file_close(File *file) {
    free(file->name);
    free(file->data);
    free(file);
}

char *file_search(File *file, const char *pattern) {
    size_t pattern_len = strlen(pattern);

    for (size_t i = 0; i < file->size - pattern_len; i++) {
        if (!memcmp(file->data + i, pattern, pattern_len)) {
            return file->data + i;
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file> <pattern>\n", argv[0]);
        return 1;
    }

    File *file = file_open(argv[1]);
    if (!file) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    char *result = file_search(file, argv[2]);
    if (!result) {
        printf("Error: could not find pattern '%s' in file '%s'\n", argv[2], argv[1]);
        file_close(file);
        return 1;
    }

    printf("Found pattern '%s' at offset %ld in file '%s'\n", argv[2], result - file->data, argv[1]);

    file_close(file);

    return 0;
}