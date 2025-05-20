//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of access points that can be scanned
#define MAX_APS 10

// Define the maximum length of an access point's name
#define MAX_AP_NAME_LENGTH 32

// Define the maximum length of an access point's MAC address
#define MAX_AP_MAC_ADDRESS_LENGTH 18

// Define the maximum number of signal strength measurements that can be taken
#define MAX_MEASUREMENTS 10

// Define the minimum signal strength that is considered to be acceptable
#define MIN_ACCEPTABLE_SIGNAL_STRENGTH -80

// Define the maximum signal strength that is considered to be excellent
#define MAX_EXCELLENT_SIGNAL_STRENGTH -50

// Define the data structure that will be used to store information about each access point
typedef struct {
    char name[MAX_AP_NAME_LENGTH];
    char mac_address[MAX_AP_MAC_ADDRESS_LENGTH];
    int signal_strength;
} access_point;

// Define the function that will be used to scan for access points
int scan_for_access_points(access_point *aps) {
    // Initialize the number of access points found to 0
    int num_aps = 0;

    // Get a list of all the available access points
    FILE *fp = popen("iwlist scan | grep -A 1 'Cell'", "r");
    if (fp == NULL) {
        perror("popen");
        return -1;
    }

    // Read each line of the output from the iwlist command
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the line to get the access point's name, MAC address, and signal strength
        char *name = strtok(line, " ");
        char *mac_address = strtok(NULL, " ");
        char *signal_strength = strtok(NULL, " ");

        // Convert the signal strength from a string to an integer
        int signal_strength_int = atoi(signal_strength);

        // Store the access point's information in the array of access points
        strcpy(aps[num_aps].name, name);
        strcpy(aps[num_aps].mac_address, mac_address);
        aps[num_aps].signal_strength = signal_strength_int;

        // Increment the number of access points found
        num_aps++;
    }

    // Close the file
    pclose(fp);

    // Return the number of access points found
    return num_aps;
}

// Define the function that will be used to measure the signal strength of an access point
int measure_signal_strength(access_point *ap) {
    // Initialize the signal strength to 0
    int signal_strength = 0;

    // Get the signal strength from the iwconfig command
    FILE *fp = popen("iwconfig wlan0 | grep Signal level", "r");
    if (fp == NULL) {
        perror("popen");
        return -1;
    }

    // Read the line of output from the iwconfig command
    char line[1024];
    if (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the line to get the signal strength
        char *signal_strength_str = strtok(line, ":");
        signal_strength = atoi(signal_strength_str);
    }

    // Close the file
    pclose(fp);

    // Return the signal strength
    return signal_strength;
}

// Define the main function
int main() {
    // Define an array of access points
    access_point aps[MAX_APS];

    // Scan for access points
    int num_aps = scan_for_access_points(aps);
    if (num_aps == -1) {
        return 1;
    }

    // Print the list of access points
    printf("Access Points:\n");
    for (int i = 0; i < num_aps; i++) {
        printf("  %s (%s)\n", aps[i].name, aps[i].mac_address);
    }

    // Measure the signal strength of each access point
    for (int i = 0; i < num_aps; i++) {
        aps[i].signal_strength = measure_signal_strength(&aps[i]);
    }

    // Print the signal strength of each access point
    printf("Signal Strengths:\n");
    for (int i = 0; i < num_aps; i++) {
        printf("  %s (%s): %d dBm\n", aps[i].name, aps[i].mac_address, aps[i].signal_strength);
    }

    // Find the access point with the strongest signal strength
    int max_signal_strength = MIN_ACCEPTABLE_SIGNAL_STRENGTH;
    access_point *strongest_ap = NULL;
    for (int i = 0; i < num_aps; i++) {
        if (aps[i].signal_strength > max_signal_strength) {
            max_signal_strength = aps[i].signal_strength;
            strongest_ap = &aps[i];
        }
    }

    // Print the access point with the strongest signal strength
    printf("Strongest Access Point:\n");
    printf("  %s (%s): %d dBm\n", strongest_ap->name, strongest_ap->mac_address, strongest_ap->signal_strength);

    return 0;
}