//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024
#define LOG_FILE "intrusion_log.txt"
#define SUSPICIOUS_TERMS_COUNT 4

const char *suspicious_terms[SUSPICIOUS_TERMS_COUNT] = {
    "hack",
    "exploit",
    "malware",
    "unauthorized"
};

void log_event(const char *event) {
    FILE *logFile = fopen(LOG_FILE, "a");
    if (!logFile) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }
    time_t now = time(NULL);
    fprintf(logFile, "[%s] %s\n", ctime(&now), event);
    fclose(logFile);
}

int is_suspicious(const char *path) {
    for (int i = 0; i < SUSPICIOUS_TERMS_COUNT; i++) {
        if (strstr(path, suspicious_terms[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

void monitor_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }
    
    while ((entry = readdir(dp))) {
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_REG) {  // Regular file
            printf("Scanning file: %s\n", full_path);
            if (is_suspicious(entry->d_name)) {
                printf("Suspicious file detected: %s\n", full_path);
                log_event(full_path);
            }
        } else if (entry->d_type == DT_DIR) {  // Directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                monitor_directory(full_path); // Recursively monitor subdirectories
            }
        }
    }

    closedir(dp);
}

void run_monitor(const char *start_dir) {
    printf("Starting monitoring of directory: %s\n", start_dir);
    while (1) {
        monitor_directory(start_dir);
        // Sleep for a defined interval before checking again
        printf("Waiting for changes...\n");
        sleep(5); // Check every 5 seconds
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_monitor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Clear previous log
    FILE *logFile = fopen(LOG_FILE, "w");
    if (logFile) {
        fclose(logFile);
    }

    run_monitor(argv[1]);
    return EXIT_SUCCESS;
}