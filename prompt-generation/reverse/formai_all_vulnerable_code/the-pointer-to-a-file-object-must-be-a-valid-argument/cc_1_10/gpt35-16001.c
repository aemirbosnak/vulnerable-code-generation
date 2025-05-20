//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define BUFFER_SIZE 256

struct LogEntry {
    char* timestamp;
    char* message;
};

struct LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

// Function to read the log file
void readLogFile(char* filename) {
    FILE* fp;
    char buffer[BUFFER_SIZE];
    
    fp = fopen(filename, "r");
    
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        // Split timestamp and message
        char *token = strtok(buffer, ",");
        char* timestamp = token;
        
        token = strtok(NULL, ",");
        char* message = token;
        
        // Create LogEntry and add to array
        struct LogEntry entry;
        entry.timestamp = timestamp;
        entry.message = message;
        logEntries[logCount] = entry;
        logCount++;
        
        if (logCount >= MAX_LOG_ENTRIES) {
            printf("Max log entries reached. Exiting..\n");
            break;
        }
    }
    
    fclose(fp);
}

// Function to detect potential intrusions
void detectIntrusions() {
    int i, j;
    
    // Check for repeated messages from the same IP
    for (i = 0; i < logCount; i++) {
        // Get IP address and message
        char* message = logEntries[i].message;
        char* ipStart = strchr(message, '[') + 1;
        char* ipEnd = strchr(ipStart, ']');
        *ipEnd = '\0';
        char* ip = ipStart;
        
        // Check for another message with same IP
        for (j = 0; j < logCount; j++) {
            char* message2 = logEntries[j].message;
            char* ipStart2 = strchr(message2, '[') + 1;
            char* ipEnd2 = strchr(ipStart2, ']');
            *ipEnd2 = '\0';
            char* ip2 = ipStart2;
            
            if (i != j && strcmp(ip, ip2) == 0 && strcmp(message, message2) == 0) {
                printf("Potential intrusion detected with repeated message from IP %s\n", ip);
            }
        }
    }
    
    // Check for brute force attacks
    for (i = 0; i < logCount; i++) {
        // Check for failed login attempts
        char* message = logEntries[i].message;
        if (strstr(message, "Invalid user") != NULL || strstr(message, "authentication failure") != NULL) {
            // Get IP address
            char* ipStart = strchr(message, '[') + 1;
            char* ipEnd = strchr(ipStart, ']');
            *ipEnd = '\0';
            char* ip = ipStart;
            
            // Check for repeated failed attempts from same IP
            int failCount = 0;
            
            for (j = i+1; j < logCount; j++) {
                char* message2 = logEntries[j].message;
                if (strstr(message2, "Invalid user") != NULL || strstr(message2, "authentication failure") != NULL) {
                    char* ipStart2 = strchr(message2, '[') + 1;
                    char* ipEnd2 = strchr(ipStart2, ']');
                    *ipEnd2 = '\0';
                    char* ip2 = ipStart2;
                    
                    if (strcmp(ip, ip2) == 0) {
                        failCount++;
                        
                        if (failCount >= 3) {
                            printf("Potential brute force attack detected from IP %s\n", ip);
                            break;
                        }
                    }
                }
            }
        }
    }
}

// Main function
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: ./ids <log file>\n");
        exit(1);
    }
    
    char* filename = argv[1];
    
    printf("Reading log file %s...\n", filename);
    readLogFile(filename);
    printf("Read %d log entries\n", logCount);
    
    printf("Detecting intrusions...\n");
    detectIntrusions();
    
    return 0;
}