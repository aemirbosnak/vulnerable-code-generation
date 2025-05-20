//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_URL_LENGTH 256
#define LOG_FILE "uptime_log.txt"
#define CHECK_INTERVAL 5 // in seconds

void log_status(const char *url, const char *status) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Unable to open log file");
        return;
    }
    
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    
    // Remove the newline character from ctime output
    time_str[strcspn(time_str, "\n")] = 0;

    fprintf(fp, "[%s] URL: %s - Status: %s\n", time_str, url, status);
    fclose(fp);
}

void check_website(const char *url) {
    char command[MAX_URL_LENGTH + 50];
    snprintf(command, sizeof(command), "curl -s --head --request GET %s | grep 'HTTP/' | awk '{print $2}'", url);
    
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        return;
    }
    
    char result[16];
    if (fgets(result, sizeof(result), fp) != NULL) {
        // Check if the status code indicates success
        if (strstr(result, "200") != NULL) {
            log_status(url, "UP");
        } else {
            log_status(url, "DOWN");
        }
    } else {
        log_status(url, "ERROR checking URL");
    }

    pclose(fp);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("=========================================\n");
    printf("      Retro Website Uptime Monitor      \n");
    printf("=========================================\n");
    printf("Enter the URL to monitor: ");
    fgets(url, sizeof(url), stdin);
    
    // Remove trailing newline
    url[strcspn(url, "\n")] = 0;

    printf("Monitoring website: %s\n", url);
    printf("Press Ctrl+C to stop monitoring.\n");

    // Create or clear the log file
    FILE *fp = fopen(LOG_FILE, "w");
    if (fp == NULL) {
        perror("Unable to open log file");
        return 1;
    }
    fclose(fp);

    while (1) {
        check_website(url);
        sleep(CHECK_INTERVAL);
    }

    return 0;
}