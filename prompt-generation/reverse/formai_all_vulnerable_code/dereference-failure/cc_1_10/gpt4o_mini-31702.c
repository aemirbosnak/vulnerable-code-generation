//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void sync_files(const char *source, const char *destination);
int is_file_modified(const char *src_file, const char *dest_file);
void copy_file(const char *src_file, const char *dest_file);
void print_help();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_help();
        return 1;
    }

    const char *source_dir = argv[1];
    const char *destination_dir = argv[2];

    sync_files(source_dir, destination_dir);

    printf("Synchronization complete!\n");
    return 0;
}

void sync_files(const char *source, const char *destination) {
    DIR *dir = opendir(source);
    if (!dir) {
        perror("Could not open source directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and directories
        }

        char src_path[1024], dest_path[1024];
        snprintf(src_path, sizeof(src_path), "%s/%s", source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", destination, entry->d_name);

        struct stat stat_buffer;
        if (stat(src_path, &stat_buffer) == 0) {
            if (S_ISDIR(stat_buffer.st_mode)) {
                // It's a directory, go down that rabbit hole!
                mkdir(dest_path, 0755); // Create destination directory
                sync_files(src_path, dest_path);
            } else {
                // It's a file, let's check if we need to copy it
                if (is_file_modified(src_path, dest_path)) {
                    copy_file(src_path, dest_path);
                }
            }
        } else {
            perror("Could not stat file");
        }
    }

    closedir(dir);
}

int is_file_modified(const char *src_file, const char *dest_file) {
    struct stat src_stat, dest_stat;
    if (stat(src_file, &src_stat) == -1) {
        perror("Could not stat source file");
        return 0;
    }
    
    if (stat(dest_file, &dest_stat) == -1) {
        // If the destination file doesn't exist, it is considered modified
        return 1;
    }

    return src_stat.st_mtime > dest_stat.st_mtime;
}

void copy_file(const char *src_file, const char *dest_file) {
    FILE *src = fopen(src_file, "rb");
    if (src == NULL) {
        perror("Could not open source file for reading");
        return;
    }

    FILE *dest = fopen(dest_file, "wb");
    if (dest == NULL) {
        perror("Could not open destination file for writing");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    printf("Copied %s to %s\n", src_file, dest_file);
}

void print_help() {
    printf("Usage: file_sync <source_directory> <destination_directory>\n");
    printf("Synchronizes the contents of source_directory to destination_directory!\n");
}