//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/wireless.h>
#include <sys/ioctl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_NETWORKS 50

typedef struct {
    char ssid[32];
    int signal_strength;
} WiFiNetwork;

void get_current_strength(const char *interface, WiFiNetwork *networks, int *count) {
    struct iwreq req;
    struct iw_statistics stats;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    strncpy(req.ifr_name, interface, IFNAMSIZ);
    if (ioctl(sock, SIOCGIWSTATS, &req) < 0) {
        perror("Failed to get wireless stats");
        close(sock);
        return;
    }

    memcpy(&stats, &req.u.data, sizeof(stats));

    networks[*count].signal_strength = stats.qual.level;
    snprintf(networks[*count].ssid, sizeof(networks[*count].ssid), "Current Network: %s", interface);
    (*count)++;

    close(sock);
}

void scan_for_networks(const char *interface, WiFiNetwork *networks, int *count) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "iwlist %s scan", interface);
    FILE *fp = popen(command, "r");

    if (fp == NULL) {
        perror("Failed to run iwlist scan");
        return;
    }

    char buffer[BUFFER_SIZE];
    char ssid[32];
    int signal_strength;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (sscanf(buffer, "Cell %*d - Address: %*s") == 0) {
            continue;
        }

        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            if (sscanf(buffer, "ESSID:\"%[^\"]\"", ssid) == 1) {
                break;
            }
        }

        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            if (sscanf(buffer, "Signal level=%d dBm", &signal_strength) == 1) {
                break;
            }
        }

        snprintf(networks[*count].ssid, sizeof(networks[*count].ssid), "%s", ssid);
        networks[*count].signal_strength = signal_strength;
        (*count)++;
        if (*count >= MAX_NETWORKS) {
            break;
        }
    }

    pclose(fp);
}

void display_networks(const WiFiNetwork *networks, int count) {
    printf("\n===== Wi-Fi Networks Available =====\n");
    for (int i = 0; i < count; i++) {
        printf("SSID: %-32s | Signal Strength: %3d dBm\n", networks[i].ssid, networks[i].signal_strength);
    }
    printf("===================================\n");
}

int main() {
    const char *interface = "wlan0"; // Change to your Wi-Fi interface
    WiFiNetwork networks[MAX_NETWORKS];
    int count = 0;

    // Scan for networks
    scan_for_networks(interface, networks, &count);

    // Get current network signal strength
    get_current_strength(interface, networks, &count);

    // Display all networks and their signal strengths
    display_networks(networks, count);

    return 0;
}