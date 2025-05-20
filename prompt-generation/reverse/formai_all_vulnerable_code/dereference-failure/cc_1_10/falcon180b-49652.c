//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    char file_data[MAX_FILE_SIZE];
} File;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    File file;
    strcpy(file.file_name, argv[1]);
    file.file_size = 0;

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    file.file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    if (file.file_size == 0) {
        printf("Error: file %s is empty\n", argv[1]);
        fclose(fp);
        return 1;
    }

    if (file.file_size > MAX_FILE_SIZE) {
        printf("Error: file %s is too large\n", argv[1]);
        fclose(fp);
        return 1;
    }

    fread(file.file_data, 1, file.file_size, fp);
    fclose(fp);

    printf("File %s has been recovered.\n", file.file_name);
    printf("File size: %d bytes\n", file.file_size);

    return 0;
}