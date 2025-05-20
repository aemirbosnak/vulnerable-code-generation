//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define TIME_FORMAT "%Y-%m-%d %H:%M:%S"

typedef struct {
    char *source;
    char *destination;
} SyncPaths;

void log_sync_process(const char *msg) {
    FILE *logfile = fopen("sync_log.txt", "a");
    if (logfile) {
        time_t now = time(NULL);
        char buf[20];
        strftime(buf, sizeof(buf), TIME_FORMAT, localtime(&now));
        fprintf(logfile, "[%s] %s\n", buf, msg);
        fclose(logfile);
    }
} 

int file_exists(const char *filepath) {
    struct stat buffer;
    return (stat(filepath, &buffer) == 0);
}

void copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    FILE *destination = fopen(dest, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes;

    if (!source || !destination) {
        log_sync_process("Failed to open source or destination file");
        exit(EXIT_FAILURE);
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source))) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);

    char log_msg[256];
    snprintf(log_msg, sizeof(log_msg), "Copied: %s to %s", src, dest);
    log_sync_process(log_msg);
}

void synchronize_files(const SyncPaths *sync_paths) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(sync_paths->source)) == NULL) {
        log_sync_process("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char src_file[PATH_MAX];
            char dest_file[PATH_MAX];
            snprintf(src_file, sizeof(src_file), "%s/%s", sync_paths->source, entry->d_name);
            snprintf(dest_file, sizeof(dest_file), "%s/%s", sync_paths->destination, entry->d_name);

            if (file_exists(dest_file)) {
                struct stat src_stat, dest_stat;
                stat(src_file, &src_stat);
                stat(dest_file, &dest_stat);

                if (difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0) {
                    copy_file(src_file, dest_file);
                }
            } else {
                copy_file(src_file, dest_file);
            }
        }
    }
    
    closedir(dir);
    log_sync_process("Synchronization complete.");
}

void display_usage() {
    printf("Futuristic File Synchronizer\n");
    printf("Usage: sync_tool <source_directory> <destination_directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return EXIT_FAILURE;
    }

    SyncPaths sync_paths;
    sync_paths.source = argv[1];
    sync_paths.destination = argv[2];

    struct stat st;
    if (stat(sync_paths.source, &st) != 0 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Source directory does not exist or is not a directory.\n");
        return EXIT_FAILURE;
    }

    if (stat(sync_paths.destination, &st) != 0 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Destination directory does not exist or is not a directory.\n");
        return EXIT_FAILURE;
    }

    log_sync_process("Starting synchronization process...");
    synchronize_files(&sync_paths);

    return EXIT_SUCCESS;
}