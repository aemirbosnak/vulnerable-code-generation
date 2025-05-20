//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1048576 // 1MB

void scan_file(const char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", file_path);
        return;
    }

    char buffer[MAX_FILE_SIZE];
    size_t num_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file);
    if (num_read == 0) {
        fclose(file);
        return;
    }

    if (strstr(buffer, "virus") != NULL) {
        printf("Virus found in file: %s\n", file_path);
    }

    fclose(file);
}

void scan_directory(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Could not open directory: %s\n", path);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 &&
                strcmp(entry->d_name, "..") != 0) {
                char subdirectory[1024];
                snprintf(subdirectory, sizeof(subdirectory),
                         "%s/%s", path, entry->d_name);
                scan_directory(subdirectory);
            }
        } else {
            char filepath[1024];
            snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);
            scan_file(filepath);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory to scan>\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1]);

    return 0;
}