//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX_PATH 1024

void print_color(const char* message, const char* color) {
    printf("%s%s\033[0m\n", color, message);
}

void sync_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        print_color("Error: Source file could not be opened!", "\033[31m"); // Red text
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (dest == NULL) {
        fclose(src);
        print_color("Error: Destination file could not be opened!", "\033[31m"); // Red text
        return;
    }

    char buffer[8192];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) != 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    print_color("✅ File synchronized successfully!", "\033[32m"); // Green text
}

int is_file_modified(const char *source, const char *destination) {
    struct stat source_stat, dest_stat;

    if (stat(source, &source_stat) != 0) {
        print_color("Error: Unable to get stats for source file!", "\033[31m");
        return 0;
    }

    if (stat(destination, &dest_stat) != 0) {
        return 1; // Destination doesn't exist, thus modified
    }

    return source_stat.st_mtime > dest_stat.st_mtime; // Return true if source is modified
}

void sync_directory(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    if (!dir) {
        print_color("Error: Cannot open source directory!", "\033[31m");
        return;
    }

    struct dirent *entry;
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Ignore . and ..
        }

        char source_path[MAX_PATH];
        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        
        char dest_path[MAX_PATH];
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            mkdir(dest_path, 0755); // Create destination directory if it's a directory
            sync_directory(source_path, dest_path); // Recursively sync subdirectory
        } else if (entry->d_type == DT_REG) {
            if (is_file_modified(source_path, dest_path)) {
                sync_file(source_path, dest_path); // Sync file if it's modified
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_color("Usage: syncdir <source_directory> <destination_directory>", "\033[33m"); // Yellow text
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    print_color("🌟 Starting file synchronization... 🌟", "\033[34m"); // Blue text

    struct stat st = {0};
    if (stat(destination_directory, &st) == -1) {
        mkdir(destination_directory, 0700); // Create destination directory if it doesn't exist
    }

    sync_directory(source_directory, destination_directory);

    print_color("🎉 File synchronization complete! 🎉", "\033[35m"); // Magenta text
    return EXIT_SUCCESS;
}