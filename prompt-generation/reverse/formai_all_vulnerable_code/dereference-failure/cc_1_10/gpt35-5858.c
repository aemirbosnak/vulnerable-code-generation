//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NETWORKS 20

struct network_info {
    char name[20];
    int signal_strength;
};

int num_networks = 0;
struct network_info networks[MAX_NETWORKS];

/**
 * This function takes in the signal strength and converts it
 * to a human-readable string.
 */
char* get_signal_strength(int strength) {
    if (strength >= -50) {
        return "Excellent";
    } else if (strength >= -60) {
        return "Very Good";
    } else if (strength >= -70) {
        return "Good";
    } else if (strength >= -80) {
        return "Fair";
    } else {
        return "Poor";
    }
}

/**
 * This function takes in the name and signal strength of
 * a network and adds it to the list of known networks.
 */
void add_network(char* name, int strength) {
    if (num_networks >= MAX_NETWORKS) {
        printf("Error: maximum number of networks reached!\n");
        return;
    }
    
    // Check if the network already exists in the list.
    for (int i = 0; i < num_networks; i++) {
        if (strcmp(networks[i].name, name) == 0) {
            // If so, update its signal strength.
            networks[i].signal_strength = strength;
            return;
        }
    }
    
    // If not, add it to the list.
    strcpy(networks[num_networks].name, name);
    networks[num_networks].signal_strength = strength;
    num_networks++;
}

/**
 * This function prints out all the known networks and their
 * signal strengths.
 */
void print_networks() {
    printf("List of known networks:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("\t%s: %d dBm (%s)\n", networks[i].name, networks[i].signal_strength, get_signal_strength(networks[i].signal_strength));
    }
}

int main() {
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("--------------------------------\n");
    printf("Enter network name and signal strength (in dBm), separated by a space:\n");
    
    char input[100];
    char* name;
    int strength;
    
    // Read in network data until the user quits.
    while (1) {
        fgets(input, sizeof(input), stdin);
        
        if (strcmp(input, "quit\n") == 0) {
            break;
        }
        
        name = strtok(input, " ");
        strength = atoi(strtok(NULL, " "));
        
        add_network(name, strength);
        print_networks();
    }
    
    printf("Goodbye!\n");
    return 0;
}