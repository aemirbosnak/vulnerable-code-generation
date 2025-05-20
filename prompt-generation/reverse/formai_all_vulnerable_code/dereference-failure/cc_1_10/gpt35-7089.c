//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the log files
#define MAX_LOG_LEN 1000

// Struct to hold log information
typedef struct Log {
    char timestamp[20];
    char source_ip[16];
    char message[MAX_LOG_LEN];
} Log;

// Function to read log file and return a Log object
Log parse_log_file(char* log_file) {
    FILE* log_fp = fopen(log_file, "r");
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    Log log_obj;
    char delim[2] = ",";

    // Read first line of file (header) and ignore
    getline(&line, &len, log_fp);

    // Parse log file and store in Log object
    read = getline(&line, &len, log_fp);
    if (read != -1) {
        char* token = strtok(line, delim);
        strcpy(log_obj.timestamp, token);

        token = strtok(NULL, delim);
        strcpy(log_obj.source_ip, token);

        token = strtok(NULL, delim);
        strcpy(log_obj.message, token);
    }

    fclose(log_fp);
    return log_obj;
}

int main() {
    char* log_file = "/var/log/syslog";
    char* attack_ip = "192.168.0.100";

    while (1) {
        // Read latest log entry
        Log log_obj = parse_log_file(log_file);

        // If source IP is the same as the attack IP, issue warning
        if (strcmp(log_obj.source_ip, attack_ip) == 0) {
            printf("[WARNING] Intrusion detected from IP %s\n", log_obj.source_ip);
            // Notify security team via email or text message
        }

        // Wait for a few seconds before checking again
        sleep(3);
    }

    return 0;
}