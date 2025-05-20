//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan_file(char *filename);
void scan_memory(char *buffer);
int get_file_size(char *filename);

int main(int argc, char *argv[]) {

    char *filename = argv[1];
    char *buffer;

    if (argc != 2) {
        printf("Usage: %s [file]\n", argv[0]);
        exit(1);
    }

    printf("Scanning file '%s'...\n", filename);

    scan_file(filename);

    printf("Done.\n");

    printf("Scanning memory...\n");

    buffer = malloc(1024 * sizeof(char));

    strcpy(buffer, "This is not a virus!");
    scan_memory(buffer);

    free(buffer);

    printf("Done.\n");

    return 0;
}


void scan_file(char *filename) {

    int i, file_size;
    char buffer[1024];
    FILE *file_ptr;

    file_size = get_file_size(filename);

    if (file_size == -1) {
        printf("Failed to open file '%s'.\n", filename);
        exit(1);
    }

    file_ptr = fopen(filename, "r");

    if (file_ptr == NULL) {
        printf("Failed to open file '%s'.\n", filename);
        exit(1);
    }

    for (i = 0; i < file_size; i += sizeof(buffer)) {

        fread(buffer, sizeof(buffer), 1, file_ptr);

        scan_memory(buffer);
    }

    fclose(file_ptr);
}


void scan_memory(char *buffer) {

    int i, j, buffer_size;
    char pattern[] = "virus";
    
    buffer_size = strlen(buffer);

    for (i = 0; i < buffer_size; i++) {

        for (j = 0; j < 5; j++) {
            if (buffer[i+j] != pattern[j]) {
                break;
            }
        }

        if (j == 5) {
            printf("Warning: Found virus in memory!\n");
            return;
        }
    }

    printf("Memory is clean.\n");
}


int get_file_size(char *filename) {

    FILE *file_ptr;
    int file_size;

    file_ptr = fopen(filename, "r");

    if (file_ptr == NULL) {
        return -1;
    }

    fseek(file_ptr, 0, SEEK_END);

    file_size = ftell(file_ptr);

    rewind(file_ptr);

    fclose(file_ptr);

    return file_size;
}