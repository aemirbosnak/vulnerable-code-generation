//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the maximum number of rules in the firewall
#define MAX_RULES 100

// Define the structure of a firewall rule
struct firewall_rule {
    char *source_ip;
    char *destination_ip;
    int source_port;
    int destination_port;
    char *protocol;
    char *action;
};

// Define the firewall rules
struct firewall_rule firewall_rules[MAX_RULES];

// Initialize the firewall rules
void init_firewall_rules() {
    // Add a rule to allow traffic from any source to destination IP 192.168.1.100 on port 80
    strcpy(firewall_rules[0].source_ip, "0.0.0.0/0");
    strcpy(firewall_rules[0].destination_ip, "192.168.1.100");
    firewall_rules[0].source_port = 0;
    firewall_rules[0].destination_port = 80;
    strcpy(firewall_rules[0].protocol, "tcp");
    strcpy(firewall_rules[0].action, "allow");

    // Add a rule to block traffic from source IP 192.168.1.101 to any destination on port 22
    strcpy(firewall_rules[1].source_ip, "192.168.1.101");
    strcpy(firewall_rules[1].destination_ip, "0.0.0.0/0");
    firewall_rules[1].source_port = 0;
    firewall_rules[1].destination_port = 22;
    strcpy(firewall_rules[1].protocol, "tcp");
    strcpy(firewall_rules[1].action, "block");
}

// Check if a packet matches a firewall rule
int check_firewall_rules(char *source_ip, char *destination_ip, int source_port, int destination_port, char *protocol) {
    int i;

    // Iterate over the firewall rules
    for (i = 0; i < MAX_RULES; i++) {
        // Check if the packet matches the rule
        if (strcmp(firewall_rules[i].source_ip, source_ip) == 0 && strcmp(firewall_rules[i].destination_ip, destination_ip) == 0 && firewall_rules[i].source_port == source_port && firewall_rules[i].destination_port == destination_port && strcmp(firewall_rules[i].protocol, protocol) == 0) {
            // Return the action specified in the rule
            return strcmp(firewall_rules[i].action, "allow") == 0 ? 1 : 0;
        }
    }

    // If no rule matches, return -1
    return -1;
}

// Main function
int main() {
    // Initialize the firewall rules
    init_firewall_rules();

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to an IP address and port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = inet_addr("192.168.1.100");
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sockfd;
    while ((client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len)) != -1) {
        // Get the source IP address and port of the incoming connection
        char source_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, source_ip, INET_ADDRSTRLEN);
        int source_port = ntohs(client_addr.sin_port);

        // Get the destination IP address and port of the incoming connection
        char destination_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &addr.sin_addr, destination_ip, INET_ADDRSTRLEN);
        int destination_port = ntohs(addr.sin_port);

        // Get the protocol of the incoming connection
        char protocol[10];
        if (getsockopt(client_sockfd, IPPROTO_TCP, SO_PROTOCOL, protocol, &client_addr_len) == -1) {
            perror("getsockopt");
            exit(1);
        }

        // Check if the incoming connection matches a firewall rule
        int action = check_firewall_rules(source_ip, destination_ip, source_port, destination_port, protocol);

        // Take action based on the firewall rule
        if (action == 1) {
            // Allow the connection
            printf("Allowing connection from %s:%d to %s:%d\n", source_ip, source_port, destination_ip, destination_port);
        } else if (action == 0) {
            // Block the connection
            printf("Blocking connection from %s:%d to %s:%d\n", source_ip, source_port, destination_ip, destination_port);
            close(client_sockfd);
        } else {
            // Drop the connection
            printf("Dropping connection from %s:%d to %s:%d\n", source_ip, source_port, destination_ip, destination_port);
            close(client_sockfd);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}