//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

typedef struct {
    char *name;
    int size;
    char *data;
} File;

int is_infected(char *data, int size) {
    int i, j;
    for (i = 0; i < size - 4; i++) {
        if (data[i] == 0xE8 && data[i + 1] == 0x00 && data[i + 2] == 0x00 && data[i + 3] == 0x00) {
            for (j = i + 4; j < size - 1; j++) {
                if (!isdigit(data[j])) {
                    break;
                }
            }
            if (j == size - 1) {
                return 1;
            }
        }
    }
    return 0;
}

void scan_file(File *file) {
    int i, j;
    for (i = 0; i < file->size; i++) {
        if (is_infected(file->data + i, file->size - i)) {
            printf("Infected file: %s\n", file->name);
            exit(1);
        }
    }
}

void read_file(char *path, File *file) {
    FILE *fp;
    fp = fopen(path, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", path);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    file->data = malloc(file->size);
    fread(file->data, 1, file->size, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    int i;
    if (argc < 2) {
        printf("Usage: %s file1 [file2...]\n", argv[0]);
        exit(1);
    }
    for (i = 1; i < argc; i++) {
        File file;
        read_file(argv[i], &file);
        if (file.size > MAX_FILE_SIZE) {
            printf("File too large: %s\n", argv[i]);
            exit(1);
        }
        scan_file(&file);
        free(file.data);
    }
    return 0;
}