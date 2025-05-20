//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_NETWORKS 20
#define BUFFER_SIZE 1024

void parse_signal_strength(char *buffer) {
    char *line;
    int signal_strength;
    int count = 0;

    line = strtok(buffer, "\n");
    while (line != NULL && count < MAX_NETWORKS) {
        if (strstr(line, "Signal:") != NULL) {
            sscanf(line, "Signal: %d", &signal_strength);
            printf("Wi-Fi Network %d Signal Strength: %d dBm\n", count + 1, signal_strength);
            count++;
        }
        line = strtok(NULL, "\n");
    }
}

void analyze_wifi_signal() {
    FILE *fp;
    char buffer[BUFFER_SIZE];

    fp = popen("nmcli -t -f SSID,SIGNAL dev wifi", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fread(buffer, sizeof(char), sizeof(buffer), fp);
    pclose(fp);

    parse_signal_strength(buffer);
}

int main() {
    printf("=== Wi-Fi Signal Strength Analyzer ===\n");
    printf("Initiating scan...\n");
    
    analyze_wifi_signal();

    printf("Scan completed.\n");
    
    return 0;
}