//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: decentralized
/* C Wireless Network Scanner */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

char scan_command[MAX_BUFFER_SIZE] = "sudo iwlist wlan0 scan | grep ESSID"; // Command to scan for wireless networks

int main() {
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    system("clear");

    printf("Scanning for wireless networks...\n\n");

    fp = popen(scan_command, "r"); // Execute scan command

    if (fp == NULL) {
        printf("Failed to execute command.\n");
        exit(1);
    }

    // Read output from command
    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "ESSID:") != NULL) {
            // Extract name of network
            char *start = strstr(line, "\"");
            char *end = strstr(start+1, "\"");
            int name_length = end - start - 1;
            char network_name[name_length];
            strncpy(network_name, start+1, name_length);
            network_name[name_length] = '\0';

            // Print network name
            printf("Network: %s\n", network_name);
        }
    }

    pclose(fp);
    if (line)
        free(line);
    exit(0);
}