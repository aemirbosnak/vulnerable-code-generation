//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctype.h>

#define MAX_AP 100
#define SSID_LEN 32
#define BUFFER_LEN 256

typedef struct {
    char ssid[SSID_LEN];
    int signal_strength;
} AccessPoint;

AccessPoint access_points[MAX_AP];
int ap_count = 0;

// Function to parse the output of the "iwlist" command
void parse_iwlist_output(const char *output) {
    char *line = strtok((char *)output, "\n");
    while (line != NULL) {
        if (strstr(line, "ESSID")) {
            char *ssid = strstr(line, "\"") + 1;
            char *end_ssid = strchr(ssid, '\"');
            if (end_ssid) {
                *end_ssid = '\0';
                strcpy(access_points[ap_count].ssid, ssid);
            }
        } else if (strstr(line, "Signal level")) {
            int signal_level;
            sscanf(line, " Signal level=%d", &signal_level);
            access_points[ap_count].signal_strength = signal_level;
            ap_count++;
        }
        line = strtok(NULL, "\n");
    }
}

// This function executes a command and returns its output
char* exec_command(const char* cmd) {
    FILE *fp;
    char *output = malloc(BUFFER_LEN);
    char buffer[BUFFER_LEN];

    if ((fp = popen(cmd, "r")) == NULL) {
        perror("popen failed");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        strcat(output, buffer);
    }

    pclose(fp);
    return output;
}

// Function to display the Wi-Fi signal statistics
void display_stats() {
    int total_strength = 0;
    int max_strength = -100;
    int min_strength = 0;

    for (int i = 0; i < ap_count; ++i) {
        total_strength += access_points[i].signal_strength;
        if (access_points[i].signal_strength > max_strength) {
            max_strength = access_points[i].signal_strength;
        }
        if (access_points[i].signal_strength < min_strength) {
            min_strength = access_points[i].signal_strength;
        }
    }

    double average_strength = (double)total_strength / ap_count;

    printf("\nWi-Fi Signal Strength Statistics:\n");
    printf("Total Access Points: %d\n", ap_count);
    printf("Average Signal Strength: %.2f dBm\n", average_strength);
    printf("Maximum Signal Strength: %d dBm\n", max_strength);
    printf("Minimum Signal Strength: %d dBm\n", min_strength);
}

// Main function
int main() {
    char cmd[100];

    // Clear previous data
    memset(access_points, 0, sizeof(access_points));
    ap_count = 0;

    printf("Scanning for Wi-Fi Access Points...\n");

    // Execute the command to retrieve Wi-Fi information
    snprintf(cmd, sizeof(cmd), "iwlist scanning 2>/dev/null");
    char *output = exec_command(cmd);

    // Parse the output
    parse_iwlist_output(output);
    
    // Free the allocated output buffer
    free(output);

    // Display statistics
    display_stats();

    return 0;
}