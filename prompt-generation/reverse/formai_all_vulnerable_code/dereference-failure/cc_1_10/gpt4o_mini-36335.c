//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_PATH 256

typedef struct {
    char path[MAX_PATH];
    time_t last_modified;
} FileEntry;

FileEntry files[MAX_FILES];
int file_count = 0;

void record_file(const char *filepath) {
    struct stat file_stat;
    if (stat(filepath, &file_stat) == 0) {
        strcpy(files[file_count].path, filepath);
        files[file_count].last_modified = file_stat.st_mtime;
        file_count++;
    }
}

void log_change(const char *filepath, const char *change_type) {
    FILE *logfile = fopen("intrusion_log.txt", "a");
    if (logfile == NULL) {
        perror("Failed to open log file");
        return;
    }
    time_t now = time(NULL);
    fprintf(logfile, "[%s] %s: %s\n", ctime(&now), change_type, filepath);
    fclose(logfile);
}

void check_for_changes(const char *directory) {
    struct stat file_stat;
    DIR *dir = opendir(directory);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the current and parent directories
        }

        char filepath[MAX_PATH];
        snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
        if (stat(filepath, &file_stat) == 0) {
            int found = 0;
            for (int i = 0; i < file_count; i++) {
                if (strcmp(files[i].path, filepath) == 0) {
                    found = 1;
                    if (files[i].last_modified != file_stat.st_mtime) {
                        log_change(filepath, "Modified");
                        files[i].last_modified = file_stat.st_mtime; // Update the last modified time
                    }
                    break;
                }
            }
            if (!found) {
                log_change(filepath, "Created");
                record_file(filepath);
            }
        }
    }

    for (int i = 0; i < file_count; i++) {
        int found = 0;
        for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
            char filepath[MAX_PATH];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            if (strcmp(files[i].path, filepath) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            log_change(files[i].path, "Deleted");
            files[i] = files[--file_count]; // Remove the file from the list
            i--; // Decrease i since we have shifted elements
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_monitor>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *directory = argv[1];
    while (1) {
        check_for_changes(directory);
        sleep(10); // Wait for 10 seconds before checking again
    }

    return 0;
}