//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_URL_LENGTH 256
#define CHECK_INTERVAL 5 // in seconds

void log_status(const char *url, int status) {
    FILE *file = fopen("uptime_log.txt", "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }
    
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline

    if (status == 0) {
        fprintf(file, "%s: %s is UP!\n", timestamp, url);
    } else {
        fprintf(file, "%s: %s is DOWN!\n", timestamp, url);
    }

    fclose(file);
}

int check_website(const char *url) {
    char command[MAX_URL_LENGTH + 20];
    snprintf(command, sizeof(command), "ping -c 1 %s > /dev/null 2>&1", url);
    int result = system(command);

    return result == 0 ? 0 : 1; // return 0 if UP, 1 if DOWN
}

void display_help() {
    printf("Welcome to the Uptime Monitor!\n");
    printf("Usage: ./uptime_monitor <url>\n");
    printf("The program will check if the website is up or down every %d seconds.\n", CHECK_INTERVAL);
    printf("Log will be saved in uptime_log.txt.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_help();
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    printf("Monitoring the website: %s\n", url);

    while (1) {
        int status = check_website(url);
        log_status(url, status);
        sleep(CHECK_INTERVAL);
    }

    return EXIT_SUCCESS;
}