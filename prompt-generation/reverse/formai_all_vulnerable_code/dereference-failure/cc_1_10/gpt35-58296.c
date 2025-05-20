//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define MAX_VIRUS_SIGNATURES 10000

typedef struct {
    char* signature;
    int length;
} virus_signature;

char* read_file(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file %s!\n", filename);
        exit(1);
    }

    char* buffer = (char*) malloc(MAX_FILE_SIZE);
    if (!buffer) {
        printf("Error: Could not allocate memory for file data!\n");
        exit(1);
    }

    int bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file);
    if (bytes_read < 0) {
        printf("Error: Could not read file %s!\n", filename);
        exit(1);
    }

    buffer[bytes_read] = '\0';
    fclose(file);

    return buffer;
}

void read_signatures(virus_signature* signatures, int* count) {
    FILE* file = fopen("virus_signatures.txt", "r");
    if (!file) {
        printf("Error: Could not open virus signatures file!\n");
        exit(1);
    }

    char* line = NULL;
    size_t line_size = 0;

    while (getline(&line, &line_size, file) != -1) {
        if (*count >= MAX_VIRUS_SIGNATURES) {
            printf("Warning: Maximum virus signature limit reached!\n");
            break;
        }

        virus_signature* signature = &signatures[*count];
        signature->length = strlen(line) - 1;

        signature->signature = (char*) malloc(signature->length + 1);
        if (!signature->signature) {
            printf("Error: Could not allocate memory for signature data!\n");
            exit(1);
        }

        strncpy(signature->signature, line, signature->length);
        signature->signature[signature->length] = '\0';

        (*count)++;
    }

    fclose(file);
    if (line) {
        free(line);
    }
}

void scan_file(char* filename, virus_signature* signatures, int count) {
    char* data = read_file(filename);
    int data_len = strlen(data);

    for (int i = 0; i < count; i++) {
        virus_signature* signature = &signatures[i];
        int signature_len = signature->length;

        for (int j = 0; j <= (data_len - signature_len); j++) {
            if (strncmp(&data[j], signature->signature, signature_len) == 0) {
                printf("Virus detected in file %s at offset %d!\n", filename, j);
                break;
            }
        }
    }

    free(data);
}

int main() {
    virus_signature signatures[MAX_VIRUS_SIGNATURES];
    int signature_count = 0;

    read_signatures(signatures, &signature_count);

    printf("Loaded %d virus signatures.\n", signature_count);

    scan_file("file1.txt", signatures, signature_count);
    scan_file("file2.txt", signatures, signature_count);
    scan_file("file3.txt", signatures, signature_count);

    return 0;
}