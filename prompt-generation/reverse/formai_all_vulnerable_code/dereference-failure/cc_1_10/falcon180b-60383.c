//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    int size;
    char *data;
} File;

int read_file(const char *filename, File *file) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    file->size = 0;
    file->data = NULL;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        file->size += len;

        if (file->data == NULL) {
            file->data = malloc(len + 1);
        } else {
            file->data = realloc(file->data, file->size + 1);
        }

        strcat(file->data, line);
    }

    fclose(fp);
    return 0;
}

int write_file(const char *filename, const File *file) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file '%s' for writing\n", filename);
        exit(1);
    }

    fwrite(file->data, file->size, 1, fp);
    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <source_file> <destination_file> <mode>\n", argv[0]);
        printf("Modes:\n");
        printf("  0: Copy source to destination\n");
        printf("  1: Synchronize source with destination\n");
        return 1;
    }

    int mode = atoi(argv[3]);
    if (mode < 0 || mode > 1) {
        printf("Invalid mode\n");
        return 1;
    }

    File source_file, dest_file;
    read_file(argv[1], &source_file);
    read_file(argv[2], &dest_file);

    if (mode == 0) {
        write_file(argv[2], &source_file);
    } else if (mode == 1) {
        int i = 0, j = 0;
        while (i < source_file.size && j < dest_file.size) {
            if (source_file.data[i] == dest_file.data[j]) {
                i++;
                j++;
            } else {
                dest_file.data[j] = source_file.data[i];
                j++;
            }
        }

        while (i < source_file.size) {
            dest_file.data[j] = source_file.data[i];
            i++;
            j++;
        }

        write_file(argv[2], &dest_file);
    }

    free(source_file.data);
    free(dest_file.data);
    return 0;
}