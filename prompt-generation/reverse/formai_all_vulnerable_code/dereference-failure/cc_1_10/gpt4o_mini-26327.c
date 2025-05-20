//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void print_networks(char *scan_results) {
    char *line = strtok(scan_results, "\n");
    printf("Available Wireless Networks:\n");
    printf("------------------------------------------------\n");
    
    while (line != NULL) {
        if (strstr(line, "ESSID:") != NULL) {
            char ssid[50];
            sscanf(line, "            ESSID:\"%[^\"]\"", ssid);
            if (strlen(ssid) > 0) {
                printf("SSID: %-30s\n", ssid);
            }
        }
        line = strtok(NULL, "\n");
    }

    printf("------------------------------------------------\n");
}

void scan_networks() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    
    // This command will trigger a wireless scan
    fp = popen("iwlist wlan0 scan", "r");
    if (fp == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

    // Read the output a line at a time - output it.
    char *scan_results = malloc(BUFFER_SIZE * sizeof(char));
    scan_results[0] = '\0'; // Initialize an empty string
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        strcat(scan_results, buffer); // Append output lines to scan_results
    }

    // Print scanned networks
    print_networks(scan_results);
    
    // Clean up
    free(scan_results);
    pclose(fp);
}

int main() {
    printf("~~~ Welcome to the Wireless Network Explorer ~~~\n");
    printf("Starting the heroic quest to find available networks...\n");
    printf("Hold on tight, we are scanning the airwaves!\n");
    
    scan_networks();
    
    printf("Scanning completed! Now you can enjoy the wireless wonders.\n");
   
    return 0;
}