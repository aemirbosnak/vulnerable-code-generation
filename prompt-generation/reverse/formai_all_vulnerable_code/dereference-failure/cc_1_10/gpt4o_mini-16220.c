//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

// Function prototypes 
void log_event(const char *event);
int check_disk_usage();
void check_running_processes();
void check_file_permissions(const char *filename);

// Constants
#define LOG_FILE "system_audit.log"
#define MAX_LOG_SIZE 1024

int main() {
    // Logging the system administrator task initiation
    log_event("System audit started");

    // Check disk usage
    if (check_disk_usage() < 75) {
        log_event("Disk usage is within safe limits.");
    } else {
        log_event("Warning! Disk usage exceeds 75%!");
    }

    // Checking running processes
    check_running_processes();

    // Checking sensitive file permissions
    const char *sensitive_files[] = {
        "/etc/shadow", 
        "/etc/passwd", 
        "/var/log/syslog"
    };

    for (int i = 0; i < sizeof(sensitive_files) / sizeof(sensitive_files[0]); i++) {
        check_file_permissions(sensitive_files[i]);
    }

    // Logging the end of the audit task
    log_event("System audit completed");

    return 0;
}

void log_event(const char *event) {
    // Open log file
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Could not open log file");
        exit(1);
    }

    // Get current time
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline

    // Write the event to log
    fprintf(log_file, "[%s] %s\n", timestamp, event);

    // Close the log file
    fclose(log_file);
}

int check_disk_usage() {
    char buffer[128];
    FILE *fp = popen("df / | awk 'NR==2 {print $5}'", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }
    
    fgets(buffer, sizeof(buffer), fp);
    pclose(fp);

    // Remove the percent sign
    buffer[strcspn(buffer, "%")] = 0;

    return atoi(buffer);
}

void check_running_processes() {
    log_event("Checking running processes...");

    FILE *fp = popen("ps -eo pid,comm", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Only log processes that might be suspicious
        if (strstr(line, "malicious_process") != NULL) {
            log_event("Suspicious process detected:");
            log_event(line);
        }
    }

    pclose(fp);
}

void check_file_permissions(const char *filename) {
    struct stat fileStat;
    if (stat(filename, &fileStat) < 0) {
        log_event("Failed to get file stats:");
        log_event(filename);
        return;
    }

    // Check permissions
    if ((fileStat.st_mode & S_IRUSR) == 0) {
        log_event("No read access for owner on:");
        log_event(filename);
    }

    if ((fileStat.st_mode & S_IWUSR) == 0) {
        log_event("No write access for owner on:");
        log_event(filename);
    }
    
    if ((fileStat.st_mode & S_IRGRP) == 0) {
        log_event("No read access for group on:");
        log_event(filename);
    }

    if ((fileStat.st_mode & S_IWGRP) == 0) {
        log_event("No write access for group on:");
        log_event(filename);
    }

    if ((fileStat.st_mode & S_IROTH) == 0) {
        log_event("No read access for others on:");
        log_event(filename);
    }

    if ((fileStat.st_mode & S_IWOTH) == 0) {
        log_event("No write access for others on:");
        log_event(filename);
    }
}