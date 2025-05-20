//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMAND_SIZE 256
#define BUFFER_SIZE 1024

void checkQoS(const char *hostname) {
    char command[COMMAND_SIZE];
    snprintf(command, sizeof(command), "ping -c 5 %s", hostname);  // Run ping command with 5 packets

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int packetLoss = 0;
    float averageRTT = 0.0;
    int rttCount = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Check for packet loss
        if (strstr(buffer, "packet loss")) {
            char *ptr = strchr(buffer, '%');  // Find percentage sign
            if (ptr != NULL) {
                packetLoss = atoi(ptr - 3); // Extract packet loss percentage
            }
        }

        // Check for average RTT
        if (strstr(buffer, "avg")) {
            char *ptr = strchr(buffer, '/'); // Find first '/'

            // Skip first two values
            for (int i = 0; i < 2; ++i) {
                ptr = strchr(ptr + 1, '/');
            }

            if (ptr != NULL) {
                averageRTT = atof(ptr + 1); // The third value is the average RTT
                rttCount++;
            }
        }
    }

    pclose(fp);

    // Print result
    printf("Network QoS Check for %s\n", hostname);
    printf("------------------------\n");
    printf("Packet Loss: %d%%\n", packetLoss);
    if (rttCount > 0) {
        printf("Average Round-Trip Time: %.2f ms\n", averageRTT);
    } else {
        printf("Average Round-Trip Time: Not Available\n");
    }
}

int main() {
    char hostname[100];

    printf("Welcome to the Network Quality of Service (QoS) Monitor!\n");
    printf("Please enter the hostname or IP address to check QoS: ");
    scanf("%99s", hostname);  // Read input safely

    checkQoS(hostname);

    return 0;
}