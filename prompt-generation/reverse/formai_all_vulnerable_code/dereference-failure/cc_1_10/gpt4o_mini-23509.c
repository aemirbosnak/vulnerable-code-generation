//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_NETWORKS 50
#define BUFFER_SIZE 256

struct Network {
    char ssid[BUFFER_SIZE];
    char signal_strength[BUFFER_SIZE];
    char encryption[BUFFER_SIZE];
};

void print_artistic_header() {
    printf("*****************************************\n");
    printf("*               WiFi Scanner             *\n");
    printf("*****************************************\n");
    printf("*       Scanning for available networks   *\n");
    printf("*****************************************\n\n");
}

void display_networks(struct Network networks[], int count) {
    printf("Found %d networks:\n", count);
    printf("-------------------------------------------------------\n");
    printf("| %-30s | %-15s | %-10s |\n", "SSID", "Signal Strength", "Encryption");
    printf("-------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-30s | %-15s | %-10s |\n", networks[i].ssid, networks[i].signal_strength, networks[i].encryption);
    }

    printf("-------------------------------------------------------\n");
}

int scan_networks(struct Network networks[]) {
    FILE *fp;
    char path[BUFFER_SIZE];
    fp = popen("nmcli -t -f SSID,SIGNAL,SECURITY device wifi list", "r");

    if (fp == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        return -1;
    }

    int count = 0;
    while (fgets(path, sizeof(path), fp) != NULL) {
        char *token = strtok(path, ":");
        if (token) {
            strncpy(networks[count].ssid, token, BUFFER_SIZE);
        }
        
        token = strtok(NULL, ":");
        if (token) {
            strncpy(networks[count].signal_strength, token, BUFFER_SIZE);
        }
        
        token = strtok(NULL, ":");
        if (token) {
            strncpy(networks[count].encryption, token, BUFFER_SIZE);
        }
        
        count++;
        if (count >= MAX_NETWORKS) {
            break;
        }
    }

    pclose(fp);
    return count;
}

int main() {
    struct Network networks[MAX_NETWORKS];
    print_artistic_header();
    
    int count = scan_networks(networks);
    if (count >= 0) {
        display_networks(networks, count);
    } else {
        fprintf(stderr, "No networks found or an error occurred.\n");
    }

    return 0;
}