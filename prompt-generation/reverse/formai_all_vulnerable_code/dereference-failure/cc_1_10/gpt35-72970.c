//FormAI DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 255
#define VALID_IP_SEGMENT 0xFF

// Struct to represent an IP address
typedef struct {
    int segment1;
    int segment2;
    int segment3;
    int segment4;
} IP_ADDRESS;

// Helper function to check if a given string is a valid IP address segment
int is_valid_segment(char *segment) {
    int num = atoi(segment);
    return num >= 0 && num <= VALID_IP_SEGMENT;
}

// Helper function to parse a string into an IP address struct
int string_to_ip(char *str, IP_ADDRESS *ip_address) {
    char *segment;

    // Parse the first segment
    segment = strtok(str, ".");
    if (!is_valid_segment(segment)) {
        return 0;
    }
    ip_address->segment1 = atoi(segment);

    // Parse the second segment
    segment = strtok(NULL, ".");
    if (!is_valid_segment(segment)) {
        return 0;
    }
    ip_address->segment2 = atoi(segment);

    // Parse the third segment
    segment = strtok(NULL, ".");
    if (!is_valid_segment(segment)) {
        return 0;
    }
    ip_address->segment3 = atoi(segment);

    // Parse the fourth segment
    segment = strtok(NULL, ".");
    if (!is_valid_segment(segment)) {
        return 0;
    }
    ip_address->segment4 = atoi(segment);

    return 1;
}

int main(int argc, char **argv) {
    char line[MAX_LINE_SIZE];
    int count = 0;

    // Loop through each line of the log file
    while (fgets(line, MAX_LINE_SIZE, stdin)) {
        IP_ADDRESS ip_address;

        // Split the line into segments
        char *host = strtok(line, " ");
        strtok(NULL, " ");
        char *ip_str = strtok(NULL, " ");

        // Parse the IP address from the string
        if (!string_to_ip(ip_str, &ip_address)) {
            continue;
        }

        // Print out the IP address and host name
        printf("%d.%d.%d.%d %s\n", ip_address.segment1, ip_address.segment2,
               ip_address.segment3, ip_address.segment4, host);

        count++;
    }

    printf("Total number of valid log entries: %d\n", count);

    return 0;
}