//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define LOG_FILE "sync.log"

void log_message(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }
    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

int file_exists(const char *file_path) {
    struct stat buffer;
    return (stat(file_path, &buffer) == 0);
}

void copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    if (!source) {
        log_message("Source file could not be opened");
        return;
    }

    FILE *destination = fopen(dest, "wb");
    if (!destination) {
        fclose(source);
        log_message("Destination file could not be created");
        return;
    }

    char buffer[BUFSIZ];
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFSIZ, source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);

    char log_msg[MAX_PATH + 50];
    sprintf(log_msg, "Copied file from %s to %s", src, dest);
    log_message(log_msg);
}

void sync_directories(const char *src_dir, const char *dest_dir) {
    DIR *dir = opendir(src_dir);
    if (dir == NULL) {
        perror("Could not open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') { // Skip hidden files and directories
            continue;
        }

        char src_path[MAX_PATH];
        char dest_path[MAX_PATH];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (file_exists(dest_path)) {
            struct stat src_stat, dest_stat;
            stat(src_path, &src_stat);
            stat(dest_path, &dest_stat);
            if (src_stat.st_mtime > dest_stat.st_mtime) {
                // If source file is newer, copy it
                copy_file(src_path, dest_path);
            }
        } else {
            // If the file does not exist in the destination directory, copy it
            copy_file(src_path, dest_path);
        }
    }

    closedir(dir);
    log_message("Synchronization complete.");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    sync_directories(src_dir, dest_dir);
    printf("File synchronization from %s to %s completed successfully. Check %s for details.\n", src_dir, dest_dir, LOG_FILE);

    return EXIT_SUCCESS;
}