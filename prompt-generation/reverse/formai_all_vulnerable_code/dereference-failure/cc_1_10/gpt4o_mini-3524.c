//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_PATH_LENGTH 1024
#define LOG_FILE "admin_log.txt"
#define MAX_LOG_LENGTH 256

void paranoid_log(const char *message) {
    FILE *logfile = fopen(LOG_FILE, "a");
    if (logfile == NULL) {
        fprintf(stderr, "Failed to open log file: %s\n", LOG_FILE);
        exit(EXIT_FAILURE);
    }
    
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // remove newline

    fprintf(logfile, "[%s] %s\n", timestamp, message);
    fclose(logfile);
}

void check_file_existence(const char *filepath) {
    struct stat buffer;
    if (stat(filepath, &buffer) == 0) {
        char log_message[MAX_LOG_LENGTH];
        snprintf(log_message, MAX_LOG_LENGTH, "File exists: %s", filepath);
        paranoid_log(log_message);
    } else {
        char log_message[MAX_LOG_LENGTH];
        snprintf(log_message, MAX_LOG_LENGTH, "File does not exist: %s", filepath);
        paranoid_log(log_message);
    }
}

void validate_user_process() {
    pid_t pd = getpid();
    char log_message[MAX_LOG_LENGTH];
    snprintf(log_message, MAX_LOG_LENGTH, "Checking process: PID %d", pd);
    paranoid_log(log_message);
    
    if (getppid() == 1) {
        paranoid_log("Warning: Process has no parent (possible zombie process).");
    }
}

void check_root_access() {
    if (geteuid() != 0) {
        paranoid_log("Warning: Non-root user. Insufficient privileges.");
        exit(EXIT_FAILURE);
    } else {
        paranoid_log("Root access verified.");
    }
}

void resource_monitor() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) {
        paranoid_log("Error: Unable to open /proc/meminfo.");
        exit(EXIT_FAILURE);
    }
    char buffer[255];
    while (fgets(buffer, sizeof(buffer), fp)) {
        paranoid_log(buffer);  // Log memory info for paranoia
    }
    fclose(fp);
}

void monitor_logs() {
    char command[MAX_PATH_LENGTH];
    snprintf(command, MAX_PATH_LENGTH, "tail -n 10 %s", LOG_FILE);
    system(command);  // Be careful, output monitoring
}

int main() {
    paranoid_log("System administration script started.");

    check_root_access();
    check_file_existence("/etc/passwd");
    validate_user_process();

    paranoid_log("Starting resource monitoring.");
    resource_monitor();

    paranoid_log("Monitoring recent logs from admin_log.txt.");
    monitor_logs();

    paranoid_log("System administration script completed.");
    return 0;
}