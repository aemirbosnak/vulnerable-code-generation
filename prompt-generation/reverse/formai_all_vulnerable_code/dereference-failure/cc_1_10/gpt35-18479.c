//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_LOG_LENGTH 100 // Maximum length of log messages
#define MAX_IP_LENGTH 16 // Maximum length of IP addresses
#define THRESHOLD 5 // Maximum allowed failed attempts per minute

struct log_entry {
    char timestamp[MAX_LOG_LENGTH];
    char ip_address[MAX_IP_LENGTH];
};

int main() {
    int ip_count = 0; // Counter for number of failed attempts
    struct log_entry current; // Current log entry
    FILE *log_file = fopen("auth.log", "r"); // In our example, we're reading from an auth.log file
    if (log_file == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }

    while (fgets(current.timestamp, MAX_LOG_LENGTH, log_file) != NULL) {
        // Parse log entry
        strtok(current.timestamp, " "); // Skip date field
        strtok(NULL, " "); // Skip time field
        strtok(NULL, " "); // Skip host field
        strtok(NULL, " "); // Skip program field
        strtok(NULL, " "); // Skip identifier field
        
        // Get IP address
        char *ip_address = strtok(NULL, " ");
        strncpy(current.ip_address, ip_address, MAX_IP_LENGTH);

        // Check if IP address has failed too many times
        if (!fork()) {
            sleep(60); // Wait for one minute before checking
            if (ip_count > THRESHOLD) {
                char *command = malloc(strlen(ip_address) + 25); // Allocate memory for command
                sprintf(command, "iptables -A INPUT -s %s -j DROP", ip_address); // Generate command to block IP address
                system(command); // Execute command
            }
            exit(0);
        } else {
            // Increment failed attempt counter for this IP
            ip_count++;
        }
    }

    fclose(log_file); // Close log file
    return 0;
}