//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 * 1024 // 1MB buffer size

typedef struct {
    char* filename;
    FILE* file;
    char* buffer;
    size_t size;
} FileData;

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }

    FileData data = {
       .filename = filename,
       .file = file,
       .buffer = malloc(BUFFER_SIZE),
       .size = 0
    };

    while (!feof(file)) {
        size_t bytes_read = fread(data.buffer + data.size, 1, BUFFER_SIZE - data.size, file);
        if (bytes_read == 0) {
            break;
        }
        data.size += bytes_read;
    }

    fclose(file);

    if (data.size == 0) {
        printf("Error: file '%s' is empty\n", filename);
        free(data.buffer);
        return 1;
    }

    printf("File '%s' has been recovered with size %zu bytes\n", filename, data.size);

    FILE* output_file = fopen(filename, "wb");
    if (!output_file) {
        printf("Error: could not create output file '%s'\n", filename);
        free(data.buffer);
        return 1;
    }

    size_t bytes_written = fwrite(data.buffer, 1, data.size, output_file);
    if (bytes_written!= data.size) {
        printf("Error: could not write all data to file '%s'\n", filename);
        free(data.buffer);
        fclose(output_file);
        remove(filename);
        return 1;
    }

    fclose(output_file);
    free(data.buffer);

    printf("File '%s' has been successfully recovered\n", filename);

    return 0;
}