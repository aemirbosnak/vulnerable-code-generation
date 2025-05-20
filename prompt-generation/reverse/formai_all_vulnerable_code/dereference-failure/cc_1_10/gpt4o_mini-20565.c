//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define LOG_FILE "intrusion_log.txt"
#define MAX_PATH_LENGTH 256
#define MAX_EVENTS 100
#define MONITOR_DIR "./monitor"
#define SUSPICIOUS_EXT ".exe" // Example of suspicious file type

typedef struct {
    char event_type[20];
    char file_path[MAX_PATH_LENGTH];
    time_t timestamp;
} Event;

Event events[MAX_EVENTS];
int event_count = 0;

// Function to log events
void log_event(const char* event_type, const char* file_path) {
    if (event_count < MAX_EVENTS) {
        strncpy(events[event_count].event_type, event_type, sizeof(events[event_count].event_type) - 1);
        strncpy(events[event_count].file_path, file_path, sizeof(events[event_count].file_path) - 1);
        events[event_count].timestamp = time(NULL);
        event_count++;
    }
}

// Function to save logs to a file
void save_logs() {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }
    
    for (int i = 0; i < event_count; i++) {
        fprintf(file, "[%s] %s: %s\n", ctime(&events[i].timestamp), events[i].event_type, events[i].file_path);
    }
    
    fclose(file);
}

// Function to monitor a directory for changes
void monitor_directory(const char* path) {
    DIR *dir;
    struct dirent *entry;
    char full_path[MAX_PATH_LENGTH];
    struct stat file_stat;

    if ((dir = opendir(path)) == NULL) {
        perror("Error opening directory");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
            if (stat(full_path, &file_stat) == 0) {
                if (S_ISREG(file_stat.st_mode)) {
                    // Check for suspicious file extensions
                    if (strstr(entry->d_name, SUSPICIOUS_EXT) != NULL) {
                        log_event("Suspicious File Detected", full_path);
                    }
                }
            }
        }
    }
    
    closedir(dir);
}

// Signal handler to gracefully exit
void handle_exit(int sig) {
    save_logs();
    exit(0);
}

int main() {
    signal(SIGINT, handle_exit);
    signal(SIGTERM, handle_exit);
    
    // Create directory to monitor if it does not exist
    mkdir(MONITOR_DIR, 0755);
    
    printf("Monitoring directory: %s\n", MONITOR_DIR);
    while (1) {
        // Monitor directory every second
        monitor_directory(MONITOR_DIR);
        sleep(1);
    }
    
    return 0;
}