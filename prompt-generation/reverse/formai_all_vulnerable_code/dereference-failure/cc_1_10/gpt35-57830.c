//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SSID_LENGTH 32

struct AccessPoint {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
};

void to_uppercase(char *string) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        string[i] = toupper(string[i]);
    }
}

void sort_access_points(struct AccessPoint *access_points, int num_access_points) {
    // Bubble sort
    for (int i = 0; i < num_access_points - 1; i++) {
        for (int j = 0; j < num_access_points - i - 1; j++) {
            if (access_points[j].signal_strength < access_points[j+1].signal_strength) {
                struct AccessPoint temp = access_points[j];
                access_points[j] = access_points[j+1];
                access_points[j+1] = temp;
            }
        }
    }
}

int main() {
    int num_access_points;
    printf("Enter the number of access points: ");
    scanf("%d", &num_access_points);

    struct AccessPoint *access_points = (struct AccessPoint*) malloc(num_access_points * sizeof(struct AccessPoint));

    for (int i = 0; i < num_access_points; i++) {
        char ssid[MAX_SSID_LENGTH];
        int signal_strength;

        printf("Enter the SSID for Access Point #%d: ", i+1);
        scanf("%s", ssid);
        to_uppercase(ssid);
        strcpy(access_points[i].ssid, ssid);

        printf("Enter the signal strength for Access Point #%d: ", i+1);
        scanf("%d", &signal_strength);
        access_points[i].signal_strength = signal_strength;
    }

    sort_access_points(access_points, num_access_points);

    printf("\nAccess Point List (sorted by signal strength):\n\n");
    printf("\t%-32s %s\n", "SSID", "Signal Strength (dBm)");
    printf("\t%-32s %s\n", "----", "-------------------");

    for (int i = 0; i < num_access_points; i++) {
        printf("\t%-32s %d\n", access_points[i].ssid, access_points[i].signal_strength);
    }

    free(access_points);
    return 0;
}