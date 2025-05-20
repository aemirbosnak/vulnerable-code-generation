//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void print_happy_message(const char *message) {
    printf("\n😊 %s 😊\n", message);
}

int is_file_updated(const char *src_path, const char *dst_path) {
    struct stat src_stat, dst_stat;

    if (stat(src_path, &src_stat) == -1) {
        perror("Failed to get source file stats");
        return 0;
    }

    if (stat(dst_path, &dst_stat) == -1) {
        return 1; // Destination doesn't exist, so it's updated by default
    }

    return difftime(src_stat.st_mtime, dst_stat.st_mtime) > 0;
}

void sync_file(const char *src_path, const char *dst_path) {
    FILE *src_file = fopen(src_path, "rb");
    FILE *dst_file = fopen(dst_path, "wb");

    if (src_file == NULL || dst_file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);
    print_happy_message("File synchronized!");
}

void sync_directory(const char *src_dir, const char *dst_dir) {
    DIR *dir = opendir(src_dir);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Could not open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files
        }

        char src_path[MAX_PATH];
        char dst_path[MAX_PATH];

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        struct stat entry_stat;
        if (stat(src_path, &entry_stat) == 0) {
            if (S_ISREG(entry_stat.st_mode)) {
                if (is_file_updated(src_path, dst_path)) {
                    sync_file(src_path, dst_path);
                }
            }
        }
    }

    closedir(dir);
    print_happy_message("Directory synchronization complete!");
}

int main() {
    char src_directory[MAX_PATH];
    char dst_directory[MAX_PATH];

    printf("Welcome to the Happy File Synchronizer! 😃\n");
    printf("Enter source directory path: ");
    fgets(src_directory, sizeof(src_directory), stdin);
    src_directory[strcspn(src_directory, "\n")] = 0; // Remove newline

    printf("Enter destination directory path: ");
    fgets(dst_directory, sizeof(dst_directory), stdin);
    dst_directory[strcspn(dst_directory, "\n")] = 0; // Remove newline

    print_happy_message("Starting synchronization...");
    sync_directory(src_directory, dst_directory);
    print_happy_message("All files are synchronized! 🎉");

    return 0;
}