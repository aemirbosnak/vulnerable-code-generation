//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

#define MAX_FILES 1024
#define MONITOR_DIR "./monitor_dir"
#define LOG_FILE "intrusion_log.txt"

typedef struct {
    char filename[256];
    time_t last_modified;
} FileInfo;

FileInfo monitored_files[MAX_FILES];
int file_count = 0;

void log_activity(const char *message) {
    FILE *logfile = fopen(LOG_FILE, "a");
    if (logfile == NULL) {
        fprintf(stderr, "Error opening log file!\n");
        exit(EXIT_FAILURE);
    }
    time_t now = time(NULL);
    fprintf(logfile, "[%s] %s\n", ctime(&now), message);
    fclose(logfile);
}

void scan_directory() {
    DIR *dir = opendir(MONITOR_DIR);
    struct dirent *entry;
    if (dir == NULL) {
        log_activity("Failed to open monitor directory.");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            char filepath[512];
            snprintf(filepath, sizeof(filepath), "%s/%s", MONITOR_DIR, entry->d_name);
            struct stat file_stat;

            if (stat(filepath, &file_stat) == 0) {
                // Check if the file is already monitored
                int found = 0;
                for (int i = 0; i < file_count; i++) {
                    if (strcmp(monitored_files[i].filename, entry->d_name) == 0) {
                        // File exists, check modification time
                        if (monitored_files[i].last_modified != file_stat.st_mtime) {
                            log_activity("File modified: ");
                            log_activity(entry->d_name);
                            monitored_files[i].last_modified = file_stat.st_mtime; // Update timestamp
                        }
                        found = 1;
                        break;
                    }
                }
                // New file detected
                if (!found) {
                    strncpy(monitored_files[file_count].filename, entry->d_name, sizeof(monitored_files[file_count].filename));
                    monitored_files[file_count].last_modified = file_stat.st_mtime;
                    file_count++;
                    log_activity("New file detected: ");
                    log_activity(entry->d_name);
                }
            } else {
                log_activity("Error getting file stats for: ");
                log_activity(entry->d_name);
            }
        }
    }
    closedir(dir);
}

void initialize_monitoring() {
    FILE *logfile = fopen(LOG_FILE, "w");
    if (logfile == NULL) {
        fprintf(stderr, "Error initializing log file!\n");
        exit(EXIT_FAILURE);
    }
    fclose(logfile);
    log_activity("Monitoring initialized. Watching directory: " MONITOR_DIR);
}

int main() {
    initialize_monitoring();

    while (1) {
        scan_directory();
        sleep(10); // Check every 10 seconds
    }

    return 0;
}