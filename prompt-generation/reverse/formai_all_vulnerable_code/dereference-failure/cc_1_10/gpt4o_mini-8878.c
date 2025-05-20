//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define MAX_NETWORKS 100
#define COMMAND_LENGTH 256

typedef struct {
    char ssid[32];
    int signal_strength;
} WiFiNetwork;

WiFiNetwork networks[MAX_NETWORKS];
int network_count = 0;
int running = 1;

void handle_signal(int signal) {
    if (signal == SIGINT) {
        running = 0;
    }
}

void parse_networks(char *output) {
    char *line;
    line = strtok(output, "\n");
    network_count = 0;

    while (line != NULL && network_count < MAX_NETWORKS) {
        if (strstr(line, "Signal:")) {
            sscanf(line, "Signal: %d", &networks[network_count].signal_strength);
        } else if (strstr(line, "SSID:")) {
            sscanf(line, "SSID: %31[^\n]", networks[network_count].ssid);
            network_count++;
        }
        line = strtok(NULL, "\n");
    }
}

void display_networks() {
    printf("\nDetected Wi-Fi Networks:\n");
    printf("%-32s | %s\n", "SSID", "Signal Strength (dBm)");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < network_count; i++) {
        printf("%-32s | %d\n", networks[i].ssid, networks[i].signal_strength);
    }
    printf("-----------------------------------------------------\n");
}

void fetch_networks() {
    char command[COMMAND_LENGTH];
    char buffer[4096];

    FILE *fp;

    snprintf(command, sizeof(command), "iwlist wlan0 scanning | grep -E 'ESSID|Signal'");

    if ((fp = popen(command, "r")) == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        exit(1);
    }

    fread(buffer, sizeof(char), sizeof(buffer), fp);
    pclose(fp);

    parse_networks(buffer);
}

int main() {
    signal(SIGINT, handle_signal);

    while (running) {
        fetch_networks();
        display_networks();
        sleep(5); // Refresh every 5 seconds
    }

    printf("Exiting program...\n");
    return 0;
}