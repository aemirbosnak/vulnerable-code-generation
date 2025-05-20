//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define COMMAND_SIZE 512

// Structure to hold details of a wireless network
typedef struct {
    char ssid[33];
    char mac[18];
    int signal_level;
} WirelessNetwork;

// Function to execute a command and collect output
void execute_command(const char* command, char* output, size_t output_size) {
    FILE* fp;
    if ((fp = popen(command, "r")) == NULL) {
        perror("popen failed");
        exit(EXIT_FAILURE);
    }

    // Read the output a line at a time
    if (fgets(output, output_size, fp) == NULL) {
        perror("fgets failed");
        pclose(fp);
        exit(EXIT_FAILURE);
    }

    pclose(fp);
}

// Function to parse a single line of iwlist output for network information
void parse_network_info(const char* line, WirelessNetwork* network) {
    char* pos;

    // Extract SSID
    if ((pos = strstr(line, "ESSID:")) != NULL) {
        sscanf(pos, "ESSID:\"%[^\"]\"", network->ssid);
    }

    // Extract MAC address (format: xx:xx:xx:xx:xx:xx)
    if ((pos = strstr(line, "Address:")) != NULL) {
        sscanf(pos, "Address: %s", network->mac);
    }

    // Extract Signal Level
    if ((pos = strstr(line, "Signal level=")) != NULL) {
        sscanf(pos, "Signal level=%d", &network->signal_level);
    }
}

// Main function
int main(void) {
    char command[COMMAND_SIZE];
    char buffer[MAX_LINE_LENGTH];

    // Prepare the command to scan for networks
    sprintf(command, "iwlist wlan0 scan | grep -E 'ESSID|Address|Signal level'");

    // Execute the command and read output
    char* output = (char*)malloc(sizeof(char) * COMMAND_SIZE);
    execute_command(command, output, COMMAND_SIZE);

    // Initialize an array to hold found wireless networks
    WirelessNetwork networks[100]; // Assuming a max of 100 networks
    int network_count = 0;

    // Parse each line of output for network information
    char* line = strtok(output, "\n");
    while (line != NULL) {
        if (strstr(line, "ESSID") != NULL) {
            parse_network_info(line, &networks[network_count]);
            network_count++;
        }
        line = strtok(NULL, "\n");
    }

    // Display the found networks
    printf("Wireless Networks Found:\n");
    printf("%-30s %-20s %-15s\n", "SSID", "MAC Address", "Signal Level (dBm)");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < network_count; i++) {
        printf("%-30s %-20s %-15d\n", networks[i].ssid, networks[i].mac, networks[i].signal_level);
    }

    // Free allocated memory
    free(output);

    return 0;
}