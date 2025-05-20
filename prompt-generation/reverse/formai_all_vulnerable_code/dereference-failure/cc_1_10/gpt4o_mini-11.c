//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void copy_file(const char *src, const char *dest) {
    FILE *source, *destination;
    char buffer[1024];
    size_t bytes;

    source = fopen(src, "rb");
    if (!source) {
        perror("Source file open error");
        return;
    }

    destination = fopen(dest, "wb");
    if (!destination) {
        perror("Destination file open error");
        fclose(source);
        return;
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

void synchronize(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    struct stat src_stat, dest_stat;
    char src_path[MAX_PATH], dest_path[MAX_PATH];

    DIR *src = opendir(src_dir);
    if (!src) {
        perror("Source directory open error");
        return;
    }

    while ((entry = readdir(src)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (stat(src_path, &src_stat) == -1) {
            perror("Source file stat error");
            continue;
        }

        if (S_ISDIR(src_stat.st_mode)) {
            mkdir(dest_path, 0755); // Create destination directory if it doesn't exist
            synchronize(src_path, dest_path);
        } else {
            // Check if the file exists in the destination
            if (stat(dest_path, &dest_stat) == -1) { 
                // File does not exist in destination, copy it
                printf("Copying new file: %s to %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            } else {
                // File exists, compare timestamps and sizes
                if (src_stat.st_mtime > dest_stat.st_mtime || 
                    src_stat.st_size != dest_stat.st_size) {
                    printf("Updating file: %s to %s\n", src_path, dest_path);
                    copy_file(src_path, dest_path);
                }
            }
        }
    }
    closedir(src);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    // Create destination directory if it doesn't exist
    mkdir(dest_dir, 0755); 

    synchronize(src_dir, dest_dir);

    printf("File synchronization completed.\n");
    return EXIT_SUCCESS;
}