//FormAI DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <string.h>

int main(void) {
    // Open and read log file
    FILE *logFile = fopen("server.log", "r");
    if (!logFile) {
        printf("Error: Could not open log file!");
        return -1;
    }
    
    // Initialize variables and arrays for parsing
    char line[1000];
    char *tokens[10];
    char *dateTime;
    char *ipAddress;
    char *requestType;
    char *url;
    char *responseCode;
    int minutes[60] = {0};
    int totalRequests = 0;
    int totalGetRequests = 0;
    int totalPostRequests = 0;
    int totalSuccessfulRequests = 0;
    int totalUnsuccessfulRequests = 0;
    int uniqueIps = 0;
    
    while (fgets(line, sizeof(line), logFile)) {
        // Split line into tokens based on spaces
        int tokenCount = 0;
        tokens[tokenCount] = strtok(line, " ");
        while (tokens[tokenCount]) {
            tokenCount++;
            tokens[tokenCount] = strtok(NULL, " ");
        }
        
        // Parse tokens to extract relevant information
        dateTime = tokens[0];
        ipAddress = tokens[3];
        requestType = tokens[5];
        url = tokens[6];
        responseCode = tokens[8];
        
        // Update relevant variables and arrays based on parsed information
        int hour = atoi(strtok(dateTime+13, ":"));
        int minute = atoi(strtok(NULL, ":"));;
        minutes[minute]++;
        totalRequests++;
        if (strcmp(requestType, "GET") == 0) {
            totalGetRequests++;
        } else if (strcmp(requestType, "POST") == 0) {
            totalPostRequests++;
        }
        if (strcmp(responseCode, "200") == 0) {
            totalSuccessfulRequests++;
        } else {
            totalUnsuccessfulRequests++;
        }
        uniqueIps++;
    }
    
    // Print analysis results
    printf("Total requests: %d\n", totalRequests);
    printf("Total GET requests: %d\n", totalGetRequests);
    printf("Total POST requests: %d\n", totalPostRequests);
    printf("Total successful requests: %d\n", totalSuccessfulRequests);
    printf("Total unsuccessful requests: %d\n", totalUnsuccessfulRequests);
    printf("Unique IP addresses: %d\n", uniqueIps);
    printf("Requests per minute:\n");
    for (int i = 0; i < 60; i++) {
        printf("Minute %d: %d requests\n", i, minutes[i]);
    }
    
    // Close log file
    fclose(logFile);
    
    return 0;
}