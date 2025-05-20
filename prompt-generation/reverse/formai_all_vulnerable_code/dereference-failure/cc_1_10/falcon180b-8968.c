//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 1024
#define MAX_PATH 2048
#define MAX_LINE 1024

typedef struct {
    char *file_name;
    FILE *fp;
} file_t;

void read_file(file_t *file, char *buffer, int max_size) {
    int ch;
    int i = 0;

    while ((ch = fgetc(file->fp))!= EOF) {
        if (i >= max_size - 1) {
            break;
        }
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
}

int compare_files(file_t *file1, file_t *file2) {
    char buffer1[MAX_LINE];
    char buffer2[MAX_LINE];
    int result = 0;

    while (1) {
        read_file(file1, buffer1, MAX_LINE);
        read_file(file2, buffer2, MAX_LINE);

        if (strcmp(buffer1, buffer2)!= 0) {
            printf("Files are different\n");
            result = 1;
            break;
        }

        if (feof(file1->fp) && feof(file2->fp)) {
            printf("Files are the same\n");
            result = 0;
            break;
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    file_t file1;
    file_t file2;

    file1.file_name = argv[1];
    file2.file_name = argv[2];

    file1.fp = fopen(file1.file_name, "r");
    if (file1.fp == NULL) {
        printf("Error opening file %s\n", file1.file_name);
        return 1;
    }

    file2.fp = fopen(file2.file_name, "r");
    if (file2.fp == NULL) {
        printf("Error opening file %s\n", file2.file_name);
        return 1;
    }

    int result = compare_files(&file1, &file2);

    fclose(file1.fp);
    fclose(file2.fp);

    return result;
}