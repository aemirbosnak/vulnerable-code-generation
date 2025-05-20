//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define MAX_SSID_LEN 32
#define MAX_RESULTS 10

typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} WiFiNetwork;

void handle_sigint(int sig) {
    printf("\nThe wasteland calls for silence. Exiting...\n");
    exit(0);
}

void scan_wifi_networks(WiFiNetwork *networks, int *network_count) {
    FILE *fp;
    char command[] = "nmcli -f SSID,SIGNAL dev wifi";
    char buffer[256];
    *network_count = 0;

    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (*network_count >= MAX_RESULTS) {
            break;
        }
        
        char *ssid_token = strtok(buffer, " ");
        char *signal_token = strtok(NULL, " ");
        
        if (ssid_token != NULL && signal_token != NULL) {
            strncpy(networks[*network_count].ssid, ssid_token, MAX_SSID_LEN);
            networks[*network_count].signal_strength = atoi(signal_token);
            (*network_count)++;
        }
    }

    pclose(fp);
}

void display_results(WiFiNetwork *networks, int network_count) {
    printf("=== Wasteland Wi-Fi Signal Strength ===\n");
    for (int i = 0; i < network_count; i++) {
        printf("SSID: %s | Signal Strength: %d dBm\n", networks[i].ssid, networks[i].signal_strength);
    }
    printf("======================================\n");
}

int main() {
    signal(SIGINT, handle_sigint);

    WiFiNetwork networks[MAX_RESULTS];
    int network_count = 0;

    while (1) {
        printf("Scanning for Wi-Fi networks...\n");
        scan_wifi_networks(networks, &network_count);
        display_results(networks, network_count);

        printf("Waiting for the next scan...\n");
        sleep(10);
    }

    return 0;
}