//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_INTERFACES 10
#define MAX_SSIDS 10

typedef struct {
    char *name;
    char *ssid;
    int signal;
} network;

void print_networks(network *networks, int count) {
    printf("Wireless Networks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (%d%%)\n", networks[i].ssid, networks[i].signal);
    }
}

network *scan_networks(char *interface) {
    network *networks = malloc(sizeof(network) * MAX_SSIDS);
    int count = 0;
    FILE *fp;
    char line[1024];
    char *token;
    char *cmd = "iwlist scan ";

    strcat(cmd, interface);
    strcat(cmd, " | grep -E '^Cell'");

    fp = popen(cmd, "r");

    if (fp == NULL) {
        printf("Error: failed to run command\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ":");
        strcpy(networks[count].ssid, token);
        networks[count].signal = atoi(strtok(NULL, ":"));
        count++;
    }

    pclose(fp);

    return networks;
}

int main() {
    char *interfaces[MAX_INTERFACES];
    int count = 0;
    char *line;
    char *token;
    FILE *fp;

    fp = fopen("/proc/net/dev", "r");

    if (fp == NULL) {
        printf("Error: failed to open file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ":");
        if (strcmp(token, "wlan") == 0) {
            strcpy(interfaces[count], token);
            count++;
        }
    }

    fclose(fp);

    for (int i = 0; i < count; i++) {
        network *networks = scan_networks(interfaces[i]);
        print_networks(networks, MAX_SSIDS);
    }

    return 0;
}