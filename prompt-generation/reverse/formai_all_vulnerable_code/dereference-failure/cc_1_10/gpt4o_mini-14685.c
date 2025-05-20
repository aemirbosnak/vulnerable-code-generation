//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_URLS 10
#define PING_INTERVAL 5 // seconds
#define LOG_FILE "uptime_log.txt"

// Function to ping a URL
int ping_site(const char *url) {
    char command[100];
    snprintf(command, sizeof(command), "ping -c 1 -W 1 %s > /dev/null 2>&1", url);
    return system(command);
}

// Function to log the uptime status
void log_status(const char *url, int status) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        return;
    }

    time_t now;
    time(&now);
    char *date_time = ctime(&now);
    // Remove newline
    date_time[strlen(date_time) - 1] = '\0';

    if (status == 0) {
        fprintf(log_file, "[%s] %s is UP!\n", date_time, url);
        printf("[SUCCESS] %s is UP!\n", url);
    } else {
        fprintf(log_file, "[%s] %s is DOWN!\n", date_time, url);
        printf("[ERROR] %s is DOWN!\n", url);
    }

    fclose(log_file);
}

int main() {
    char *urls[MAX_URLS] = {
        "www.google.com",
        "www.example.com",
        "www.github.com",
        "www.stackoverflow.com",
        "www.nonexistentwebsiteabcxyz.com", // This is just for testing failure
    };

    printf("🎉 Welcome to the Website Uptime Monitor! 🎉\n");
    printf("🔥 Monitoring your favorite sites every %d seconds! 🔥\n", PING_INTERVAL);

    while (1) {
        for (int i = 0; i < MAX_URLS; i++) {
            if (urls[i] == NULL) break; // Stop if there are no more URLs
            int status = ping_site(urls[i]);
            log_status(urls[i], status);
        }
        sleep(PING_INTERVAL);
    }

    return 0; // Although this never gets executed, it's good practice!
}