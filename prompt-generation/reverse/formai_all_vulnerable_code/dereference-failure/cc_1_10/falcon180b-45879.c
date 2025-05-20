//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10 MB

typedef struct {
    char *name;
    unsigned int size;
    unsigned char *data;
} file_t;

void read_file(const char *filename, file_t *file) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);

    if (file->size > MAX_FILE_SIZE) {
        printf("Error: file '%s' is too large (%d bytes)\n", filename, file->size);
        fclose(fp);
        exit(1);
    }

    file->data = malloc(file->size);
    if (file->data == NULL) {
        printf("Error: could not allocate memory for file '%s'\n", filename);
        fclose(fp);
        exit(1);
    }

    if (fread(file->data, 1, file->size, fp)!= file->size) {
        printf("Error: could not read file '%s'\n", filename);
        free(file->data);
        fclose(fp);
        exit(1);
    }

    fclose(fp);
}

void scan_file(const char *filename, const unsigned char *virus_signature, size_t signature_size) {
    file_t file;
    read_file(filename, &file);

    size_t i, j;
    for (i = 0; i < file.size - signature_size; i++) {
        for (j = 0; j < signature_size; j++) {
            if (file.data[i+j]!= virus_signature[j]) {
                break;
            }
        }
        if (j == signature_size) {
            printf("Virus detected in file '%s'\n", filename);
            exit(1);
        }
    }

    printf("File '%s' is clean\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <virus_signature>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const unsigned char *virus_signature = argv[2];
    size_t signature_size = strlen((char *)virus_signature);

    scan_file(filename, virus_signature, signature_size);

    return 0;
}