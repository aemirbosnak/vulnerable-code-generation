//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define COMMAND_BUFFER 128
#define MAX_NETWORKS 50
#define SSID_LENGTH 32

typedef struct {
    char ssid[SSID_LENGTH];
    int signal_strength;
} WifiNetwork;

void handle_signal(int sig) {
    if (sig == SIGINT) {
        printf("\nTerminating Wi-Fi Signal Analyzer...\n");
        exit(0);
    }
}

void display_networks(WifiNetwork networks[], int count) {
    printf("%-32s %s\n", "SSID", "Signal Strength (dBm)");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-32s %d dBm\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int parse_wifi_info(const char *line, WifiNetwork *network) {
    char *token;

    token = strtok((char *)line, ":");
    if (token == NULL) return 0;
    strcpy(network->ssid, token);

    token = strtok(NULL, ":");
    if (token == NULL) return 0;
    network->signal_strength = atoi(token);

    return 1;
}

int fetch_wifi_networks(WifiNetwork networks[]) {
    FILE *fp;
    char command[COMMAND_BUFFER] = "nmcli -f SSID,SIGNAL dev wifi | tail -n +2";
    char buffer[COMMAND_BUFFER];
    int count = 0;

    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        return 0;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (parse_wifi_info(buffer, &networks[count])) {
            count++;
            if (count >= MAX_NETWORKS) break;
        }
    }

    pclose(fp);
    return count;
}

void sort_networks(WifiNetwork networks[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (networks[i].signal_strength < networks[j].signal_strength) {
                WifiNetwork temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }
}

int main() {
    signal(SIGINT, handle_signal);
    
    WifiNetwork networks[MAX_NETWORKS];
    int network_count;

    while (1) {
        printf("Scanning for Wi-Fi networks...\n");
        network_count = fetch_wifi_networks(networks);
        
        if (network_count > 0) {
            sort_networks(networks, network_count);
            display_networks(networks, network_count);
        } else {
            printf("No networks found or error retrieving data.\n");
        }

        printf("\nRefreshing in 10 seconds...\n");
        sleep(10);
    }

    return 0;
}