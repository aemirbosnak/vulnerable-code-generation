//FormAI DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_LOGS 1000000 // Maximum number of logs that can be analyzed
#define MAX_IP_LENGTH 20 // Maximum length of an IP address string

// Function to analyze the logs and generate results
void analyzeLogs(char* filePath) {
    printf("Analyzing logs from file: %s\n", filePath);
    
    // Open the log file for reading
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("ERROR: Could not open log file\n");
        return;
    }
    
    // Variables to store the log data
    char logLine[200];
    char ipAddresses[MAX_LOGS][MAX_IP_LENGTH];
    int numRequests[MAX_LOGS];
    int numLogs = 0;
    
    // Parse the log file line by line
    while (fgets(logLine, sizeof(logLine), file) != NULL) {
        // Extract the IP address from the log line
        char* ipAddressStart = strchr(logLine, '[') + 1;
        char* ipAddressEnd = strchr(ipAddressStart, ']');
        int ipAddressLength = ipAddressEnd - ipAddressStart;
        char ipAddress[MAX_IP_LENGTH];
        strncpy(ipAddress, ipAddressStart, ipAddressLength);
        ipAddress[ipAddressLength] = '\0';
        
        // Check if this IP address has already been seen in the logs
        int ipIndex = -1;
        for (int i = 0; i < numLogs; i++) {
            if (strcmp(ipAddresses[i], ipAddress) == 0) {
                ipIndex = i;
                break;
            }
        }
        
        // Update the log count for this IP address
        if (ipIndex == -1) {
            strcpy(ipAddresses[numLogs], ipAddress);
            numRequests[numLogs] = 1;
            numLogs++;
        } else {
            numRequests[ipIndex]++;
        }
    }
    
    // Close the log file
    fclose(file);
    
    // Print the results
    printf("Number of unique IP addresses in logs: %d\n", numLogs);
    printf("IP address\t\t\tNumber of requests\n");
    for (int i = 0; i < numLogs; i++) {
        printf("%-20s\t\t%d\n", ipAddresses[i], numRequests[i]);
    }
}

int main() {
    char* filePath = "sample_logs.txt";
    analyzeLogs(filePath);
    return 0;
}