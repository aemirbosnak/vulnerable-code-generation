//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFSIZE 8192

// Function Prototypes
void sync_directories(const char *src, const char *dst);
int is_file_updated(const char *src_file, const char *dst_file);
void copy_file(const char *src_file, const char *dst_file);
void print_status(const char *message);

int main(int argc, char *argv[]) {
    // A curious condition to kick off our revisiting odyssey!
    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Tossing sense into the chaos of existence
    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    print_status("Starting the synchronization journey...");

    // Behold! We shall synchronize the paths!
    sync_directories(source_dir, dest_dir);

    print_status("Synchronization completed!");
    return EXIT_SUCCESS;
}

void sync_directories(const char *src, const char *dst) {
    struct dirent *entry;
    DIR *src_dir = opendir(src);
    if (!src_dir) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(src_dir)) != NULL) {
        // A whimsical filtering out of the weird stuff
        if (entry->d_name[0] == '.') {
            continue;  // Ignore hidden files and folders!
        }

        char src_path[MAX_PATH];
        char dst_path[MAX_PATH];
        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst, entry->d_name);

        struct stat src_stat;
        if (stat(src_path, &src_stat) == -1) {
            perror("Failed to get source file stats");
            continue;
        }

        // Ah, the moment of truth – will we copy?
        if (S_ISREG(src_stat.st_mode)) {
            if (is_file_updated(src_path, dst_path)) {
                copy_file(src_path, dst_path);
            }
        } else if (S_ISDIR(src_stat.st_mode)) {
            // A brave new world! We must duck into this directory!
            mkdir(dst_path, 0755); // Create it if it doesn't exist
            sync_directories(src_path, dst_path); // Call recursively
        }
    }

    closedir(src_dir);
}

int is_file_updated(const char *src_file, const char *dst_file) {
    struct stat src_stat, dst_stat;
    if (stat(dst_file, &dst_stat) != 0) {
        // The destination file doesn't exist, hence it needs a copy!
        return 1; 
    }
    if (stat(src_file, &src_stat) == 0) {
        return src_stat.st_mtime > dst_stat.st_mtime; // Compare modification times
    }
    return 0; // The source file doesn't exist anyway, don't bother
}

void copy_file(const char *src_file, const char *dst_file) {
    FILE *src = fopen(src_file, "rb");
    FILE *dst = fopen(dst_file, "wb");
    
    if (!src || !dst) {
        perror("File opening failed");
        if (src) fclose(src);
        return;
    }

    char buffer[BUFSIZE];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dst);
    }

    fclose(src);
    fclose(dst);
    
    printf("Copied: %s -> %s\n", src_file, dst_file);
}

void print_status(const char *message) {
    printf(">> %s\n", message);
}