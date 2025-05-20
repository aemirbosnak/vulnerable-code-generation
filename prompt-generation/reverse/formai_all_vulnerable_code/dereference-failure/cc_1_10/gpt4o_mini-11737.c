//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

void copy_file(const char* src, const char* dest) {
    FILE *sourceFile, *destFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    sourceFile = fopen(src, "rb");
    if (sourceFile == NULL) {
        perror("Failed to open source file");
        return;
    }

    destFile = fopen(dest, "wb");
    if (destFile == NULL) {
        perror("Failed to open destination file");
        fclose(sourceFile);
        return;
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
}

void synchronize_directories(const char* src_dir, const char* dest_dir) {
    DIR *dir;
    struct dirent *entry;
    char src_path[MAX_PATH], dest_path[MAX_PATH];
    struct stat src_stat, dest_stat;

    dir = opendir(src_dir);
    if (dir == NULL) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (stat(src_path, &src_stat) == 0) {
            if (stat(dest_path, &dest_stat) != 0 || src_stat.st_mtime > dest_stat.st_mtime) {
                printf("Copying new/updated file: %s to %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    synchronize_directories(source_directory, destination_directory);

    return 0;
}