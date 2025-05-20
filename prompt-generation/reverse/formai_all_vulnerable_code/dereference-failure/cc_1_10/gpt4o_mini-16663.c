//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define LOG_FILE "intrusion_log.txt"
#define MONITOR_DIR "."

typedef struct {
    char timestamp[20];
    char action[10];
    char file_path[BUFFER_SIZE];
} LogEntry;

void log_event(const char *action, const char *file_path) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        perror("Failed to open log file");
        return;
    }

    LogEntry entry;
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(entry.timestamp, sizeof(entry.timestamp), "%Y-%m-%d %H:%M:%S", tm_info);
    
    strncpy(entry.action, action, sizeof(entry.action));
    strncpy(entry.file_path, file_path, sizeof(entry.file_path));

    fprintf(log_file, "[%s] %s: %s\n", entry.timestamp, entry.action, entry.file_path);
    fclose(log_file);
}

void check_directory() {
    struct dirent *entry;
    DIR *dp = opendir(MONITOR_DIR);
    
    if (dp == NULL) {
        perror("Failed to open the directory");
        return;
    }

    char path[BUFFER_SIZE];
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            snprintf(path, sizeof(path), "%s/%s", MONITOR_DIR, entry->d_name);
            struct stat statbuf;
            if (stat(path, &statbuf) == -1) {
                perror("Failed to get file statistics");
                continue;
            }
            log_event("CHECK", path);
        }
    }
    closedir(dp);
}

void simulate_intrusion(const char *file_path) {
    FILE *fake_file = fopen(file_path, "w");
    if (!fake_file) {
        perror("Failed to create a fake intruder file");
        return;
    }
    fprintf(fake_file, "This is a fake intrusion!\n");
    fclose(fake_file);
    log_event("INTRUSION", file_path);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <duration_in_seconds>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int duration = atoi(argv[1]);
    if (duration <= 0) {
        fprintf(stderr, "Invalid duration provided.\n");
        return EXIT_FAILURE;
    }

    printf("Starting intrusion detection system...\n");
    printf("Monitoring directory: %s\n", MONITOR_DIR);
    printf("Duration: %d seconds\n", duration);

    time_t start_time = time(NULL);
    while (difftime(time(NULL), start_time) < duration) {
        check_directory();
        sleep(2);  // Check every 2 seconds
    }

    printf("Simulating an intrusion.\n");
    simulate_intrusion("fake_intruder_file.txt");

    return EXIT_SUCCESS;
}