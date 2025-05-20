//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define LOG_FILE "system.log"
#define IDS_LOG_FILE "ids.log"
#define BUFFER_SIZE 256
#define MAX_ATTEMPTS 5

typedef struct {
    char timestamp[100];
    char ip_address[16];
    char action[50];
} LogEntry;

void log_event(LogEntry entry) {
    FILE *file = fopen(IDS_LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open IDS log file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s - %s - %s\n", entry.timestamp, entry.ip_address, entry.action);
    fclose(file);
}

int check_for_intrusions(const char *ip_address) {
    static int attempt_count = 0;
    attempt_count++;

    if (attempt_count > MAX_ATTEMPTS) {
        attempt_count = 0; // Reset after logging
        return 1; // Signal intrusion
    }
    return 0; // No intrusion
}

void scan_log_file() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        LogEntry entry;
        char *token = strtok(buffer, " ");
        strcpy(entry.timestamp, token);
        token = strtok(NULL, " ");
        strcpy(entry.ip_address, token);
        token = strtok(NULL, " ");
        strcpy(entry.action, token);

        if (strstr(entry.action, "unauthorized") != NULL) {
            printf("Unauthorized access attempt detected from IP: %s\n", entry.ip_address);
            LogEntry intrusion_entry;
            strcpy(intrusion_entry.timestamp, entry.timestamp);
            strcpy(intrusion_entry.ip_address, entry.ip_address);
            strcpy(intrusion_entry.action, "Potential intrusion detected!");
            
            log_event(intrusion_entry);
            
            if (check_for_intrusions(entry.ip_address)) {
                printf("ALERT: Intrusion detected from IP: %s\n", entry.ip_address);
            }
        }
    }

    fclose(file);
}

void generate_log_entry(const char *ip_address, const char *action) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character

    fprintf(file, "%s %s %s\n", timestamp, ip_address, action);
    fclose(file);
}

int main() {
    // Simulate generating log entries
    generate_log_entry("192.168.1.10", "login successful");
    generate_log_entry("192.168.1.10", "unauthorized access attempt");
    generate_log_entry("192.168.1.10", "unauthorized access attempt");
    generate_log_entry("192.168.1.10", "unauthorized access attempt");
    generate_log_entry("192.168.1.10", "unauthorized access attempt");
    generate_log_entry("192.168.1.10", "unauthorized access attempt"); // This should trigger an alert

    // Scan the log file for intrusions
    scan_log_file();

    return 0;
}