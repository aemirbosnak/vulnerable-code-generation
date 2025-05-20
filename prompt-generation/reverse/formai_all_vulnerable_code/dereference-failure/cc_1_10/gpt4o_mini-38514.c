//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

#define LOG_FILE "/var/log/ids_log.txt"
#define MONITOR_DIR "/home/user/documents"
#define THRESHOLD_SIZE 1024 * 1024 // 1 MB
#define MAX_FILES_TO_MONITOR 100

typedef struct {
    char name[256];
    off_t size;
    time_t last_modified;
} FileInfo;

FileInfo monitored_files[MAX_FILES_TO_MONITOR];
int monitored_count = 0;

void log_event(const char *event_message) {
    FILE *log_fp = fopen(LOG_FILE, "a");
    if (log_fp == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }
    fprintf(log_fp, "%s: %s\n", event_message, ctime(&(time_t){time(NULL)}));
    fclose(log_fp);
}

void initialize_monitor() {
    DIR *dir = opendir(MONITOR_DIR);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Failed to open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            if (monitored_count < MAX_FILES_TO_MONITOR) {
                char filepath[512];
                snprintf(filepath, sizeof(filepath), "%s/%s", MONITOR_DIR, entry->d_name);
                struct stat file_stat;

                if (stat(filepath, &file_stat) == 0) {
                    strncpy(monitored_files[monitored_count].name, entry->d_name, sizeof(monitored_files[monitored_count].name));
                    monitored_files[monitored_count].size = file_stat.st_size;
                    monitored_files[monitored_count].last_modified = file_stat.st_mtime;
                    monitored_count++;
                }
            }
        }
    }
    closedir(dir);
}

void check_for_changes() {
    DIR *dir = opendir(MONITOR_DIR);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Failed to open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char filepath[512];
            snprintf(filepath, sizeof(filepath), "%s/%s", MONITOR_DIR, entry->d_name);
            struct stat file_stat;

            if (stat(filepath, &file_stat) == 0) {
                // Check if file exists in monitored_files
                int found = 0;
                for (int i = 0; i < monitored_count; i++) {
                    if (strcmp(monitored_files[i].name, entry->d_name) == 0) {
                        found = 1;
                        // File exists: check size and modification time
                        if (monitored_files[i].size != file_stat.st_size) {
                            log_event("File size change detected: ");
                        }
                        if (monitored_files[i].last_modified != file_stat.st_mtime) {
                            log_event("File modification time change detected: ");
                        }
                        monitored_files[i].size = file_stat.st_size;
                        monitored_files[i].last_modified = file_stat.st_mtime;
                        break;
                    }
                }
                if (!found) {
                    // New file detected
                    log_event("New file detected: ");
                    if (file_stat.st_size > THRESHOLD_SIZE) {
                        log_event("Warning: File exceeds threshold size: ");
                    }
                    // Add to monitored files
                    if (monitored_count < MAX_FILES_TO_MONITOR) {
                        strncpy(monitored_files[monitored_count].name, entry->d_name, sizeof(monitored_files[monitored_count].name));
                        monitored_files[monitored_count].size = file_stat.st_size;
                        monitored_files[monitored_count].last_modified = file_stat.st_mtime;
                        monitored_count++;
                    }
                }
            }
        }
    }
    closedir(dir);
}

void signal_handler(int signum) {
    log_event("IDS terminated by user");
    exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGINT, signal_handler);
    log_event("Intrusion Detection System started");

    initialize_monitor();

    while (1) {
        sleep(10); // Check for changes every 10 seconds
        check_for_changes();
    }

    return 0;
}