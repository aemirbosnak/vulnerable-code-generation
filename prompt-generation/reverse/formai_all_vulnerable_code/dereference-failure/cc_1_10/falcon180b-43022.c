//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define VIRUS_SIGNATURE "VIRUS"

// function to read file into memory
char* read_file(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error: could not allocate memory for file %s\n", filename);
        exit(1);
    }

    fread(buffer, file_size, 1, file);
    fclose(file);

    buffer[file_size] = '\0';
    return buffer;
}

// function to scan for virus signature
int scan_for_virus(const char* buffer) {
    char* virus_signature = VIRUS_SIGNATURE;
    int signature_length = strlen(virus_signature);

    for (int i = 0; i <= strlen(buffer) - signature_length; i++) {
        if (strncmp(buffer + i, virus_signature, signature_length) == 0) {
            printf("Virus detected in file %s\n", buffer);
            return 1;
        }
    }

    printf("No virus detected in file %s\n", buffer);
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char* file_buffer = read_file(argv[1]);
    scan_for_virus(file_buffer);

    free(file_buffer);
    return 0;
}