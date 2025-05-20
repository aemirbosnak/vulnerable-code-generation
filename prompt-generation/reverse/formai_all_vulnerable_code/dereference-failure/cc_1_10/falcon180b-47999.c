//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} File;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];
    File file = {0};

    FILE *fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("Error opening file '%s'\n", file_path);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size_t file_size = ftell(fp);
    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large (%zu bytes)\n", file_size);
        fclose(fp);
        return 1;
    }

    rewind(fp);
    file.data = malloc(file_size);
    if (file.data == NULL) {
        printf("Memory allocation failed\n");
        fclose(fp);
        return 1;
    }

    file.size = fread(file.data, 1, file_size, fp);
    if (ferror(fp)) {
        printf("Error reading file '%s'\n", file_path);
        free(file.data);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    char *signature = "CAFEBABE"; // Java class file signature
    int signature_size = strlen(signature);

    int i;
    for (i = 0; i < file.size - signature_size; i++) {
        if (memcmp(file.data + i, signature, signature_size) == 0) {
            printf("File '%s' contains a Java class file\n", file_path);
            break;
        }
    }

    if (i == file.size - signature_size) {
        printf("File '%s' does not contain a Java class file\n", file_path);
    }

    free(file.data);
    return 0;
}