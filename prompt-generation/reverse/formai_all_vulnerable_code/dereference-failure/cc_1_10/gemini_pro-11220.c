//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

// Structure to store the topology information
typedef struct {
    char *hostname;
    char *ip_address;
    int num_hops;
    struct topology_entry *next;
} topology_entry;

// Function to free the memory allocated for the topology
void free_topology(topology_entry *head) {
    topology_entry *current, *next;

    current = head;
    while (current != NULL) {
        next = current->next;
        free(current->hostname);
        free(current->ip_address);
        free(current);
        current = next;
    }
}

// Function to print the topology
void print_topology(topology_entry *head) {
    topology_entry *current;

    current = head;
    while (current != NULL) {
        printf("%s (%s) - %d hops\n", current->hostname, current->ip_address, current->num_hops);
        current = current->next;
    }
}

// Function to add a new entry to the topology
topology_entry *add_topology_entry(topology_entry *head, char *hostname, char *ip_address, int num_hops) {
    topology_entry *new_entry;

    new_entry = (topology_entry *)malloc(sizeof(topology_entry));
    if (new_entry == NULL) {
        perror("malloc");
        return NULL;
    }

    new_entry->hostname = strdup(hostname);
    new_entry->ip_address = strdup(ip_address);
    new_entry->num_hops = num_hops;
    new_entry->next = head;

    return new_entry;
}

// Function to map the network topology
topology_entry *map_network_topology(char *hostname) {
    struct hostent *host;
    struct in_addr **addr_list;
    char *ip_address;
    int num_hops;

    // Get the host information
    host = gethostbyname(hostname);
    if (host == NULL) {
        herror("gethostbyname");
        return NULL;
    }

    // Get the IP address of the host
    addr_list = (struct in_addr **)host->h_addr_list;
    if (addr_list == NULL) {
        fprintf(stderr, "No IP address found for %s\n", hostname);
        return NULL;
    }

    // Convert the IP address to a string
    ip_address = inet_ntoa(*addr_list[0]);

    // Initialize the number of hops to 0
    num_hops = 0;

    // Return the topology entry
    return add_topology_entry(NULL, hostname, ip_address, num_hops);
}

int main(int argc, char **argv) {
    topology_entry *head;

    // Check if the user provided a hostname
    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Map the network topology
    head = map_network_topology(argv[1]);
    if (head == NULL) {
        return EXIT_FAILURE;
    }

    // Print the topology
    print_topology(head);

    // Free the memory allocated for the topology
    free_topology(head);

    return EXIT_SUCCESS;
}