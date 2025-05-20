//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define LOG_FILE "intrusion_log.txt"
#define MAX_PATH 256
#define MAX_LOG_ENTRIES 1024

typedef struct {
    char timestamp[20];
    char message[256];
} LogEntry;

LogEntry log_entries[MAX_LOG_ENTRIES];
int log_count = 0;

void log_event(const char* message) {
    if (log_count < MAX_LOG_ENTRIES) {
        time_t now = time(NULL);
        strftime(log_entries[log_count].timestamp, sizeof(log_entries[log_count].timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
        snprintf(log_entries[log_count].message, sizeof(log_entries[log_count].message), "%s", message);
        log_count++;
    }
}

void write_log_to_file() {
    FILE* file = fopen(LOG_FILE, "w");
    if (file) {
        for (int i = 0; i < log_count; i++) {
            fprintf(file, "[%s] %s\n", log_entries[i].timestamp, log_entries[i].message);
        }
        fclose(file);
    } else {
        perror("Could not open log file");
    }
}

void monitor_directory(const char* dir_path) {
    DIR* dir;
    struct dirent* entry;
    char full_path[MAX_PATH];

    dir = opendir(dir_path);
    if (!dir) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // Check if it's a regular file
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            struct stat file_info;
            if (stat(full_path, &file_info) == 0) {
                // Add logging condition, e.g., log if file size exceeds a threshold
                if (file_info.st_size > 1024 * 1024) {  // Files larger than 1MB
                    char message[512];
                    snprintf(message, sizeof(message), "Large file detected: %s (size: %lld bytes)", full_path, (long long)file_info.st_size);
                    log_event(message);
                }
            }
        }
    }
    closedir(dir);
}

void check_for_intrusions() {
    // Here you can check for specific patterns, or perform anomaly detection
    // For simplicity, we'll just log an intrusion alert manually
    log_event("Potential intrusion detected: Unusual file access pattern.");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_monitor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* dir_to_monitor = argv[1];

    // Monitor the specified directory
    monitor_directory(dir_to_monitor);
    
    // Check for possible intrusions
    check_for_intrusions();
    
    // Write the log entries to a file
    write_log_to_file();

    printf("Monitoring completed. Check %s for log entries.\n", LOG_FILE);
    return EXIT_SUCCESS;
}