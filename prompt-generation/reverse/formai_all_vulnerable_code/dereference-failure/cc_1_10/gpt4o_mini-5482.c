//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_LOGS 100
#define LOG_FILE "intrusion_logs.txt"
#define MONITOR_DIR "/var/www/html" // Directory to monitor

typedef struct {
    time_t timestamp;
    char operation[10];
    char filename[256];
} LogEntry;

LogEntry logs[MAX_LOGS];
int log_count = 0;

void log_activity(const char *operation, const char *filename) {
    if (log_count < MAX_LOGS) {
        logs[log_count].timestamp = time(NULL);
        strncpy(logs[log_count].operation, operation, sizeof(logs[log_count].operation) - 1);
        strncpy(logs[log_count].filename, filename, sizeof(logs[log_count].filename) - 1);
        log_count++;
    } else {
        printf("Log capacity reached. Please review the log file.\n");
    }
}

void save_logs_to_file() {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }
    for (int i = 0; i < log_count; i++) {
        fprintf(file, "%s %s %s\n", ctime(&logs[i].timestamp), logs[i].operation, logs[i].filename);
    }
    fclose(file);
    log_count = 0; // Reset log count after saving
}

void scan_directory() {
    struct stat fileStat;
    DIR *d;
    struct dirent *dir;
    d = opendir(MONITOR_DIR);

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
                char filepath[512];
                snprintf(filepath, sizeof(filepath), "%s/%s", MONITOR_DIR, dir->d_name);
                if (stat(filepath, &fileStat) < 0) {
                    perror("Could not stat the file");
                    continue;
                }
                // Check file creation time
                time_t cur_time = time(NULL);
                if ((cur_time - fileStat.st_mtime) < 5) { // e.g., files modified in the last 5 seconds
                    log_activity("CREATED", dir->d_name);
                }
                // Add more checks as needed for delete, modified etc.
            }
        }
        closedir(d);
    } else {
        perror("Could not open directory");
    }
}

void monitor_activity() {
    while (1) {
        scan_directory();
        save_logs_to_file();
        sleep(5); // Monitor every 5 seconds
    }
}

int main(int argc, char *argv[]) {
    printf("Starting Intrusion Detection System...\n");
    monitor_activity();
    return 0;
}