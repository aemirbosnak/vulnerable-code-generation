//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1 MB
#define MAX_VIRUS_SIZE 1024 // 1 KB

// Function to read a file into memory
void read_file(const char *filename, char **buffer) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File is too large (%ld bytes)\n", file_size);
        exit(1);
    }

    rewind(fp);
    *buffer = malloc(file_size + 1);
    if (!*buffer) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    fread(*buffer, file_size, 1, fp);
    fclose(fp);

    (*buffer)[file_size] = '\0';
}

// Function to scan for viruses in memory
int scan_memory(const char *filename, const char *virus_name) {
    char *file_buffer = NULL;
    read_file(filename, &file_buffer);

    char *virus_buffer = strdup(virus_name);
    tolower(virus_buffer);

    char *ptr = file_buffer;
    while ((ptr = strstr(ptr, virus_buffer))) {
        printf("Virus found in %s at offset %ld\n", filename, ptr - file_buffer);
        return 1;
    }

    free(file_buffer);
    free(virus_buffer);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <virus_name>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *virus_name = argv[2];

    int result = scan_memory(filename, virus_name);
    if (result == 0) {
        printf("No viruses found in %s\n", filename);
    }

    return 0;
}