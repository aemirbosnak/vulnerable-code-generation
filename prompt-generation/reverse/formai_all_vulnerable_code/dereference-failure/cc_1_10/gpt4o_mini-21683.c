//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>

#define LOG_FILE "intrusion_log.txt"
#define MONITOR_DIR "/home/user/monitored" // Specify the directory to monitor
#define MAX_PATH_LENGTH 256

// Function to log the activity
void log_activity(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file) {
        time_t now = time(NULL);
        fprintf(log_file, "[%s]: %s\n", ctime(&now), message);
        fclose(log_file);
    }
}

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to monitor the directory for changes
void monitor_directory() {
    DIR *dir;
    struct dirent *entry;
    char prev_files[100][MAX_PATH_LENGTH];
    int prev_count = 0;

    // Store initial state of directory
    if ((dir = opendir(MONITOR_DIR)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] != '.') { // Exclude hidden files
                strcpy(prev_files[prev_count++], entry->d_name);
            }
        }
        closedir(dir);
    }

    while (1) {
        sleep(5); // Wait for 5 seconds before rechecking
        
        // Clear current file list
        char current_files[100][MAX_PATH_LENGTH];
        int current_count = 0;

        // Read current state of directory
        if ((dir = opendir(MONITOR_DIR)) != NULL) {
            while ((entry = readdir(dir)) != NULL) {
                if (entry->d_name[0] != '.') {
                    strcpy(current_files[current_count++], entry->d_name);
                }
            }
            closedir(dir);
        }

        // Detect changes: Added or Deleted files
        for (int i = 0; i < current_count; i++) {
            int found = 0;
            for (int j = 0; j < prev_count; j++) {
                if (strcmp(current_files[i], prev_files[j]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                char message[512];
                snprintf(message, sizeof(message), "File added: %s", current_files[i]);
                log_activity(message);
            }
        }

        for (int i = 0; i < prev_count; i++) {
            int found = 0;
            for (int j = 0; j < current_count; j++) {
                if (strcmp(prev_files[i], current_files[j]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                char message[512];
                snprintf(message, sizeof(message), "File deleted: %s", prev_files[i]);
                log_activity(message);
            }
        }

        // Update previous state
        prev_count = current_count;
        for (int i = 0; i < prev_count; i++) {
            strcpy(prev_files[i], current_files[i]);
        }
    }
}

// Main function
int main() {
    printf("Intrusion Detection System Monitoring started...\n");
    log_activity("Intrusion Detection System initialized.");

    monitor_directory();

    return 0;
}