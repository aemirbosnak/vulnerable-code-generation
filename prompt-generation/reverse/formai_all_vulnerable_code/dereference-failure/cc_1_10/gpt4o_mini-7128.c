//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_PATH 1024
#define LOG_FILE "sync_log.txt"

// Function declarations
void log_action(const char *message);
void synchronize_directories(const char *source, const char *target);
void copy_file(const char *source, const char *target);
int file_exists(const char *filename);
void update_file_if_different(const char *source, const char *target);
void list_files(const char *dir, char files[][MAX_PATH], int *count);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <target_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *target_dir = argv[2];

    log_action("Starting synchronization process...");
    synchronize_directories(source_dir, target_dir);
    log_action("Synchronization process completed.");

    return EXIT_SUCCESS;
}

void log_action(const char *message) {
    FILE *log = fopen(LOG_FILE, "a");
    if (log) {
        fprintf(log, "%s\n", message);
        fclose(log);
    } else {
        fprintf(stderr, "Could not open log file: %s\n", strerror(errno));
    }
}

void synchronize_directories(const char *source, const char *target) {
    char source_files[100][MAX_PATH];
    char target_files[100][MAX_PATH];
    int source_count = 0, target_count = 0;

    list_files(source, source_files, &source_count);
    list_files(target, target_files, &target_count);

    for (int i = 0; i < source_count; i++) {
        char target_file[MAX_PATH];
        snprintf(target_file, sizeof(target_file), "%s/%s", target, source_files[i]);
        update_file_if_different(source_files[i], target_file);
    }

    for (int i = 0; i < target_count; i++) {
        char source_file[MAX_PATH];
        snprintf(source_file, sizeof(source_file), "%s/%s", source, target_files[i]);
        if (!file_exists(source_file)) {
            log_action("Removing obsolete file from target: ");
            log_action(target_files[i]);
            remove(target_files[i]);
        }
    }
}

void copy_file(const char *source, const char *target) {
    FILE *src = fopen(source, "rb");
    FILE *dst = fopen(target, "wb");
    if (!src || !dst) {
        fprintf(stderr, "Error opening files for copying: %s\n", strerror(errno));
        return;
    }

    char buffer[1024];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dst);
    }

    fclose(src);
    fclose(dst);

    log_action("Copied file: ");
    log_action(target);
}

int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

void update_file_if_different(const char *source, const char *target) {
    if (!file_exists(target)) {
        copy_file(source, target);
        return;
    }

    struct stat src_stat, tgt_stat;
    stat(source, &src_stat);
    stat(target, &tgt_stat);

    if (src_stat.st_mtime > tgt_stat.st_mtime) {
        copy_file(source, target);
    }
}

void list_files(const char *dir, char files[][MAX_PATH], int *count) {
    DIR *d = opendir(dir);
    struct dirent *entry;

    if (d == NULL) {
        fprintf(stderr, "Could not open directory: %s\n", strerror(errno));
        return;
    }

    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            snprintf(files[*count], MAX_PATH, "%s/%s", dir, entry->d_name);
            (*count)++;
        }
    }

    closedir(d);
}