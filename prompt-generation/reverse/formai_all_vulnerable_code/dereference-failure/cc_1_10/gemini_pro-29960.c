//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

// Function to get the signal strength of a Wi-Fi network.
int get_signal_strength(char *essid) {
    // Open the iwconfig file.
    FILE *fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the file line by line.
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Find the line that contains the ESSID.
        if (strstr(line, essid) != NULL) {
            // Get the signal strength from the line.
            int signal_strength = atoi(strtok(line, " "));

            // Return the signal strength.
            return signal_strength;
        }
    }

    // Close the file.
    fclose(fp);

    // Return -1 if the ESSID was not found.
    return -1;
}

// Function to print the signal strength of a Wi-Fi network.
void print_signal_strength(char *essid) {
    // Get the signal strength.
    int signal_strength = get_signal_strength(essid);

    // Print the signal strength.
    printf("Signal strength of %s: %d dBm\n", essid, signal_strength);
}

// Function to main.
int main(int argc, char *argv[]) {
    // Check if the user has provided an ESSID.
    if (argc < 2) {
        printf("Usage: %s <essid>\n", argv[0]);
        return -1;
    }

    // Get the ESSID from the command line.
    char *essid = argv[1];

    // Print the signal strength of the Wi-Fi network.
    print_signal_strength(essid);

    return 0;
}