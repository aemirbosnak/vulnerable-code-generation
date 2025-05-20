//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printUsage();
int analyzeSignalStrength(char* interface, int samples);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printUsage();
        return 1;
    }

    char* interface = argv[1];
    int samples = atoi(argv[2]);

    analyzeSignalStrength(interface, samples);

    return 0;
}

void printUsage() {
    printf("Usage: wifi_analyzer [interface] [samples]\n");
    printf("\tinterface - the name of the wireless interface to analyze\n");
    printf("\tsamples - the number of samples to collect\n");
}

int analyzeSignalStrength(char* interface, int samples) {
    printf("Analyzing signal strength for interface %s...\n", interface);

    int totalSignalStrength = 0;

    for (int i = 0; i < samples; i++) {
        char command[100];
        sprintf(command, "iwconfig %s | grep Signal | awk '{print $4}'", interface);

        FILE* fp = popen(command, "r");
        if (fp == NULL) {
            printf("Error executing command!\n");
            return 1;
        }

        char signalStrength[10];
        fgets(signalStrength, 10, fp);
        pclose(fp);

        int signalStrengthValue = atoi(signalStrength);

        printf("Sample %d: Signal strength = %d dBm\n", i+1, signalStrengthValue);

        totalSignalStrength += signalStrengthValue;

        sleep(1);
    }

    int averageSignalStrength = totalSignalStrength / samples;

    printf("\nAnalysis complete.\n");
    printf("Average signal strength over %d samples = %d dBm\n", samples, averageSignalStrength);

    return 0;
}