//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IP_LEN 16
#define MAX_LOG_LINE_SIZE 256

// Struct to store log data
typedef struct {
    char src_ip[MAX_IP_LEN];
    char dest_ip[MAX_IP_LEN];
    char protocol[10];
    char status[10];
} LogEntry;

// Struct to store intrusion detection data
typedef struct {
    char ip[MAX_IP_LEN];
    int count;
} IntrusionData;

int main() {
    FILE *log_file = fopen("sample_log.txt", "r");
    char log_line[MAX_LOG_LINE_SIZE];

    // Array to store intrusion detection data
    IntrusionData intrusions[10];
    int intrusion_count = 0;

    while(fgets(log_line, MAX_LOG_LINE_SIZE, log_file)) {
        LogEntry log_entry;

        // Split log line into log entry fields
        sscanf(log_line, "%s %s %s %s", log_entry.src_ip, log_entry.dest_ip, log_entry.protocol, log_entry.status);

        // Check if this is a failed login attempt
        if(strcmp(log_entry.protocol, "ssh") == 0 && strcmp(log_entry.status, "failed") == 0) {
            int ip_exists = 0;

            // Check if source IP already exists in intrusion data
            for(int i = 0; i < intrusion_count; i++) {
                if(strcmp(intrusions[i].ip, log_entry.src_ip) == 0) {
                    // Increment count for existing IP
                    intrusions[i].count++;
                    ip_exists = 1;
                    break;
                }
            }

            if(!ip_exists) {
                // Add new IP to intrusion data
                strcpy(intrusions[intrusion_count].ip, log_entry.src_ip);
                intrusions[intrusion_count].count = 1;
                intrusion_count++;
            }
        }
    }

    // Print all IPs with more than 3 failed login attempts
    printf("Intrusion Detection Report:\n");
    printf("---------------------------\n");
    for(int i = 0; i < intrusion_count; i++) {
        if(intrusions[i].count > 3) {
            printf("%s - %d failed attempts\n", intrusions[i].ip, intrusions[i].count);
        }
    }

    fclose(log_file);
    return 0;
}