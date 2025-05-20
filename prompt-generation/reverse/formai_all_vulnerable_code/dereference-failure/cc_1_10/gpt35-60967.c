//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "VIRUSWORM"
#define BUFFER_SIZE 1024

void scan_file(char* filename);
void scan_buffer(char* buffer);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: antivirus <file>\n");
        return 1;
    }

    char* filename = argv[1];
    scan_file(filename);

    printf("File scan complete!\n");
    return 0;
}

void scan_file(char* filename) {
    FILE* file;
    char buffer[BUFFER_SIZE];

    if ((file = fopen(filename, "rb")) == NULL) {
        printf("Could not open file: %s\n", filename);
        return;
    }

    int bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        scan_buffer(buffer);
    }

    fclose(file);
}

void scan_buffer(char* buffer) {
    char* signature = VIRUS_SIGNATURE;
    int signatureLength = strlen(signature);

    for (int i = 0; i < BUFFER_SIZE - signatureLength; i++) {
        if (memcmp(&buffer[i], signature, signatureLength) == 0) {
            printf("Virus detected!\n");
            exit(1);
        }
    }
}