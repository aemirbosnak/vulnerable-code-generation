//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1MB
#define MAX_FILE_NAME 1000 // 1KB
#define MAX_BLOCK_SIZE 4096 // 4KB

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    char data[MAX_FILE_SIZE];
} FILE_INFO;

FILE_INFO* read_file(FILE* fp) {
    FILE_INFO* file_info = (FILE_INFO*)malloc(sizeof(FILE_INFO));
    if (file_info == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    memset(file_info, 0, sizeof(FILE_INFO));

    fseek(fp, 0, SEEK_SET);
    fread(&file_info->size, sizeof(int), 1, fp);
    fread(file_info->data, sizeof(char), file_info->size, fp);

    fseek(fp, 0, SEEK_SET);
    fread(file_info->name, sizeof(char), MAX_FILE_NAME, fp);

    return file_info;
}

void write_file(FILE* fp, FILE_INFO* file_info) {
    fseek(fp, 0, SEEK_SET);
    fwrite(&file_info->size, sizeof(int), 1, fp);
    fwrite(file_info->data, sizeof(char), file_info->size, fp);

    fseek(fp, 0, SEEK_SET);
    fwrite(file_info->name, sizeof(char), MAX_FILE_NAME, fp);
}

FILE_INFO* recover_file(FILE* fp, int block_size) {
    FILE_INFO* file_info = NULL;
    char buffer[MAX_BLOCK_SIZE];
    int offset = 0;
    int i;

    while (fread(buffer, sizeof(char), block_size, fp)!= 0) {
        for (i = 0; i < block_size; i++) {
            if (buffer[i] == 0x00) {
                if (file_info!= NULL) {
                    write_file(fp, file_info);
                    file_info = NULL;
                    offset = 0;
                }
            } else {
                if (file_info == NULL) {
                    file_info = (FILE_INFO*)malloc(sizeof(FILE_INFO));
                    if (file_info == NULL) {
                        printf("Error: Memory allocation failed!\n");
                        exit(1);
                    }
                    memset(file_info, 0, sizeof(FILE_INFO));
                }
                file_info->data[offset++] = buffer[i];
            }
        }
    }

    if (file_info!= NULL) {
        write_file(fp, file_info);
    }

    return file_info;
}

int main() {
    FILE* fp = fopen("test.dat", "rb+");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    int block_size = MAX_BLOCK_SIZE;
    FILE_INFO* file_info = recover_file(fp, block_size);

    printf("Recovered file name: %s\n", file_info->name);
    printf("Recovered file size: %d bytes\n", file_info->size);

    fclose(fp);
    free(file_info);

    return 0;
}