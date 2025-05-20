//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SSID_LEN 32

typedef struct {
    char ssid[MAX_SSID_LEN];
    int channel;
} AccessPoint;

AccessPoint *scan_networks(int *num_aps) {
    int num_lines = 0;
    char *buffer = NULL;
    size_t buflen = 0;
    FILE *fp = popen("iwlist wlan0 scan", "r");
    if (fp == NULL) {
        perror("Failed to run iwlist");
        exit(EXIT_FAILURE);
    }

    // Count the number of lines in the output
    while (getline(&buffer, &buflen, fp) != -1) {
        num_lines++;
    }
    rewind(fp);

    // Allocate memory for AccessPoint structures
    AccessPoint *aps = (AccessPoint *) malloc(num_lines * sizeof(AccessPoint));
    if (aps == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;

    // Read each line of output and store SSID and channel information
    while (getline(&buffer, &buflen, fp) != -1) {
        if (strstr(buffer, "ESSID:\"") != NULL) {
            char *ssid_start = strstr(buffer, "ESSID:\"") + strlen("ESSID:\"");
            char *ssid_end = strstr(ssid_start, "\"");
            int ssid_size = ssid_end - ssid_start;
            if (ssid_size >= MAX_SSID_LEN) {
                ssid_size = MAX_SSID_LEN - 1;
            }
            strncpy(aps[i].ssid, ssid_start, ssid_size);
            aps[i].ssid[ssid_size] = '\0';
        } else if (strstr(buffer, "Channel:") != NULL) {
            char *channel_start = strstr(buffer, "Channel:") + strlen("Channel:");
            aps[i].channel = atoi(channel_start);
            i++;
        }
    }
    pclose(fp);
    *num_aps = num_lines;
    free(buffer);
    return aps;
}

int main() {
    int num_aps;
    AccessPoint *aps = scan_networks(&num_aps);
    printf("Found %d access points:\n", num_aps);
    for (int i = 0; i < num_aps; i++) {
        printf("SSID: %s, Channel: %d\n", aps[i].ssid, aps[i].channel);
    }
    free(aps);
    return 0;
}