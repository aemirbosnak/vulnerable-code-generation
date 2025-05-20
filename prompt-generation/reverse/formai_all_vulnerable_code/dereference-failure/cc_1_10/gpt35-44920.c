//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

typedef struct {
    char* ssid;
    int signal_strength;
} AccessPoint;

// Function to print the list of AccessPoints
void printAccessPoints(AccessPoint *accessPoints, int numAccessPoints) {
    printf("SSID                  Signal Strength (0-100)\n");
    for (int i = 0; i < numAccessPoints; i++) {
        printf("%-20s%-20d\n", accessPoints[i].ssid, accessPoints[i].signal_strength);
    }
}

// Function to sort the AccessPoints based on signal strength
void sortAccessPoints(AccessPoint *accessPoints, int numAccessPoints) {
    for (int i = 0; i < numAccessPoints - 1; i++) {
        for (int j = 0; j < numAccessPoints - i - 1; j++) {
            if (accessPoints[j].signal_strength < accessPoints[j + 1].signal_strength) {
                AccessPoint temp = accessPoints[j];
                accessPoints[j] = accessPoints[j + 1];
                accessPoints[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numAccessPoints;
    printf("Enter the number of access points in range: ");
    scanf("%d", &numAccessPoints);

    // Allocate memory for the AccessPoints array
    AccessPoint *accessPoints = (AccessPoint*) malloc(numAccessPoints * sizeof(AccessPoint));

    // Get input for each AccessPoint ssid and signal strength
    for (int i = 0; i < numAccessPoints; i++) {
        accessPoints[i].ssid = (char*) malloc(21 * sizeof(char));
        printf("\nEnter the ssid of access point %d: ", i + 1);
        scanf("%s", accessPoints[i].ssid);
        printf("Enter the signal strength (0-100) of access point %d: ", i + 1);
        scanf("%d", &accessPoints[i].signal_strength);

        // Ensure the signal strength is within the valid range
        while (accessPoints[i].signal_strength < MIN_SIGNAL_STRENGTH ||
               accessPoints[i].signal_strength > MAX_SIGNAL_STRENGTH) {
            printf("Invalid signal strength. Please enter a value between %d and %d: ", MIN_SIGNAL_STRENGTH, MAX_SIGNAL_STRENGTH);
            scanf("%d", &accessPoints[i].signal_strength);
        }
    }

    // Sort the AccessPoints based on signal strength
    sortAccessPoints(accessPoints, numAccessPoints);

    // Print the list of AccessPoints
    printAccessPoints(accessPoints, numAccessPoints);

    // Free the allocated memory
    for (int i = 0; i < numAccessPoints; i++) {
        free(accessPoints[i].ssid);
    }
    free(accessPoints);

    return 0;
}