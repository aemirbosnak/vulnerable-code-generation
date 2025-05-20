//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 32
#define MAX_SCAN_RESULTS 50

// Struct for holding scan results
typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} scan_result_t;

// Function for sorting scan results by signal strength
int cmp_scan_results(const void *a, const void *b) {
    int a_strength = ((scan_result_t*)a)->signal_strength;
    int b_strength = ((scan_result_t*)b)->signal_strength;

    return b_strength - a_strength;
}

int main(int argc, char **argv) {
    // Array for holding scan results
    scan_result_t scan_results[MAX_SCAN_RESULTS];
    
    // Loop through all command line arguments (SSIDs to scan)
    for(int i = 1; i < argc; i++) {
        // Command to scan SSID and get signal strength
        char command[64];
        snprintf(command, 64, "iwconfig wlan0 essid %s | grep Signal | cut -d '=' -f 3 | cut -d ' ' -f 1", argv[i]);

        // Open pipe to execute command
        FILE *pipe = popen(command, "r");

        // Read output from command
        char signal_strength_str[8];
        fgets(signal_strength_str, 8, pipe);

        // Close pipe
        pclose(pipe);

        // Convert signal strength string to int
        int signal_strength = atoi(signal_strength_str);

        // Copy SSID and signal strength to scan_results array
        strncpy(scan_results[i-1].ssid, argv[i], MAX_SSID_LENGTH);
        scan_results[i-1].signal_strength = signal_strength;
    }

    // Sort scan results by signal strength (descending order)
    qsort(scan_results, argc-1, sizeof(scan_result_t), cmp_scan_results);

    // Print sorted scan results
    printf("SSID                    Signal Strength\n");
    for(int i = 0; i < argc-1; i++) {
        printf("%-24s %d dBm\n", scan_results[i].ssid, scan_results[i].signal_strength);
    }

    return 0;
}