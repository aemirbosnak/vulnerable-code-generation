//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 100
#define MAX_SSID_LEN 32

typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_level;
    char encryption[10];
} WiFiNetwork;

void parse_iwlist_output(char* output, WiFiNetwork networks[], int* network_count) {
    char* line;
    char* context = NULL;
    *network_count = 0;

    line = strtok_r(output, "\n", &context);
    while (line != NULL) {
        if (strstr(line, "ESSID:") != NULL) {
            sscanf(line, " ESSID:\"%[^\"]\"", networks[*network_count].ssid);
        } else if (strstr(line, "Quality=") != NULL) {
            sscanf(line, " Quality=%*d/%*d  Signal level=%d", &networks[*network_count].signal_level);
        } else if (strstr(line, "Encryption key: on") != NULL) {
            strcpy(networks[*network_count].encryption, "Enabled");
        } else if (strstr(line, "Encryption key: off") != NULL) {
            strcpy(networks[*network_count].encryption, "Disabled");
        }

        if (strstr(line, "ESSID:") && line - output > 0) {
            (*network_count)++;
        }

        line = strtok_r(NULL, "\n", &context);
    }
}

void print_networks(WiFiNetwork networks[], int network_count) {
    printf("Available WiFi Networks:\n");
    printf("%-30s %-15s Signal Level\n", "SSID", "Encryption");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < network_count; i++) {
        printf("%-30s %-15s %d dBm\n", networks[i].ssid, networks[i].encryption, networks[i].signal_level);
    }
}

int main() {
    WiFiNetwork networks[MAX_NETWORKS];
    int network_count = 0;
    char command[128];
    char output[2048];

    // Running iwlist to scan for WiFi networks
    snprintf(command, sizeof(command), "iwlist wlan0 scan 2>/dev/null");
    
    FILE* pipe = popen(command, "r");
    if (pipe == NULL) {
        perror("popen failed");
        return 1;
    }

    // Reading output from the command
    size_t bytesRead = fread(output, 1, sizeof(output), pipe);
    output[bytesRead] = '\0'; // Null terminate the string
    pclose(pipe);

    // Parse the output and populate networks
    parse_iwlist_output(output, networks, &network_count);

    // Print the available networks
    print_networks(networks, network_count);

    return 0;
}