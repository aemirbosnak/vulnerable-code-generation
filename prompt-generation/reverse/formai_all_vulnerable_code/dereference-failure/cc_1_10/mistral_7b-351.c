//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024
#define MALWARE_SIGNATURE "MalwareSignature"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    if (fileSize > MAX_FILE_SIZE) {
        printf("File too large to scan\n");
        fclose(file);
        return 1;
    }

    char *buffer = malloc(fileSize);
    size_t readSize;

    while ((readSize = fread(buffer, 1, fileSize, file)) != fileSize) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return 1;
    }

    fclose(file);

    if (strstr(buffer, MALWARE_SIGNATURE) != NULL) {
        printf("Malware detected in file: %s\n", argv[1]);
    } else {
        printf("File: %s is clean\n", argv[1]);
    }

    free(buffer);
    return 0;
}