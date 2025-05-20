//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

// Define the maximum length of the SSID and BSSID strings
#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 18

// Define the maximum number of access points to be scanned
#define MAX_ACCESS_POINTS 50

// Define the minimum and maximum signal strength values to be used in the calculations
#define MIN_SIGNAL_STRENGTH -100
#define MAX_SIGNAL_STRENGTH -50

// Define the number of signal strength levels to be used in the calculations
#define SIGNAL_STRENGTH_LEVELS 10

// Define the array to hold the access point data
typedef struct access_point {
    char ssid[MAX_SSID_LENGTH];
    char bssid[MAX_BSSID_LENGTH];
    int signal_strength;
} access_point;

// Function to scan for available WiFi access points and store data in the array
int scan_wifi(access_point *ap_data, int max_aps) {
    // Use the "iw" command to scan for available access points
    char command[100] = "iw dev wlan0 scan | egrep 'SSID|signal' | sed 's/://g'";
    FILE *pipe = popen(command, "r");
    
    if (!pipe) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return -1;
    }
    
    char line[100];
    int count = 0;
    
    // Read the output of the command line by line
    while (fgets(line, sizeof(line), pipe)) {
        // If the line contains the SSID, copy it into the data array
        if (strstr(line, "SSID")) {
            char *ssid = line + strlen("SSID")+1;
            strncpy(ap_data[count].ssid, ssid, strlen(ssid)-1);
        }
        // If the line contains the BSSID, copy it into the data array
        else if (strstr(line, "BSSID")) {
            char *bssid = line + strlen("BSSID")+1;
            strncpy(ap_data[count].bssid, bssid, strlen(bssid)-1);
        }
        // If the line contains the signal strength, convert it to an integer and store it in the data array
        else if (strstr(line, "signal")) {
            char *signal_str = line + strlen("signal")+1;
            int signal_strength = strtol(signal_str, NULL, 10);
            ap_data[count].signal_strength = signal_strength;
            
            // Increment the counter
            count++;
            
            // If we have reached the maximum number of access points, break out of the loop
            if (count == max_aps) {
                break;
            }
        }
    }
    
    pclose(pipe);
    
    return count;
}

int main(void) {
    // Define the array to hold the access point data
    access_point ap_data[MAX_ACCESS_POINTS];
    
    // Scan for available WiFi access points and store the data in the array
    int num_aps = scan_wifi(ap_data, MAX_ACCESS_POINTS);
    
    // If no access points were found, print an error message and exit
    if (num_aps == 0) {
        fprintf(stderr, "Error: No WiFi access points found.\n");
        exit(1);
    }
    
    // Define the array to hold the signal strength levels
    int signal_strength_levels[SIGNAL_STRENGTH_LEVELS] = {0};
    
    // Calculate the range of signal strength values to be used in the analysis
    float signal_strength_range = (float) (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH) / SIGNAL_STRENGTH_LEVELS;
    
    // Loop through the access points and calculate the signal strength level for each one
    for (int i = 0; i < num_aps; i++) {
        // Calculate the signal strength level based on the access point's signal strength
        int signal_strength_level = (int) ((float) (ap_data[i].signal_strength - MIN_SIGNAL_STRENGTH) / signal_strength_range);
        
        // Increment the count for that signal strength level
        signal_strength_levels[signal_strength_level]++;
    }
    
    // Print the results
    for (int i = 0; i < SIGNAL_STRENGTH_LEVELS; i++) {
        printf("%d%%\t", signal_strength_levels[i] * 100 / num_aps);
        
        for (int j = 0; j < signal_strength_levels[i]; j++) {
            printf("#");
        }
        
        printf("\n");
    }
    
    return 0;
}