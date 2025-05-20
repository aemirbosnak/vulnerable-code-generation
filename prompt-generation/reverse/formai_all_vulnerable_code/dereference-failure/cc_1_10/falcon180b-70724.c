//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (100 * 1024 * 1024) // 100MB

typedef struct {
    char *filename;
    unsigned char *data;
    size_t size;
} FileInfo;

void load_file(const char *filename, FileInfo *file_info) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file_info->size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (file_info->size > MAX_FILE_SIZE) {
        printf("Error: File '%s' is too large (%zu bytes)\n", filename, file_info->size);
        fclose(fp);
        exit(1);
    }

    file_info->data = malloc(file_info->size);
    if (file_info->data == NULL) {
        printf("Error: Out of memory\n");
        fclose(fp);
        exit(1);
    }

    size_t bytes_read = fread(file_info->data, 1, file_info->size, fp);
    if (bytes_read!= file_info->size) {
        printf("Error: Could not read entire file '%s'\n", filename);
        free(file_info->data);
        fclose(fp);
        exit(1);
    }

    fclose(fp);
}

int is_virus(const unsigned char *data, size_t size) {
    const unsigned char virus_signature[] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48 };
    const size_t virus_signature_size = sizeof(virus_signature) - 1;

    for (size_t i = 0; i < size - virus_signature_size; i++) {
        if (memcmp(data + i, virus_signature, virus_signature_size) == 0) {
            return 1;
        }
    }

    return 0;
}

void scan_file(const char *filename, FileInfo *file_info) {
    unsigned char *data = file_info->data;
    size_t size = file_info->size;

    if (is_virus(data, size)) {
        printf("Virus found in file '%s'\n", filename);
    } else {
        printf("No virus found in file '%s'\n", filename);
    }

    free(data);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FileInfo file_info;

    load_file(filename, &file_info);
    scan_file(filename, &file_info);

    return 0;
}