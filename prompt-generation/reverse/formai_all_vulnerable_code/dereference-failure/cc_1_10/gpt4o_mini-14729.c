//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define COMMAND "sudo iwlist wlan0 scan"

void scan_networks() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char *token;
    int network_count = 0;

    // Open the command for reading
    if ((fp = popen(COMMAND, "r")) == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        exit(1);
    }

    printf("Scanning for wireless networks...\n\n");

    // Read the output a line at a time
    while (fgets(buffer, sizeof(buffer) - 1, fp) != NULL) {
        // Searching for SSID
        if (strstr(buffer, "ESSID:")) {
            token = strtok(buffer, ":");
            if (token != NULL) {
                token = strtok(NULL, "\"");
                if (token != NULL) {
                    printf("Network %d: SSID: %s\n", ++network_count, token);
                }
            }
        }

        // Searching for Signal Level
        if (strstr(buffer, "Signal level")) {
            token = strtok(buffer, " ");
            while (token != NULL) {
                if (strstr(token, "level")) {
                    printf("Signal Quality: %s\n", token);
                    break;
                }
                token = strtok(NULL, " ");
            }
        }
    }

    // Close the command stream
    if (pclose(fp) == -1) {
        fprintf(stderr, "Error closing command stream: %s\n", strerror(errno));
    }

    if (network_count == 0) {
        printf("No wireless networks found.\n");
    }
}

int main(int argc, char *argv[]) {
    if (geteuid() != 0) {
        fprintf(stderr, "This program must be run as root or with sudo privileges.\n");
        return 1;
    }

    scan_networks();

    return 0;
}