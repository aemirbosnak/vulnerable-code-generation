//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NETWORKS 100
#define MAX_SSID_LENGTH 32
#define MAX_CHANNEL_NUMBER 14

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int channel;
    int signal_strength;
    time_t last_seen;
} Network;

int num_networks = 0;
Network networks[MAX_NETWORKS];

void add_network(char* ssid, int channel, int signal_strength) {
    if (num_networks >= MAX_NETWORKS) {
        printf("Error: Maximum number of networks reached.\n");
        return;
    }

    strcpy(networks[num_networks].ssid, ssid);
    networks[num_networks].channel = channel;
    networks[num_networks].signal_strength = signal_strength;
    networks[num_networks].last_seen = time(0);
    num_networks++;
}

void print_networks() {
    printf("Networks found:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s (Channel %d, Signal Strength %d)\n", networks[i].ssid, networks[i].channel, networks[i].signal_strength);
    }
}

int main() {
    printf("Starting post-apocalyptic wireless network scanner...\n");

    char input[1024];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char* ssid = strtok(input, ":");
        int channel = atoi(strtok(NULL, ":"));
        int signal_strength = atoi(strtok(NULL, ":"));

        add_network(ssid, channel, signal_strength);
    }

    print_networks();

    return 0;
}