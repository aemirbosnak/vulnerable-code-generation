//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Color definitions
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

// Signal strength threshold values
#define WEAK_SIGNAL -80
#define GOOD_SIGNAL -70
#define STRONG_SIGNAL -60

// Function to get the signal strength of a Wi-Fi network
int get_signal_strength(char *ssid) {
    // Open a file stream to read the Wi-Fi signal strength information
    FILE *fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the header line
    char line[1024];
    fgets(line, sizeof(line), fp);

    // Read each line of the file and find the signal strength for the given SSID
    while (fgets(line, sizeof(line), fp)) {
        // Split the line into tokens
        char *tokens[8];
        int i = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            tokens[i++] = token;
            token = strtok(NULL, " ");
        }

        // Check if the SSID matches the given SSID
        if (strcmp(tokens[0], ssid) == 0) {
            // Return the signal strength
            return atoi(tokens[3]);
        }
    }

    // SSID not found
    return -1;
}

// Function to print the signal strength of a Wi-Fi network
void print_signal_strength(char *ssid, int signal_strength) {
    // Determine the signal strength level
    char *level;
    if (signal_strength < WEAK_SIGNAL) {
        level = RED "Weak" RESET;
    } else if (signal_strength < GOOD_SIGNAL) {
        level = YELLOW "Good" RESET;
    } else {
        level = GREEN "Strong" RESET;
    }

    // Print the signal strength
    printf("%s: %s (%d dBm)\n", ssid, level, signal_strength);
}

int main() {
    // Get the list of Wi-Fi networks
    FILE *fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the header line
    char line[1024];
    fgets(line, sizeof(line), fp);

    // Read each line of the file and print the signal strength for each network
    while (fgets(line, sizeof(line), fp)) {
        // Split the line into tokens
        char *tokens[8];
        int i = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            tokens[i++] = token;
            token = strtok(NULL, " ");
        }

        // Get the signal strength
        int signal_strength = atoi(tokens[3]);

        // Print the signal strength
        print_signal_strength(tokens[0], signal_strength);
    }

    // Close the file
    fclose(fp);

    return EXIT_SUCCESS;
}