//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH_LENGTH 1024
#define LOG_FILE "intrusion_log.txt"

void log_intrusion(const char *message) {
    time_t now = time(NULL);
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file != NULL) {
        fprintf(log_file, "[%s] %s\n", ctime(&now), message);
        fclose(log_file);
    } else {
        perror("Failed to open log file");
    }
}

void scan_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            char full_path[MAX_PATH_LENGTH];
            snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);

            struct stat file_stat;
            if (stat(full_path, &file_stat) == 0) {
                // Example condition for intrusion detection
                if (file_stat.st_size > 1024 * 1024) { // Files larger than 1MB
                    char log_message[MAX_PATH_LENGTH + 50];
                    snprintf(log_message, sizeof(log_message), "Possible intrusion: large file detected: %s", full_path);
                    log_intrusion(log_message);
                }
            }
        } else if (entry->d_type == DT_DIR) {
            // Ignore current and parent directory entries
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char sub_dir[MAX_PATH_LENGTH];
                snprintf(sub_dir, sizeof(sub_dir), "%s/%s", directory, entry->d_name);
                scan_directory(sub_dir);
            }
        }
    }

    closedir(dp);
}

void signal_handler(int signal) {
    if (signal == SIGINT) {
        log_intrusion("Intrusion detection system terminated.");
        exit(0);
    }
}

int main() {
    signal(SIGINT, signal_handler);

    const char *root_directory = "/path/to/monitor";  // Change this to the target directory for monitoring.
    log_intrusion("Intrusion detection system started.");

    while (1) {
        log_intrusion("Scanning directory...");
        scan_directory(root_directory);
        sleep(60);  // Delay between scans (in seconds)
    }

    return 0;
}