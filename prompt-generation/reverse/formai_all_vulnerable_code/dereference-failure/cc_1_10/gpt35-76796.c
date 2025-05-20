//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define VIRUS_SIGNATURE "BADCODE"
#define VIRUS_SIGNATURE_LENGTH 7

void scan_file(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file: %s\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    char* buffer = (char*) malloc(file_size);
    if (!buffer) {
        printf("Could not allocate buffer for file: %s\n", filename);
        fclose(file);
        return;
    }

    fread(buffer, sizeof(char), file_size, file);
    fclose(file);

    for (size_t i = 0; i < file_size - VIRUS_SIGNATURE_LENGTH; i++) {
        if (buffer[i] == 'B' && 
            buffer[i + 1] == 'A' && 
            buffer[i + 2] == 'D' && 
            buffer[i + 3] == 'C' && 
            buffer[i + 4] == 'O' && 
            buffer[i + 5] == 'D' && 
            buffer[i + 6] == 'E') {
            printf("Virus detected in file: %s\n", filename);
            free(buffer);
            return;
        }
    }

    free(buffer);
    printf("No viruses found in file: %s\n", filename);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    scan_file(filename);

    return 0;
}