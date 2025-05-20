//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBar(int barLength, int strength) {
    printf("%4d |", strength);
    for(int i = 0; i < barLength; i++) {
        if(i < strength) printf("█ ");
        else printf("  ");
    }
    printf("|\n");
}

void analyzeSignalStrength() {
    printf("Enter the number of Wi-Fi networks you want to analyze: ");
    int n;
    scanf("%d", &n);
    char** networkNames = (char**) malloc(n * sizeof(char*));
    int* signalStrengths = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        getchar(); // Consume newline
        printf("Enter the name of network %d: ", i+1);
        char* name = (char*) malloc(50 * sizeof(char));
        fgets(name, 50, stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline character at the end
        networkNames[i] = name;
        printf("Enter the signal strength of network %d (out of 100): ", i+1);
        int strength;
        scanf("%d", &strength);
        signalStrengths[i] = strength;
    }
    int maxStrength = 0;
    for(int i = 0; i < n; i++) {
        if(signalStrengths[i] > maxStrength) maxStrength = signalStrengths[i];
    }
    int barLength = 10;
    printf("Signal strength (out of 100):\n");
    for(int i = maxStrength; i >= 0; i -= 10) {
        printBar(barLength, i);
    }
    printf("           ");
    for(int i = 0; i < barLength*2-1; i++) {
        printf("-");
    }
    printf("\n           ");
    for(int i = 0; i < n; i++) {
        printf("%s ", networkNames[i]);
        for(int j = 0; j < barLength - strlen(networkNames[i])/2; j++) printf(" ");
    }
    printf("\n");
    printf("           ");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < barLength - 1 - strlen(networkNames[i])/2; j++) printf(" ");
        printf("| ");
    }
    printf("\n");
    free(networkNames);
    free(signalStrengths);
}

int main() {
    analyzeSignalStrength();
    return 0;
}