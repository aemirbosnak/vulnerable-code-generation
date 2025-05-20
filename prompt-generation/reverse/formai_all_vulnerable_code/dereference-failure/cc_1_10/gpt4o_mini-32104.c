//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// Function to initialize the Wi-Fi signal strength analyzer
void initAnalyzer() {
    printf("Initializing the Wi-Fi Signal Strength Analyzer...\n");
    sleep(2);
    printf("Analyzer Initialized!\n");
}

// Function to get Wi-Fi signal strength
int getSignalStrength() {
    FILE *fp;
    char buffer[1024];
    int signalStrength = -1;

    // Execute the command to fetch the Wi-Fi status and signal strength info
    fp = popen("iwconfig 2>&1", "r");
    if (fp == NULL) {
        printf("Failed to run command: %s\n", strerror(errno));
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Look for 'Signal level=' in the output
        char *signalStr = strstr(buffer, "Signal level=");
        if (signalStr) {
            // Parsing the signal strength from the output
            sscanf(signalStr, "Signal level=%d", &signalStrength);
        }
    }

    pclose(fp);
    return signalStrength;
}

// Function to display the signal strength
void displaySignalStrength(int strength) {
    printf("Current Wi-Fi Signal Strength: %d dBm\n", strength);
    if (strength >= -50) {
        printf("☀️ Excellent signal strength!\n");
    } else if (strength >= -70) {
        printf("🌟 Good signal strength!\n");
    } else if (strength >= -80) {
        printf("⚠️ Fair signal strength...\n");
    } else {
        printf("🚨 Poor signal strength! Please check your connection.\n");
    }
}

// Function to analyze and log results
void analyzeAndLog(int strength) {
    FILE *logFile = fopen("wifi_signal_log.txt", "a");
    if (logFile == NULL) {
        printf("Failed to open log file: %s\n", strerror(errno));
        return;
    }

    const char *strengthStatus;
    if (strength >= -50) {
        strengthStatus = "Excellent";
    } else if (strength >= -70) {
        strengthStatus = "Good";
    } else if (strength >= -80) {
        strengthStatus = "Fair";
    } else {
        strengthStatus = "Poor";
    }

    fprintf(logFile, "Signal Strength: %d dBm - Status: %s\n", strength, strengthStatus);
    fclose(logFile);
    printf("Results logged to wifi_signal_log.txt\n");
}

// Main function
int main() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");

    initAnalyzer();
    int signalStrength = getSignalStrength();

    // Handle case if signal strength fetch fails
    if (signalStrength == -1) {
        printf("⚠️ Unable to retrieve signal strength. Please check your Wi-Fi adapter.\n");
        return 1;
    }

    displaySignalStrength(signalStrength);
    analyzeAndLog(signalStrength);

    // Infinite loop to continually check signal strength
    char userResponse;
    while (1) {
        printf("Do you want to refresh the signal strength? (y/n): ");
        scanf(" %c", &userResponse);

        if (userResponse == 'y' || userResponse == 'Y') {
            signalStrength = getSignalStrength();
            if (signalStrength == -1) {
                printf("⚠️ Unable to retrieve signal strength.\n");
                break;
            }
            displaySignalStrength(signalStrength);
            analyzeAndLog(signalStrength);
        } else if (userResponse == 'n' || userResponse == 'N') {
            printf("Exiting the analyzer. Stay connected! 😊\n");
            break;
        } else {
            printf("Invalid input! Please try again.\n");
        }
    }

    return 0;
}