//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

bool isValidIP(char *ipAddress);
void printUsage();
int scanNetwork(char *ipAddress);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printUsage();
        return -1;
    }

    char *ipAddress = argv[1];

    if(!isValidIP(ipAddress)) {
        printf("Invalid IP Address.\n");
        return -1;
    }

    printf("Scanning network %s...\n", ipAddress);
    int numDevices = scanNetwork(ipAddress);
    printf("%d devices found on network %s.\n", numDevices, ipAddress);

    return 0;
}

bool isValidIP(char *ipAddress) {
    // Split the string into 4 parts based on the periods
    char *part1 = strtok(ipAddress, ".");
    char *part2 = strtok(NULL, ".");
    char *part3 = strtok(NULL, ".");
    char *part4 = strtok(NULL, ".");

    // Check that all parts were successfully split and that they are all numbers between 0 and 255
    if(part1 == NULL || part2 == NULL || part3 == NULL || part4 == NULL) {
        return false;
    }

    char *endptr;
    long longPart1 = strtol(part1, &endptr, 10);
    long longPart2 = strtol(part2, &endptr, 10);
    long longPart3 = strtol(part3, &endptr, 10);
    long longPart4 = strtol(part4, &endptr, 10);

    if(longPart1 < 0 || longPart1 > 255 || 
        longPart2 < 0 || longPart2 > 255 || 
        longPart3 < 0 || longPart3 > 255 || 
        longPart4 < 0 || longPart4 > 255) {
        return false;
    }

    return true;
}

void printUsage() {
    printf("Usage: network-scanner [IP Address]\n");
}

int scanNetwork(char *ipAddress) {
    // Split the IP Address into 4 parts
    char *part1 = strtok(ipAddress, ".");
    char *part2 = strtok(NULL, ".");
    char *part3 = strtok(NULL, ".");
    char *part4 = strtok(NULL, ".");

    // Create a buffer to hold the command to execute
    char buffer[BUFFER_SIZE];

    // Loop through all possible combinations of the last 8 bits
    int numDevices = 0;
    for(int i = 0; i <= 255; i++) {
        sprintf(buffer, "ping %s.%s.%s.%d -c 1 -W 1", part1, part2, part3, i);

        // Execute the ping command and capture the output
        FILE *pingResult = popen(buffer, "r");
        char result[BUFFER_SIZE];
        fgets(result, BUFFER_SIZE, pingResult);

        /* Check if the ping was successful by checking if the output contains "1 received"
         * The exact wording may differ depending on the system, so the check should be case insensitive */
        char *response = strcasestr(result, "1 received");
        if(response != NULL) {
            printf("Device found at %s.%s.%s.%d\n", part1, part2, part3, i);
            numDevices++;
        }

        pclose(pingResult);
    }

    return numDevices;
}