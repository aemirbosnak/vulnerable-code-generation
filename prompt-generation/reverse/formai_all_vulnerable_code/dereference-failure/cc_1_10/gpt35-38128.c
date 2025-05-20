//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define VIRUS_SIGNATURE "this is a virus"

void scan_file(char* filename);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* directory_name = argv[1];

    DIR* directory = opendir(directory_name);

    if (!directory) {
        perror(directory_name);
        exit(EXIT_FAILURE);
    }

    struct dirent* entry;

    while ((entry = readdir(directory))) {
        if (entry->d_type == DT_REG) {
            char* filename = entry->d_name;

            if (strstr(filename, ".cav")) {
                scan_file(filename);
            }
        }
    }

    closedir(directory);

    printf("Scan complete!\n");

    return 0;
}

void scan_file(char* filename) {
    printf("Scanning %s...\n", filename);

    FILE* file = fopen(filename, "rb");

    if (!file) {
        perror(filename);
        return;
    }

    fseek(file, 0L, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(sizeof(char) * file_size);

    if (!buffer) {
        fprintf(stderr, "Error: Unable to allocate memory for file.\n");
        exit(EXIT_FAILURE);
    }

    fread(buffer, 1, file_size, file);

    if (strstr(buffer, VIRUS_SIGNATURE)) {
        printf("WARNING: %s is infected with a virus!\n", filename);
    }

    free(buffer);
    fclose(file);
}