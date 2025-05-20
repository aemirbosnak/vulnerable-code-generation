//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct to hold the access point data
struct access_point {
    char* ssid;
    int signal_strength;
    int channel;
};

// Function to parse the CSV file containing information about access points
void parse_file(char* filename, struct access_point** ap_list, int* num_aps) {
    // Open the file for reading
    FILE* fp = fopen(filename, "r");

    // Initialize variables for parsing
    char buffer[1024];
    char* token;
    int ss, ch;

    // Read the first line (header) and discard it
    fgets(buffer, sizeof(buffer), fp);

    // Loop through the remaining lines and parse the data
    while (fgets(buffer, sizeof(buffer), fp)) {
        // Allocate memory for a new access point struct
        struct access_point* ap = (struct access_point*) malloc(sizeof(struct access_point));
        ap->ssid = NULL;

        // Use strtok to tokenize the CSV line
        token = strtok(buffer, ",");
        while (token != NULL) {
            // Use isdigit() to determine if token is a number or a string
            if (isdigit(*token)) {
                // Token is a number, so set signal_strength or channel accordingly
                if (ap->channel == 0) {
                    ap->channel = atoi(token);
                } else {
                    ap->signal_strength = atoi(token);
                }
            } else {
                // Token is a string, so set ssid accordingly
                if (ap->ssid == NULL) {
                    ap->ssid = (char*) malloc(sizeof(char) * (strlen(token) + 1));
                    strcpy(ap->ssid, token);
                }
            }

            // Get the next token
            token = strtok(NULL, ",");
        }

        // Add the new access point to the list
        *ap_list = (struct access_point*) realloc(*ap_list, sizeof(struct access_point) * (*num_aps + 1));
        (*ap_list)[*num_aps] = *ap;
        (*num_aps)++;
    }

    // Close the file
    fclose(fp);
}

// Function to print the list of access points
void print_aps(struct access_point* ap_list, int num_aps) {
    for (int i = 0; i < num_aps; i++) {
        printf("%s (Channel: %d, Signal Strength: %d)\n", ap_list[i].ssid, ap_list[i].channel, ap_list[i].signal_strength);
    }
}

int main() {
    // Initialize variables
    char filename[] = "access_points.csv";
    struct access_point* ap_list = NULL;
    int num_aps = 0;

    // Parse the CSV file and load the access points into memory
    parse_file(filename, &ap_list, &num_aps);

    // Print the list of access points
    printf("Found %d access points:\n", num_aps);
    print_aps(ap_list, num_aps);

    // Free memory allocated for access points
    for (int i = 0; i < num_aps; i++) {
        free(ap_list[i].ssid);
    }
    free(ap_list);

    return 0;
}