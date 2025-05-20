//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 100

struct log_entry {
    char ip[16];
    time_t timestamp;
};

int main() {
    struct log_entry log[MAX_LOG_SIZE];
    int log_size = 0;

    printf("Welcome to our intrusion detection system!\n");

    while (1) {
        char ip[16];
        printf("Enter source IP address: ");
        scanf("%15s", ip);

        // Check if IP is in blacklist
        FILE *blacklist = fopen("blacklist.txt", "r");
        char line[16];
        int is_blacklisted = 0;
        while (fgets(line, 16, blacklist) != NULL) {
            if (strncmp(ip, line, strlen(line)-1) == 0) {
                printf("*** Warning: IP address %s is blacklisted! ***\n", ip);
                is_blacklisted = 1;
                break;
            }
        }
        fclose(blacklist);

        if (!is_blacklisted) {
            // Check if IP is already in log
            int i;
            for (i = 0; i < log_size; i++) {
                if (strcmp(ip, log[i].ip) == 0) {
                    time_t current_time;
                    time(&current_time);
                    double time_diff = difftime(current_time, log[i].timestamp);
                    if (time_diff < 10) {
                        printf("*** Warning: IP address %s is making too many requests! ***\n", ip);
                    } else {
                        log[i].timestamp = current_time;
                    }
                    break;
                }
            }

            if (i == log_size) {
                // IP not in log, add new entry
                if (log_size == MAX_LOG_SIZE) {
                    // Log is full, remove oldest entry
                    int j;
                    for (j = 1; j < MAX_LOG_SIZE; j++) {
                        log[j-1] = log[j];
                    }
                    log_size--;
                }

                struct log_entry new_entry;
                strcpy(new_entry.ip, ip);
                time(&new_entry.timestamp);
                log[log_size] = new_entry;
                log_size++;
            }
        }
    }

    return 0;
}