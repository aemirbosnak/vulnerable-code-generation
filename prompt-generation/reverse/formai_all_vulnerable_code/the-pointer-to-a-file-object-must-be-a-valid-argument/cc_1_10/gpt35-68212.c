//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for log details
struct LogDetails {
    char logType[10];
    char ipAddress[20];
    char message[100];
};

// Function to check if given IP address is blacklisted
int isBlacklisted(char ipAddress[]) {
    FILE *fp;
    char buffer[100];

    // Open the file containing blacklisted IP addresses
    fp = fopen("blacklist.txt", "r");

    // Iterate through each line of the file
    while (fgets(buffer, 100, fp) != NULL) {
        // Remove newline character from the end of the line
        strtok(buffer, "\n");

        // Compare the IP address with the line read from the file
        if (strcmp(ipAddress, buffer) == 0) {
            return 1; // Return 1 if IP is blacklisted
        }
    }

    // If IP is not found in the file, return 0
    return 0;
}

int main() {
    char log[100];
    struct LogDetails logDetails;

    printf("Enter log details (Log Type, IP Address, Message): ");
    fgets(log, 100, stdin);

    // Separate the log details using comma delimiter
    char *logType = strtok(log, ",");
    char *ipAddress = strtok(NULL, ",");
    char *message = strtok(NULL, ",");

    // Remove any leading or trailing whitespace
    strcpy(logType, logType + strspn(logType, " \t"));
    strcpy(ipAddress, ipAddress + strspn(ipAddress, " \t"));
    strcpy(message, message + strspn(message, " \t"));

    // Copy the log details to structure
    strcpy(logDetails.logType, logType);
    strcpy(logDetails.ipAddress, ipAddress);
    strcpy(logDetails.message, message);

    // Call function to check if IP is blacklisted
    if (isBlacklisted(logDetails.ipAddress)) {
        printf("Intrusion detected!\n");
        printf("Log Type: %s\n", logDetails.logType);
        printf("IP Address: %s\n", logDetails.ipAddress);
        printf("Message: %s\n", logDetails.message);
    }
    else {
        printf("No intrusion detected.\n");
    }

    return 0;
}