//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_NETWORKS 100

typedef struct {
    char essid[36]; // Wi-Fi network name
    int signal;     // Signal strength in dBm
} Network;

void trim_newline(char *str) {
    char *newline = strchr(str, '\n');
    if (newline) *newline = '\0';
}

int parse_output(const char *buffer, Network *networks) {
    int count = 0;
    char *line, *context;

    line = strtok_r((char *)buffer, "\n", &context);
    while (line) {
        if (strstr(line, "ESSID:")) {
            sscanf(line, " ESSID:\"%[^\"]\"", networks[count].essid);
        } else if (strstr(line, "Signal level=")) {
            sscanf(line, " Signal level=%d", &networks[count].signal);
            count++;
        }
        line = strtok_r(NULL, "\n", &context);
    }
    
    return count;
}

void display_networks(Network *networks, int count) {
    printf("%-30s %s\n", "ESSID", "Signal Strength (dBm)");
    printf("%-30s %s\n", "------------------------------", "---------------------");
    for (int i = 0; i < count; i++) {
        printf("%-30s %d\n", networks[i].essid, networks[i].signal);
    }
}

void run_command(const char *cmd, char *output) {
    FILE *fp;
    fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(EXIT_FAILURE);
    }
    fgets(output, BUFFER_SIZE, fp);
    pclose(fp);
}

int main() {
    char command[] = "iwlist scan 2>/dev/null";
    char output[BUFFER_SIZE];
    Network networks[MAX_NETWORKS];
    int network_count;

    run_command(command, output);
    network_count = parse_output(output, networks);
    
    if (network_count > 0) {
        display_networks(networks, network_count);
    } else {
        printf("No Wi-Fi networks found.\n");
    }

    return 0;
}