//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NETWORKS 100
#define SSID_LEN 32
#define MAC_ADDR_LEN 18
#define COMMAND_BUFFER_SIZE 256

typedef struct {
    char ssid[SSID_LEN];
    char mac[MAC_ADDR_LEN];
    int signal_level;
} Network;

void print_usage() {
    printf("Usage: wireless_scanner [interface] [output_format]\n");
    printf("interface: Wireless interface to scan (e.g., wlan0)\n");
    printf("output_format: Set to 'text' or 'json'\n");
}

void scan_networks(const char* interface, Network networks[], int* count) {
    char command[COMMAND_BUFFER_SIZE];
    sprintf(command, "sudo iwlist %s scan | grep -E 'Cell|ESSID|Signal level' > /tmp/network_scan.txt", interface);
    
    system(command);

    FILE* file = fopen("/tmp/network_scan.txt", "r");
    if (!file) {
        perror("Failed to open temporary scan file");
        exit(EXIT_FAILURE);
    }

    char line[COMMAND_BUFFER_SIZE];
    *count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Cell")) {
            sscanf(line, " Cell %*[^:]: %s", networks[*count].mac);
        } else if (strstr(line, "ESSID")) {
            sscanf(line, " ESSID:\"%[^\"]\"", networks[*count].ssid);
        } else if (strstr(line, "Signal level")) {
            sscanf(line, " Signal level=%d", &networks[*count].signal_level);
            (*count)++;
        }
    }

    fclose(file);
    system("rm -f /tmp/network_scan.txt");  // Clean up
}

void print_text_output(Network networks[], int count) {
    printf("Available Wireless Networks:\n");
    for (int i = 0; i < count; i++) {
        printf("SSID: %s\n", networks[i].ssid);
        printf("MAC: %s\n", networks[i].mac);
        printf("Signal Level: %d dBm\n", networks[i].signal_level);
        printf("------------------------------------\n");
    }
}

void print_json_output(Network networks[], int count) {
    printf("[\n");
    for (int i = 0; i < count; i++) {
        printf("  {\n");
        printf("    \"ssid\": \"%s\",\n", networks[i].ssid);
        printf("    \"mac\": \"%s\",\n", networks[i].mac);
        printf("    \"signal_level\": %d\n", networks[i].signal_level);
        printf("  }%s\n", (i < count - 1) ? "," : "");
    }
    printf("]\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char* interface = argv[1];
    const char* output_format = argv[2];
    
    if (strcmp(output_format, "text") != 0 && strcmp(output_format, "json") != 0) {
        printf("Invalid output format. Choose 'text' or 'json'.\n");
        return EXIT_FAILURE;
    }

    Network networks[MAX_NETWORKS];
    int network_count = 0;

    scan_networks(interface, networks, &network_count);

    if (strcmp(output_format, "text") == 0) {
        print_text_output(networks, network_count);
    } else {
        print_json_output(networks, network_count);
    }

    return EXIT_SUCCESS;
}