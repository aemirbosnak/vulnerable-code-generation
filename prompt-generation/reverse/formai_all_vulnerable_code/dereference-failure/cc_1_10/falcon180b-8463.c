//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_data[MAX_FILE_SIZE];
    int file_size;
} file_t;

void read_file(file_t *file) {
    FILE *fp = fopen(file->file_name, "rb");
    if (fp == NULL) {
        printf("Error: File %s not found.\n", file->file_name);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    file->file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fread(file->file_data, 1, file->file_size, fp);
    fclose(fp);
}

void write_file(file_t *file) {
    FILE *fp = fopen(file->file_name, "wb");
    if (fp == NULL) {
        printf("Error: File %s not found.\n", file->file_name);
        exit(1);
    }
    fwrite(file->file_data, 1, file->file_size, fp);
    fclose(fp);
}

int compare_files(file_t *file1, file_t *file2) {
    if (file1->file_size!= file2->file_size) {
        return 0;
    }
    int result = memcmp(file1->file_data, file2->file_data, file1->file_size);
    if (result == 0) {
        return 1;
    }
    return 0;
}

void synchronize_files(file_t *file1, file_t *file2) {
    if (compare_files(file1, file2)) {
        printf("Files are synchronized.\n");
    } else {
        printf("Files are not synchronized.\n");
        if (file1->file_size > file2->file_size) {
            write_file(file2);
        } else if (file2->file_size > file1->file_size) {
            write_file(file1);
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }
    file_t file1, file2;
    strcpy(file1.file_name, argv[1]);
    strcpy(file2.file_name, argv[2]);
    read_file(&file1);
    read_file(&file2);
    synchronize_files(&file1, &file2);
    return 0;
}