//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// An array of SSID structures
typedef struct {
    char *ssid;
    double strength;
} SSID;

// A function to compare two SSID structures by strength
int compare_strength(const void *a, const void *b) {
    SSID *ssid1 = (SSID *)a;
    SSID *ssid2 = (SSID *)b;
    return ssid2->strength - ssid1->strength;
}

int main() {
    // An array of all the SSIDs we find
    SSID *ssids = NULL;
    // The number of SSIDs we find
    int num_ssids = 0;

    // Get the list of SSIDs from the system
    FILE *fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the header line
    char line[1024];
    fgets(line, sizeof(line), fp);

    // Read each line of the file
    while (fgets(line, sizeof(line), fp)) {
        // Parse the line
        char *ssid = strtok(line, ":");
        char *strength = strtok(NULL, ": ");

        // Allocate memory for a new SSID structure
        SSID *new_ssid = malloc(sizeof(SSID));
        if (new_ssid == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }

        // Copy the SSID and strength into the structure
        new_ssid->ssid = strdup(ssid);
        new_ssid->strength = atof(strength);

        // Add the SSID to the array
        ssids = realloc(ssids, (num_ssids + 1) * sizeof(SSID));
        if (ssids == NULL) {
            perror("realloc");
            return EXIT_FAILURE;
        }
        ssids[num_ssids] = *new_ssid;
        num_ssids++;
    }

    // Close the file
    fclose(fp);

    // Sort the SSIDs by strength
    qsort(ssids, num_ssids, sizeof(SSID), compare_strength);

    // Print the SSIDs and their strengths
    printf("SSID\t\tStrength\n");
    for (int i = 0; i < num_ssids; i++) {
        printf("%s\t\t%f\n", ssids[i].ssid, ssids[i].strength);
    }

    // Free the memory we allocated
    for (int i = 0; i < num_ssids; i++) {
        free(ssids[i].ssid);
    }
    free(ssids);

    return EXIT_SUCCESS;
}