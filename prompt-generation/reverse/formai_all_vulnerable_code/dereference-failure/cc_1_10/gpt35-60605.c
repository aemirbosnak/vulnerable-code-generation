//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: artistic
/*
   C Wireless Network Scanner
   Author: [Your Name Here]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <ifaddrs.h>

struct wireless_network {
    char ssid[32];
    char bssid[18];
    char signal[6];
    char security[50];
} networks[10];

int get_wireless_networks() {
    FILE *fp = popen("sudo iwlist wlan0 scanning | egrep 'Cell |ESSID|Signal|Authentication'", "r");

    if (fp == NULL) {
        perror("Failed to execute command");
        return -1;
    }

    char buffer[256];
    int network_count = 0;
    int line_count = 0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, "Cell")) {
            network_count++;
            line_count = 0;
        }

        if (strstr(buffer, "ESSID")) {
            strcpy(networks[network_count-1].ssid, strstr(buffer, "\"") + 1);
            networks[network_count-1].ssid[strlen(networks[network_count-1].ssid)-2] = '\0';
        }

        if (strstr(buffer, "Address")) {
            strcpy(networks[network_count-1].bssid, strstr(buffer, ":") + 2);
        }

        if (strstr(buffer, "Signal")) {
            strcpy(networks[network_count-1].signal, strstr(buffer, ":") + 2);
            networks[network_count-1].signal[strlen(networks[network_count-1].signal)-4] = '\0';
        }

        if (strstr(buffer, "Auth")) {
            strcpy(networks[network_count-1].security, strstr(buffer, ":") + 2);
            networks[network_count-1].security[strlen(networks[network_count-1].security)-2] = '\0';
        }
    }

    pclose(fp);
    return network_count;
}

int main() {
    int network_count = get_wireless_networks();

    if (network_count == -1) {
        printf("Error while scanning for networks: %s\n", strerror(errno));
        return 1;
    }

    printf("Found %d wireless networks:\n", network_count);

    for (int i = 0; i < network_count; i++) {
        printf("SSID: %s\n", networks[i].ssid);
        printf("BSSID: %s\n", networks[i].bssid);
        printf("Signal strength: %s\n", networks[i].signal);
        printf("Security: %s\n", networks[i].security);
        printf("\n");
    }

    return 0;
}