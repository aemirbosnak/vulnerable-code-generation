//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define LOG_FILE "intrusion_log.txt"
#define MONITOR_DIR "/path/to/monitor" // Change this to the directory you want to monitor
#define MAX_FILES 1024

typedef struct {
    char filename[256];
    time_t last_modified;
} FileRecord;

FileRecord file_records[MAX_FILES];
int file_count = 0;

void log_event(const char *event) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file != NULL) {
        fprintf(log_file, "[%ld] %s\n", time(NULL), event);
        fclose(log_file);
    } else {
        perror("Error opening log file");
    }
}

void scan_directory() {
    struct dirent *entry;
    DIR *dp = opendir(MONITOR_DIR);
    struct stat file_info;

    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Process regular files only
            char filepath[512];
            snprintf(filepath, sizeof(filepath), "%s/%s", MONITOR_DIR, entry->d_name);

            if (stat(filepath, &file_info) == 0) {
                int found = 0;

                // Check if we already have this file recorded
                for (int i = 0; i < file_count; i++) {
                    if (strcmp(file_records[i].filename, entry->d_name) == 0) {
                        found = 1;

                        // If modified, log the event
                        if (file_records[i].last_modified != file_info.st_mtime) {
                            char log_msg[512];
                            snprintf(log_msg, sizeof(log_msg), "File modified: %s", entry->d_name);
                            log_event(log_msg);
                            file_records[i].last_modified = file_info.st_mtime;
                        }
                        break;
                    }
                }

                // If not found, we add the new file to our records
                if (!found && file_count < MAX_FILES) {
                    strcpy(file_records[file_count].filename, entry->d_name);
                    file_records[file_count].last_modified = file_info.st_mtime;
                    char log_msg[512];
                    snprintf(log_msg, sizeof(log_msg), "New file detected: %s", entry->d_name);
                    log_event(log_msg);
                    file_count++;
                }
            }
        }
    }

    closedir(dp);
}

void remove_old_records() {
    time_t now = time(NULL);
    for (int i = 0; i < file_count; i++) {
        if (difftime(now, file_records[i].last_modified) > 60 * 60) { // More than 1 hour old
            char log_msg[512];
            snprintf(log_msg, sizeof(log_msg), "File record removed: %s", file_records[i].filename);
            log_event(log_msg);
            // Shift records to remove the old entry
            for (int j = i; j < file_count - 1; j++) {
                file_records[j] = file_records[j + 1];
            }
            file_count--;
            i--; // Check the new record at index i again
        }
    }
}

int main() {
    while (1) {
        printf("Monitoring directory: %s\n", MONITOR_DIR);
        scan_directory();
        remove_old_records();
        sleep(10); // Wait before the next scan
    }

    return 0;
}