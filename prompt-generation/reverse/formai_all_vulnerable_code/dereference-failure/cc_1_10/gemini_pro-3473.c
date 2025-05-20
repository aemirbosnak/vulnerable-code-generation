//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    char *data;
    size_t size;
} CyberpunkFile;

CyberpunkFile *load_file(const char *filename) {
    CyberpunkFile *file = malloc(sizeof(CyberpunkFile));
    if (file == NULL) {
        return NULL;
    }
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        free(file);
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);
    file->data = malloc(file->size + 1);
    if (file->data == NULL) {
        fclose(fp);
        free(file);
        return NULL;
    }
    fread(file->data, file->size, 1, fp);
    file->data[file->size] = '\0';
    fclose(fp);
    return file;
}

void free_file(CyberpunkFile *file) {
    if (file != NULL) {
        if (file->name != NULL) {
            free(file->name);
        }
        if (file->data != NULL) {
            free(file->data);
        }
        free(file);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    CyberpunkFile *file = load_file(argv[1]);
    if (file == NULL) {
        printf("Error: could not load file %s\n", argv[1]);
        return 1;
    }
    printf("%s", file->data);
    free_file(file);
    return 0;
}