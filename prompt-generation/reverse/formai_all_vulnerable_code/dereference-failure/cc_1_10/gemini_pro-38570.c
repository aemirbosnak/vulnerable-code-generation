//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of networks to be displayed
#define MAX_NETWORKS 10

// Structure to store the details of a wireless network
typedef struct {
  char ssid[33];
  char bssid[18];
  int channel;
  int signal_strength;
  int security;
} wireless_network;

// Function to scan for wireless networks
int scan_wireless_networks(wireless_network *networks) {
  // Open the wireless interface
  FILE *fp = fopen("/proc/net/wireless", "r");
  if (fp == NULL) {
    perror("fopen");
    return -1;
  }

  // Read the header line
  char line[256];
  fgets(line, sizeof(line), fp);

  // Read the data lines
  int i = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Parse the data line
    char *ssid = strtok(line, ":");
    char *bssid = strtok(NULL, ":");
    char *channel = strtok(NULL, ":");
    char *signal_strength = strtok(NULL, ":");
    char *security = strtok(NULL, ":");

    // Store the network details in the array
    strcpy(networks[i].ssid, ssid);
    strcpy(networks[i].bssid, bssid);
    networks[i].channel = atoi(channel);
    networks[i].signal_strength = atoi(signal_strength);
    networks[i].security = atoi(security);

    i++;
    if (i >= MAX_NETWORKS) {
      break;
    }
  }

  // Close the wireless interface
  fclose(fp);

  return i;
}

// Function to print the details of a wireless network
void print_wireless_network(wireless_network *network) {
  printf("SSID: %s\n", network->ssid);
  printf("BSSID: %s\n", network->bssid);
  printf("Channel: %d\n", network->channel);
  printf("Signal Strength: %d\n", network->signal_strength);
  printf("Security: %d\n", network->security);
}

// Main function
int main() {
  // Array to store the details of the wireless networks
  wireless_network networks[MAX_NETWORKS];

  // Scan for wireless networks
  int num_networks = scan_wireless_networks(networks);

  // Print the details of the wireless networks
  for (int i = 0; i < num_networks; i++) {
    print_wireless_network(&networks[i]);
    printf("\n");
  }

  return 0;
}