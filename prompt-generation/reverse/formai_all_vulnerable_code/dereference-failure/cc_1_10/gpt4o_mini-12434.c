//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BACKUP_SUFFIX ".bak"

void recover_file(const char *path, const char *filename) {
    char source[MAX_PATH];
    char destination[MAX_PATH];

    snprintf(source, sizeof(source), "%s/%s", path, filename);
    snprintf(destination, sizeof(destination), "%s/%s%s", path, filename, BACKUP_SUFFIX);

    // Attempt to recover by creating a copy with a new name
    FILE *src = fopen(source, "rb");
    if (src) {
        FILE *dst = fopen(destination, "wb");
        if (dst) {
            char buffer[1024];
            size_t bytes;
            while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
                fwrite(buffer, 1, bytes, dst);
            }
            fclose(dst);
            printf("Recovered: %s -> %s\n", source, destination);
        } else {
            printf("Error creating backup: %s\n", destination);
        }
        fclose(src);
    } else {
        printf("File not found: %s\n", source);
    }
}

void scan_directory(const char *directory) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(directory)) == NULL) {
        fprintf(stderr, "Cannot open directory: %s\n", directory);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

        // If it is a directory, recurse into it
        if (entry->d_type == DT_DIR) {
            scan_directory(path);
        } else if (entry->d_type == DT_REG) {
            // Attempt to recover the regular file
            recover_file(directory, entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory = argv[1];
    scan_directory(directory);

    return EXIT_SUCCESS;
}