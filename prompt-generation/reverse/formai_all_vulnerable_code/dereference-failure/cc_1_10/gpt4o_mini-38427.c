//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256

void log_message(const char *message) {
    FILE *log_file = fopen("sync_log.txt", "a");
    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

void copy_file(const char *src, const char *dest) {
    char buffer[BUFFER_SIZE];
    FILE *src_file = fopen(src, "rb");
    FILE *dest_file = fopen(dest, "wb");

    if (!src_file || !dest_file) {
        log_message("Failed to open source or destination file.");
        exit(EXIT_FAILURE);
    }

    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    log_message("File copied successfully.");
}

void synchronizer(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    struct dirent *entry;

    if (dir == NULL) {
        log_message("Could not open source directory.");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char src_path[BUFFER_SIZE];
        char dest_path[BUFFER_SIZE];

        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(src_path, sizeof(src_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (file_exists(dest_path)) {
            log_message("File already exists in destination, skipping copy.");
        } else {
            copy_file(src_path, dest_path);
            log_message("New file added to destination.");
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    log_message("Synchronization process initiated.");
    
    synchronizer(source_directory, destination_directory);

    log_message("Synchronization process completed.");

    return 0;
}