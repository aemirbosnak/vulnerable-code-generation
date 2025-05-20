//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1MB
#define BUF_SIZE 4096

bool is_file(const char *path) {
    FILE *fp = fopen(path, "rb");
    if (fp == NULL)
        return false;
    fclose(fp);
    return true;
}

void die(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void read_file(const char *path, unsigned char *buf, size_t size) {
    FILE *fp = fopen(path, "rb");
    size_t bytes_read = 0;

    if (fp == NULL)
        die("Cannot open file.\n");

    while (bytes_read < size) {
        size_t bytes_to_read = size - bytes_read;
        if (fread(buf + bytes_read, 1, bytes_to_read, fp) != bytes_to_read) {
            if (feof(fp)) {
                // Reach end of file
            } else {
                // Error occurred
                die("Error reading file.\n");
            }
            break;
        }

        bytes_read += bytes_to_read;
    }

    fclose(fp);
}

size_t checksum(const unsigned char *buf, size_t size) {
    unsigned char sum = 0;

    for (size_t i = 0; i < size; i++) {
        sum += buf[i];
    }

    return sum;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    const char *file_path = argv[1];

    if (!is_file(file_path)) {
        fprintf(stderr, "File not found.\n");
        exit(1);
    }

    unsigned char buf[BUF_SIZE];
    size_t file_size = 0;

    read_file(file_path, buf, MAX_FILE_SIZE);
    file_size = ftell(stdin);
    rewind(stdin); // Reset the input stream

    size_t checksum_value = checksum(buf, file_size);

    printf("File size: %ld bytes\n", file_size);
    printf("Checksum: %02x%02x\n", (int) (checksum_value >> 8), (int) (checksum_value & 0xff));

    return 0;
}