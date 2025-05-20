//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define WIFI_SCAN_CMD "nmcli -t -f IN-USE,SSID,SIGNAL dev wifi"
#define MAX_DEVICES 100

typedef struct {
    char ssid[100];   // Wi-Fi SSID
    int signal;       // Signal strength
    int in_use;       // If the device is currently connected
} WifiDevice;

// Function to clear previous results
void clearScreen() {
    printf("\033[H\033[J");
}

// Function to print the header
void printHeader() {
    printf("+--------------------------------------------------+\n");
    printf("| Wi-Fi Signal Strength Analyzer                    |\n");
    printf("+--------------------------------------------------+\n");
    printf("| In-Use | SSID                       | Signal (dBm) |\n");
    printf("+--------------------------------------------------+\n");
}

// Function to execute the command and parse the output
int scanWifi(WifiDevice *devices) {
    FILE *fp;
    char buffer[256];
    int count = 0;

    // Execute command to scan Wi-Fi networks
    fp = popen(WIFI_SCAN_CMD, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        return -1;
    }

    // Read and parse the output
    while (fgets(buffer, sizeof(buffer), fp) != NULL && count < MAX_DEVICES) {
        sscanf(buffer, "%1s %99[^:]:%d", (devices[count].in_use ? ">" : " "), devices[count].ssid, &devices[count].signal);
        count++;
    }

    pclose(fp);
    return count; // return the number of devices found
}

// Function to handle interruptions
void handleSignal(int signal) {
    if (signal == SIGINT) {
        printf("\nExiting Wi-Fi Signal Strength Analyzer... Bye!\n");
        exit(0);
    }
}

int main() {
    signal(SIGINT, handleSignal); // Handle Ctrl+C signal

    WifiDevice devices[MAX_DEVICES];
    int device_count;

    while (1) {
        clearScreen();
        device_count = scanWifi(devices);
        
        if (device_count < 0) {
            fprintf(stderr, "Error scanning Wi-Fi devices!\n");
            return 1;
        }
        
        printHeader();
        
        for (int i = 0; i < device_count; i++) {
            printf("| %-6s | %-25s | %-12d |\n",
                   devices[i].in_use ? "Yes" : "No", 
                   devices[i].ssid, 
                   devices[i].signal);
        }
        printf("+--------------------------------------------------+\n");

        printf("Press Ctrl+C to exit...\n");
        sleep(3); // Refresh every 3 seconds
    }
    
    return 0;
}