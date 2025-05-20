//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_MAX_SIZE (1024 * 1024) // 1MB

typedef struct {
    char *filename;
    char *data;
    size_t size;
} File;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_to_recover>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open '%s'\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size_t file_size = ftell(fp);
    if (file_size == 0 || file_size > FILE_MAX_SIZE) {
        printf("Error: invalid file size\n");
        fclose(fp);
        return 1;
    }

    rewind(fp);
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        printf("Error: could not allocate memory\n");
        fclose(fp);
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, file_size, fp);
    if (bytes_read!= file_size) {
        printf("Error: could not read file\n");
        free(buffer);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    char *header = strstr(buffer, "DATA");
    if (header == NULL) {
        printf("Error: invalid file format\n");
        free(buffer);
        return 1;
    }

    header += 4; // skip 'DATA' header
    char *data_start = strstr(header, "DATA");
    if (data_start == NULL) {
        printf("Error: invalid file format\n");
        free(buffer);
        return 1;
    }

    data_start += 5; // skip 'DATA' header

    File file = {
       .filename = filename,
       .data = data_start,
       .size = strlen(data_start)
    };

    printf("Successfully recovered data from '%s'\n", filename);
    printf("Data:\n%s\n", file.data);

    free(buffer);
    return 0;
}