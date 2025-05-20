//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[256];
    char data[MAX_FILE_SIZE];
    int size;
} file_t;

file_t files[MAX_FILES];
int num_files = 0;

void add_file(char *name, char *data, int size) {
    if (num_files == MAX_FILES) {
        fprintf(stderr, "Error: too many files\n");
        exit(1);
    }

    strcpy(files[num_files].name, name);
    memcpy(files[num_files].data, data, size);
    files[num_files].size = size;
    num_files++;
}

void save_backup(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    fwrite(&num_files, sizeof(int), 1, fp);
    for (int i = 0; i < num_files; i++) {
        fwrite(files[i].name, sizeof(char), 256, fp);
        fwrite(files[i].data, sizeof(char), files[i].size, fp);
    }

    fclose(fp);
}

void load_backup(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    fread(&num_files, sizeof(int), 1, fp);
    for (int i = 0; i < num_files; i++) {
        fread(files[i].name, sizeof(char), 256, fp);
        fread(files[i].data, sizeof(char), files[i].size, fp);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <command> <filename>\n", argv[0]);
        exit(1);
    }

    char *command = argv[1];
    char *filename = argv[2];

    if (strcmp(command, "save") == 0) {
        save_backup(filename);
    } else if (strcmp(command, "load") == 0) {
        load_backup(filename);
    } else {
        fprintf(stderr, "Error: invalid command\n");
        exit(1);
    }

    return 0;
}