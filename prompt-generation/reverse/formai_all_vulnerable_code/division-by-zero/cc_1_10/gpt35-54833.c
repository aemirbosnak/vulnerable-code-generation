//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Constants
#define MAX_STRING_LENGTH 100
#define MAX_WIFI_SIGNALS 10

// Struct for Wi-Fi Signal Data
typedef struct {
    char ssid[MAX_STRING_LENGTH];
    int signalStrength;
} WifiSignal;

// Function Prototypes
void inputWifiSignalData(WifiSignal* signals, int numSignals);
void printWifiSignalData(WifiSignal* signals, int numSignals);
int calculateAverageSignalStrength(WifiSignal* signals, int numSignals);
void printSignalStrengthAnalysis(int avgSignalStrength);

// Main function
int main() {
    // Declare Variables
    int numSignals = 0;
    WifiSignal signals[MAX_WIFI_SIGNALS];
    int avgSignalStrength = 0;

    // Input Wi-Fi Signal Data
    printf("Enter the number of Wi-Fi signals: ");
    scanf("%d", &numSignals);
    inputWifiSignalData(signals, numSignals);

    // Print Wi-Fi Signal Data
    printf("\nWi-Fi Signals:\n");
    printWifiSignalData(signals, numSignals);

    // Calculate Average Signal Strength
    avgSignalStrength = calculateAverageSignalStrength(signals, numSignals);

    // Print Signal Strength Analysis
    printf("\nSignal Strength Analysis:\n");
    printSignalStrengthAnalysis(avgSignalStrength);

    return 0;
}

// Function to input Wi-Fi Signal Data
void inputWifiSignalData(WifiSignal* signals, int numSignals) {
    for (int i = 0; i < numSignals; i++) {
        printf("Enter the SSID of Wi-Fi signal #%d: ", i+1);
        scanf("%s", signals[i].ssid);
        printf("Enter the signal strength of Wi-Fi signal #%d: ", i+1);
        scanf("%d", &signals[i].signalStrength);
    }
}

// Function to print Wi-Fi Signal Data
void printWifiSignalData(WifiSignal* signals, int numSignals) {
    for (int i = 0; i < numSignals; i++) {
        printf("SSID: %s, Signal Strength: %d\n", signals[i].ssid, signals[i].signalStrength);
    }
}

// Function to calculate Average Signal Strength
int calculateAverageSignalStrength(WifiSignal* signals, int numSignals) {
    int totalSignalStrength = 0;
    for (int i = 0; i < numSignals; i++) {
        totalSignalStrength += signals[i].signalStrength;
    }
    return totalSignalStrength / numSignals;
}

// Function to print Signal Strength Analysis
void printSignalStrengthAnalysis(int avgSignalStrength) {
    printf("The average Wi-Fi signal strength is %d dBm.\n", avgSignalStrength);
    if (avgSignalStrength >= -30) {
        printf("The signal strength is excellent.\n");
    } else if (avgSignalStrength >= -67) {
        printf("The signal strength is good.\n");
    } else if (avgSignalStrength >= -70) {
        printf("The signal strength is fair.\n");
    } else {
        printf("The signal strength is poor.\n");
    }
}