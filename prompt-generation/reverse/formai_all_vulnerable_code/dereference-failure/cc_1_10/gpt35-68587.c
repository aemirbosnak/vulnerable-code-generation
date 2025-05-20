//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP_LEN 16
#define MAX_LOG_LINE 100

struct log_entry {
    char timestamp[20];
    char source_ip[MAX_IP_LEN];
    char message[MAX_LOG_LINE];
};

struct blacklist_entry {
    char ip_address[MAX_IP_LEN];
    bool is_blocked;
};

// Define a prototype for our function
void analyze_logs(char *log_file, struct blacklist_entry *blacklist, int blacklist_size);

int main() {
    // Define our blacklist of IP addresses
    struct blacklist_entry blacklist[10] = {
        {"192.168.1.100", false},
        {"10.0.0.2", false},
        {"172.16.0.5", false},
        {"192.168.1.50", false},
        {"192.168.1.75", false},
        {"10.0.0.50", false},
        {"172.16.0.100", false},
        {"192.168.1.200", false},
        {"192.168.1.225", false},
        {"10.0.0.75", false}
    };

    // Call our function to analyze the logs
    analyze_logs("system_logs.txt", blacklist, 10);

    return 0;
}

void analyze_logs(char *log_file, struct blacklist_entry *blacklist, int blacklist_size) {
    // Open the log file for reading
    FILE *file = fopen(log_file, "r");
    if (!file) {
        printf("Error opening log file.\n");
        exit(1);
    }

    // Read in each line of the log file
    char line[MAX_LOG_LINE];
    struct log_entry entry;
    while (fgets(line, MAX_LOG_LINE, file)) {
        // Parse the line into its component parts
        char *token = strtok(line, ",");
        strcpy(entry.timestamp, token);

        token = strtok(NULL, ",");
        strcpy(entry.source_ip, token);

        token = strtok(NULL, ",");
        strcpy(entry.message, token);

        // Check if the source IP address is in the blacklist
        bool is_blocked = false;
        for (int i = 0; i < blacklist_size; i++) {
            if (strcmp(entry.source_ip, blacklist[i].ip_address) == 0) {
                is_blocked = true;
                blacklist[i].is_blocked = true;
                break;
            }
        }

        // If the IP address is in the blacklist, print a message
        if (is_blocked) {
            printf("Intrusion detected at %s from source IP %s\n", entry.timestamp, entry.source_ip);
        }
    }

    // Close the log file
    fclose(file);

    // Print out the final blacklist
    printf("Blacklist:\n");
    for (int i = 0; i < blacklist_size; i++) {
        printf("IP address %s is%s blocked\n", blacklist[i].ip_address, blacklist[i].is_blocked ? "" : " not");
    }
}