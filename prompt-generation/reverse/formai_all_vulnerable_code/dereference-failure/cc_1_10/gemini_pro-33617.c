//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// Linus Torvalds style macros and definitions
#define MAX_LINE_LENGTH 1024
#define MAX_HOSTNAME_LENGTH 255
#define MAX_IP_ADDRESS_LENGTH 15

// Structure to store network topology information
typedef struct network_topology {
    char hostname[MAX_HOSTNAME_LENGTH];
    char ip_address[MAX_IP_ADDRESS_LENGTH];
    struct network_topology *next;
} network_topology;

// Function to get the hostname of the current host
char *get_hostname(void) {
    char hostname[MAX_HOSTNAME_LENGTH];
    if (gethostname(hostname, MAX_HOSTNAME_LENGTH) != 0) {
        perror("gethostname");
        exit(EXIT_FAILURE);
    }
    return strdup(hostname);
}

// Function to get the IP address of the current host
char *get_ip_address(void) {
    struct hostent *hostent;
    char *hostname = get_hostname();
    if ((hostent = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    return inet_ntoa(*(struct in_addr *)*hostent->h_addr_list);
}

// Function to add a new network topology entry
network_topology *add_network_topology_entry(network_topology *head, char *hostname, char *ip_address) {
    network_topology *new_entry = malloc(sizeof(network_topology));
    if (new_entry == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(new_entry->hostname, hostname);
    strcpy(new_entry->ip_address, ip_address);
    new_entry->next = head;
    return new_entry;
}

// Function to print the network topology
void print_network_topology(network_topology *head) {
    network_topology *current = head;
    while (current != NULL) {
        printf("%s (%s)\n", current->hostname, current->ip_address);
        current = current->next;
    }
}

// Function to free the network topology
void free_network_topology(network_topology *head) {
    network_topology *current = head;
    while (current != NULL) {
        network_topology *next = current->next;
        free(current);
        current = next;
    }
}

int main(void) {
    network_topology *head = NULL;
    char *hostname = get_hostname();
    char *ip_address = get_ip_address();
    head = add_network_topology_entry(head, hostname, ip_address);

    if (head == NULL) {
        fprintf(stderr, "Error: could not add network topology entry for %s (%s)\n", hostname, ip_address);
        exit(EXIT_FAILURE);
    }

    print_network_topology(head);

    free_network_topology(head);

    return EXIT_SUCCESS;
}