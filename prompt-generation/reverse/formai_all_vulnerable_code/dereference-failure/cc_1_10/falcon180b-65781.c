//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // maximum file size to recover
#define BUFFER_SIZE 4096 // buffer size for reading and writing

struct file_header {
    char magic[4]; // file signature
    int version; // version number
    int file_size; // file size in bytes
};

struct file_header read_header(FILE* file) {
    struct file_header header;
    fread(&header, sizeof(struct file_header), 1, file);
    return header;
}

int write_header(FILE* file, struct file_header header) {
    fwrite(&header, sizeof(struct file_header), 1, file);
    return 0;
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: could not open file.\n");
        return 1;
    }

    struct file_header header = read_header(file);
    if (strcmp(header.magic, "DATA")!= 0) {
        printf("Error: invalid file signature.\n");
        fclose(file);
        return 1;
    }

    int file_size = header.file_size;
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: file size exceeds maximum limit.\n");
        fclose(file);
        return 1;
    }

    char* buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        printf("Error: could not allocate memory.\n");
        fclose(file);
        return 1;
    }

    FILE* output_file = fopen("recovered.dat", "wb");
    if (!output_file) {
        printf("Error: could not create output file.\n");
        free(buffer);
        fclose(file);
        return 1;
    }

    int bytes_read = 0;
    while (bytes_read < file_size) {
        int bytes_to_read = BUFFER_SIZE;
        if (bytes_to_read > file_size - bytes_read) {
            bytes_to_read = file_size - bytes_read;
        }

        int bytes_written = fwrite(buffer, 1, bytes_to_read, output_file);
        if (bytes_written!= bytes_to_read) {
            printf("Error: could not write to output file.\n");
            free(buffer);
            fclose(file);
            fclose(output_file);
            remove("recovered.dat");
            return 1;
        }

        bytes_read += bytes_to_read;
    }

    fclose(file);
    fclose(output_file);

    printf("File recovery successful!\n");

    return 0;
}