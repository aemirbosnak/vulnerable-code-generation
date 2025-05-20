//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void synchronize(const char* src, const char* dest);
void copy_file(const char* src_file, const char* dest_file);
void check_and_sync(const char* src, const char* dest);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    synchronize(argv[1], argv[2]);

    printf("Synchronization complete. Have a peaceful day!\n");
    return 0;
}

void synchronize(const char* src, const char* dest) {
    DIR* dir = opendir(src);
    if (!dir) {
        perror("Open source directory failed");
        exit(EXIT_FAILURE);
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[BUFFER_SIZE];
        char dest_path[BUFFER_SIZE];

        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        struct stat stat_src;
        if (stat(src_path, &stat_src) == 0) {
            // If it's a regular file, check if we need to copy it
            if (S_ISREG(stat_src.st_mode)) {
                check_and_sync(src_path, dest_path);
            }
            // If it's a directory, create the directory in destination
            else if (S_ISDIR(stat_src.st_mode)) {
                mkdir(dest_path, 0755);
                synchronize(src_path, dest_path);
            }
        }
    }
    closedir(dir);
}

void check_and_sync(const char* src_file, const char* dest_file) {
    struct stat stat_src, stat_dest;

    // Check if the destination file exists
    if (stat(dest_file, &stat_dest) != 0) {
        printf("Copying file: %s to %s\n", src_file, dest_file);
        copy_file(src_file, dest_file);
        return;
    }

    // Check modification time and size to decide if we need to copy
    if (stat(src_file, &stat_src) == 0) {
        if (difftime(stat_src.st_mtime, stat_dest.st_mtime) > 0 || 
            stat_src.st_size != stat_dest.st_size) {
            printf("Updating file: %s to %s\n", src_file, dest_file);
            copy_file(src_file, dest_file);
        }
    }
}

void copy_file(const char* src_file, const char* dest_file) {
    FILE* src = fopen(src_file, "rb");
    if (!src) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    FILE* dest = fopen(dest_file, "wb");
    if (!dest) {
        fclose(src);
        perror("Error opening destination file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}