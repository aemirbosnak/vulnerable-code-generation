//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum number of Wi-Fi networks to scan for
#define MAX_NETWORKS 100

// Define the structure of a Wi-Fi network
typedef struct WiFinetwork {
  char ssid[33];
  int signal_strength;
} WiFinetwork;

// Define the function to compare two Wi-Fi networks by signal strength
int compare_networks(const void *a, const void *b) {
  const WiFinetwork *networkA = (const WiFinetwork *)a;
  const WiFinetwork *networkB = (const WiFinetwork *)b;

  return networkB->signal_strength - networkA->signal_strength;
}

// Define the function to scan for Wi-Fi networks
bool scan_wifi_networks(WiFinetwork *networks, int *num_networks) {
  // Open the Wi-Fi scanning interface
  FILE *fp = fopen("/proc/net/wireless", "r");
  if (fp == NULL) {
    perror("fopen");
    return false;
  }

  // Read the header line
  char line[1024];
  if (fgets(line, sizeof(line), fp) == NULL) {
    perror("fgets");
    fclose(fp);
    return false;
  }

  // Scan for Wi-Fi networks
  int i = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Parse the line
    char *ssid = strtok(line, ":");
    char *signal_strength = strtok(NULL, ":");

    // Convert the signal strength to an integer
    int signal_strength_int = atoi(signal_strength);

    // Store the network in the array
    strcpy(networks[i].ssid, ssid);
    networks[i].signal_strength = signal_strength_int;

    i++;
  }

  // Close the Wi-Fi scanning interface
  fclose(fp);

  // Set the number of networks found
  *num_networks = i;

  return true;
}

// Define the main function
int main(void) {
  // Declare the array of Wi-Fi networks
  WiFinetwork networks[MAX_NETWORKS];

  // Declare the number of networks found
  int num_networks;

  // Scan for Wi-Fi networks
  if (!scan_wifi_networks(networks, &num_networks)) {
    return EXIT_FAILURE;
  }

  // Sort the networks by signal strength
  qsort(networks, num_networks, sizeof(WiFinetwork), compare_networks);

  // Print the sorted networks
  for (int i = 0; i < num_networks; i++) {
    printf("%s: %d dBm\n", networks[i].ssid, networks[i].signal_strength);
  }

  return EXIT_SUCCESS;
}