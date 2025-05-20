//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#define LOG_FILE "ids_log.txt"
#define BUFFER_SIZE 256
#define MONITOR_DIR "/var/log"

typedef struct {
    char file_name[BUFFER_SIZE];
    time_t last_modified;
} FileMonitor;

void log_event(const char *event) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }
    time_t now = time(NULL);
    fprintf(log_file, "[%s] %s\n", ctime(&now), event);
    fclose(log_file);
}

void check_file_modification(FileMonitor *monitor, int *monitor_count) {
    struct stat file_stat;
    char full_path[BUFFER_SIZE];

    DIR *dir = opendir(MONITOR_DIR);
    if (!dir) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check for regular files
            snprintf(full_path, sizeof(full_path), "%s/%s", MONITOR_DIR, entry->d_name);
            if (stat(full_path, &file_stat) == -1) {
                perror("stat failed");
                continue;
            }
            for (int i = 0; i < *monitor_count; i++) {
                if (strcmp(monitor[i].file_name, entry->d_name) == 0) {
                    if (difftime(file_stat.st_mtime, monitor[i].last_modified) != 0) {
                        snprintf(full_path, sizeof(full_path), "File modified: %s", entry->d_name);
                        log_event(full_path);
                        monitor[i].last_modified = file_stat.st_mtime; // Update time
                    }
                    break;
                }
            }
        }
    }
    closedir(dir);
}

void initialize_monitor(FileMonitor *monitor, int *monitor_count) {
    struct stat file_stat;
    char full_path[BUFFER_SIZE];

    DIR *dir = opendir(MONITOR_DIR);
    if (!dir) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            snprintf(full_path, sizeof(full_path), "%s/%s", MONITOR_DIR, entry->d_name);
            if (stat(full_path, &file_stat) == -1) {
                perror("stat failed");
                continue;
            }
            strncpy(monitor[*monitor_count].file_name, entry->d_name, BUFFER_SIZE);
            monitor[*monitor_count].last_modified = file_stat.st_mtime;
            (*monitor_count)++;
        }
    }
    closedir(dir);
}

int main() {
    FileMonitor monitor[BUFFER_SIZE];
    int monitor_count = 0;

    // Initialize log file
    FILE *log_file = fopen(LOG_FILE, "w");
    if (log_file == NULL) {
        perror("Error opening log file");
        return EXIT_FAILURE;
    }
    fclose(log_file);

    // Initialize monitored files
    initialize_monitor(monitor, &monitor_count);

    printf("Intrusion Detection System Monitoring Directory: %s\n", MONITOR_DIR);
    while (1) {
        check_file_modification(monitor, &monitor_count);
        sleep(5); // Check every 5 seconds
    }

    return EXIT_SUCCESS;
}