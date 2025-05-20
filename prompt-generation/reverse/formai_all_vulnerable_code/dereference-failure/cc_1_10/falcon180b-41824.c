//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 1024) // 1GB
#define BLOCK_SIZE 4096

typedef struct {
    char *filename;
    size_t filesize;
    FILE *file;
    unsigned char *buffer;
} FileInfo;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FileInfo fileinfo = { 0 };

    fileinfo.filename = filename;
    fileinfo.file = fopen(filename, "rb");

    if (fileinfo.file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    fseek(fileinfo.file, 0, SEEK_END);
    fileinfo.filesize = ftell(fileinfo.file);
    rewind(fileinfo.file);

    if (fileinfo.filesize == 0) {
        printf("File is empty.\n");
        return 1;
    }

    if (fileinfo.filesize > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        return 1;
    }

    fileinfo.buffer = (unsigned char *) malloc(BLOCK_SIZE);

    unsigned char *data = (unsigned char *) malloc(fileinfo.filesize);
    unsigned char *ptr = data;

    while ((size_t) fread(fileinfo.buffer, 1, BLOCK_SIZE, fileinfo.file) > 0) {
        memcpy(ptr, fileinfo.buffer, BLOCK_SIZE);
        ptr += BLOCK_SIZE;
    }

    fclose(fileinfo.file);
    free(fileinfo.buffer);

    printf("File recovery successful!\n");
    printf("Recovered data:\n");

    for (int i = 0; i < fileinfo.filesize; i++) {
        printf("%02X ", data[i]);
    }

    free(data);
    return 0;
}