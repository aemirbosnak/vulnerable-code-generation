//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

void log_message(const char *message) {
    FILE *log_file = fopen("sync.log", "a");
    if (log_file) {
        time_t now = time(NULL);
        fprintf(log_file, "[%s] %s\n", ctime(&now), message);
        fclose(log_file);
    }
}

void sync_files(const char *src, const char *dest) {
    char src_file[MAX_PATH];
    char dest_file[MAX_PATH];
    struct stat src_stat, dest_stat;

    DIR *dir = opendir(src);
    if (!dir) {
        log_message("Failed to open source directory.");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files (e.g., '.' and '..')

        snprintf(src_file, sizeof(src_file), "%s/%s", src, entry->d_name);
        snprintf(dest_file, sizeof(dest_file), "%s/%s", dest, entry->d_name);

        // Check file status
        if (stat(src_file, &src_stat) == -1) {
            log_message("Failed to stat source file.");
            continue;
        }

        // Check if the destination file exists
        if (stat(dest_file, &dest_stat) == -1) {
            // File doesn't exist, copy it
            FILE *src_fp = fopen(src_file, "rb");
            FILE *dest_fp = fopen(dest_file, "wb");

            if (src_fp && dest_fp) {
                char buffer[BUFFER_SIZE];
                size_t bytes;
                while ((bytes = fread(buffer, 1, sizeof(buffer), src_fp))) {
                    fwrite(buffer, 1, bytes, dest_fp);
                }
                fclose(src_fp);
                fclose(dest_fp);
                char log_msg[256];
                snprintf(log_msg, sizeof(log_msg), "Copied new file: %s", entry->d_name);
                log_message(log_msg);
            }
            else {
                log_message("Failed to open source or destination file for copying.");
            }
            continue;
        }

        // If the source file is newer, replace the destination file
        if (src_stat.st_mtime > dest_stat.st_mtime) {
            FILE *src_fp = fopen(src_file, "rb");
            FILE *dest_fp = fopen(dest_file, "wb");

            if (src_fp && dest_fp) {
                char buffer[BUFFER_SIZE];
                size_t bytes;
                while ((bytes = fread(buffer, 1, sizeof(buffer), src_fp))) {
                    fwrite(buffer, 1, bytes, dest_fp);
                }
                fclose(src_fp);
                fclose(dest_fp);
                char log_msg[256];
                snprintf(log_msg, sizeof(log_msg), "Updated file: %s", entry->d_name);
                log_message(log_msg);
            }
            else {
                log_message("Failed to open source or destination file for updating.");
            }
        }
    }
    closedir(dir);
}

void show_usage() {
    printf("CyberSync v1.0 - The Pulse of the Data Jungle\n");
    printf("Usage: ./cybersync <source_directory> <destination_directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        show_usage();
        exit(EXIT_FAILURE);
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    log_message("Sync process initiated.");
    sync_files(source_directory, destination_directory);
    log_message("Sync process completed.");

    return 0;
}