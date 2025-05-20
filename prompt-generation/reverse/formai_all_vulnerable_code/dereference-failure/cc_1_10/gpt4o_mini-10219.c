//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_APS 50

typedef struct {
    char ssid[32];
    int signal_strength;
} access_point_t;

int fetch_signal_data(access_point_t aps[MAX_APS]) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char command[] = "nmcli -t -f SSID,SIGNAL dev wifi";

    // Open a pipeline to nmcli command
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Unable to run nmcli");
        return -1;
    }

    // Initialize access points count
    int ap_count = 0;

    // Parse the output of nmcli
    while (fgets(buffer, sizeof(buffer), fp) != NULL && ap_count < MAX_APS) {
        // Tokenize the string by ":"
        char *token = strtok(buffer, ":");
        strcpy(aps[ap_count].ssid, token);
        token = strtok(NULL, ":");
        if (token) {
            aps[ap_count].signal_strength = atoi(token);
            ap_count++;
        }
    }

    pclose(fp); // Close the pipe
    return ap_count;
}

void analyze_signal_strength(access_point_t aps[], int count) {
    printf("Analyzing Signal Strength...\n\n");
    
    // Display header
    printf("%-32s %-15s\n", "SSID", "Signal Strength (dBm)");
    printf("----------------------------------------------------------\n");

    // Sort access points by signal strength
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (aps[i].signal_strength < aps[j].signal_strength) {
                access_point_t temp = aps[i];
                aps[i] = aps[j];
                aps[j] = temp;
            }
        }
    }

    // Display sorted access points
    for (int i = 0; i < count; i++) {
        printf("%-32s %-15d\n", aps[i].ssid, aps[i].signal_strength);
    }
}

int main() {
    access_point_t aps[MAX_APS];
    int count = fetch_signal_data(aps);

    if (count < 0) {
        return EXIT_FAILURE; // Error occurred in data fetching
    }

    analyze_signal_strength(aps, count);
    return EXIT_SUCCESS;
}