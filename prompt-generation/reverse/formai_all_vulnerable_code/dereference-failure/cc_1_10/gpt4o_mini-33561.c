//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define LOG_FILE "ids_log.txt"
#define MAX_PATH 1024
#define MAX_FILES 100
#define ALERT_THRESHOLD 10

typedef struct {
    char path[MAX_PATH];
    time_t last_mod_time;
    int change_count;
} FileMonitor;

FileMonitor watched_files[MAX_FILES];
int file_count = 0;

void log_event(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file) {
        time_t now = time(NULL);
        fprintf(log_file, "[%s] %s\n", ctime(&now), message);
        fclose(log_file);
    }
}

void monitor_file(const char *file_path) {
    struct stat file_stat;
    if (stat(file_path, &file_stat) == 0) {
        strcpy(watched_files[file_count].path, file_path);
        watched_files[file_count].last_mod_time = file_stat.st_mtime;
        watched_files[file_count].change_count = 0;
        file_count++;
    } else {
        perror("Failed to monitor file");
    }
}

void check_file_changes() {
    for (int i = 0; i < file_count; i++) {
        struct stat file_stat;
        if (stat(watched_files[i].path, &file_stat) == 0) {
            if (watched_files[i].last_mod_time != file_stat.st_mtime) {
                watched_files[i].last_mod_time = file_stat.st_mtime;
                watched_files[i].change_count++;
                
                // Log change event
                char log_message[256];
                snprintf(log_message, sizeof(log_message), "File changed: %s", watched_files[i].path);
                log_event(log_message);

                if (watched_files[i].change_count > ALERT_THRESHOLD) {
                    snprintf(log_message, sizeof(log_message), "ALERT: %s has been modified more than %d times", watched_files[i].path, ALERT_THRESHOLD);
                    log_event(log_message);
                }
            }
        } else {
            perror("Failed to check file");
        }
    }
}

void monitor_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    char full_path[MAX_PATH];
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            monitor_file(full_path);
        }
    }
    closedir(dir);
}

int main() {
    // Monitor the /tmp directory
    monitor_directory("/tmp");
    
    // Main monitoring loop
    while (1) {
        check_file_changes();
        sleep(5); // Check every 5 seconds
    }

    return 0;
}