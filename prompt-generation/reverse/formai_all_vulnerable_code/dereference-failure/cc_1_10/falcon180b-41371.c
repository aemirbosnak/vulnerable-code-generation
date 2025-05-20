//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_LENGTH 100
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *name;
    char *extension;
    unsigned char *data;
    size_t size;
} File;

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} Virus;

void read_file(const char *filename, File *file) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    file->data = malloc(file->size + 1);
    if (file->data == NULL) {
        printf("Error allocating memory for file data\n");
        exit(1);
    }

    fread(file->data, file->size, 1, fp);
    fclose(fp);

    file->data[file->size] = 0;
}

void scan_file(const Virus *virus, const File *file) {
    size_t i;
    for (i = 0; i < file->size - virus->size; i++) {
        if (memcmp(file->data + i, virus->data, virus->size) == 0) {
            printf("Virus found in file: %s\n", file->name);
            exit(1);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <file> <virus>\n", argv[0]);
        exit(1);
    }

    File file;
    read_file(argv[1], &file);

    Virus virus;
    virus.name = argv[2];
    virus.data = malloc(MAX_VIRUS_LENGTH);
    virus.size = strlen(virus.name);
    if (virus.data == NULL) {
        printf("Error allocating memory for virus data\n");
        exit(1);
    }

    strcpy(virus.data, virus.name);

    scan_file(&virus, &file);

    printf("No virus found in file: %s\n", argv[1]);
    exit(0);
}