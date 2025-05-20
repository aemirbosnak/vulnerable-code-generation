//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFF_SIZE 1024

void print_happy_message() {
    printf("🎉 File Synchronizer is up and running! 🎉\n");
    printf("Let's sync your files from source to destination! 🚀\n");
}

int is_file_modified(const char *source_path, const char *dest_path) {
    struct stat src_stat, dest_stat;
    
    if (stat(source_path, &src_stat) < 0) {
        perror("Error accessing source file");
        return 0;
    }

    if (stat(dest_path, &dest_stat) < 0) {
        return 1; // Dest file doesn't exist, consider it modified
    }

    return src_stat.st_mtime > dest_stat.st_mtime; // Check if source is newer
}

void sync_file(const char *source_path, const char *dest_path) {
    FILE *source_file = fopen(source_path, "rb");
    FILE *dest_file = fopen(dest_path, "wb");
    
    if (source_file == NULL || dest_file == NULL) {
        perror("Error opening files");
        return;
    }

    char buffer[BUFF_SIZE];
    
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);

    printf("🌟 Updated: %s -> %s\n", source_path, dest_path);
}

void sync_directory(const char *source_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *source = opendir(source_dir);
    
    if (source == NULL) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(source)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files
        }

        char source_path[MAX_PATH];
        char dest_path[MAX_PATH];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // It's a directory
            mkdir(dest_path, 0755);
            sync_directory(source_path, dest_path); // Recursive call
        } else {
            // It's a file
            if (is_file_modified(source_path, dest_path)) {
                sync_file(source_path, dest_path);
            }
        }
    }

    closedir(source);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }

    print_happy_message();

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    // Create destination directory if it doesn't exist
    mkdir(dest_dir, 0755);

    sync_directory(source_dir, dest_dir);

    printf("🎊 All files synchronized successfully! 🎊\n");
    return 0;
}