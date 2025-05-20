//FormAI DATASET v1.0 Category: Firewall ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

// Define the maximum data buffer size
#define BUFFER_SIZE 1024

// Define the maximum number of rules
#define MAX_RULES 1000

// Define the rule structure
typedef struct {
    char *protocol;
    char *src_ip;
    char *dest_ip;
    int src_port;
    int dest_port;
} firewall_rule;

// Define the firewall rule list
firewall_rule rules[MAX_RULES];

// Define the number of rules
int num_rules = 0;

// Add a new firewall rule
void add_rule(char *protocol, char *src_ip, char *dest_ip, int src_port, int dest_port) {
    // Check if the rule list is full
    if (num_rules == MAX_RULES) {
        printf("Error: Maximum number of rules exceeded.\n");
        return;
    }

    // Allocate memory for the new rule
    firewall_rule *new_rule = malloc(sizeof(firewall_rule));

    // Initialize the new rule
    new_rule->protocol = strdup(protocol);
    new_rule->src_ip = strdup(src_ip);
    new_rule->dest_ip = strdup(dest_ip);
    new_rule->src_port = src_port;
    new_rule->dest_port = dest_port;

    // Add the new rule to the rule list
    rules[num_rules++] = *new_rule;

    // Print the new rule
    printf("Rule Added: %s %s:%d -> %s:%d\n", new_rule->protocol, new_rule->src_ip, new_rule->src_port, new_rule->dest_ip, new_rule->dest_port);
}

// Check if a packet matches a rule
int match_rule(char *protocol, char *src_ip, char *dest_ip, int src_port, int dest_port) {
    // Loop through all the rules
    for (int i = 0; i < num_rules; i++) {
        // Check if the rule matches the packet
        if ((strcmp(rules[i].protocol, protocol) == 0) &&
            (strcmp(rules[i].src_ip, src_ip) == 0) &&
            (strcmp(rules[i].dest_ip, dest_ip) == 0) &&
            (rules[i].src_port == 0 || rules[i].src_port == src_port) &&
            (rules[i].dest_port == 0 || rules[i].dest_port == dest_port)) {
                return 1;
        }
    }

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Parse the port number
    int port = atoi(argv[1]);

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

    // Check if the socket was created
    if (sockfd < 0) {
        perror("Error");
        return 1;
    }

    // Configure the network address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to the network address
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error");
        return 1;
    }

    // Receive packets and filter them
    while (1) {
        // Define the data buffer
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        // Receive the packet into the data buffer
        ssize_t num_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

        // Check if the packet was received
        if (num_bytes < 0) {
            perror("Error");
            return 1;
        }

        // Get the IP header
        struct iphdr *ip_hdr = (struct iphdr *)buffer;

        // Get the TCP header
        struct tcphdr *tcp_hdr = (struct tcphdr *)(buffer + ip_hdr->ihl * 4);

        // Check if the packet matches a rule
        if (match_rule("TCP", inet_ntoa(*(struct in_addr *)&ip_hdr->saddr), inet_ntoa(*(struct in_addr *)&ip_hdr->daddr), ntohs(tcp_hdr->source), ntohs(tcp_hdr->dest))) {
            printf("Blocked: TCP %s:%d -> %s:%d\n", inet_ntoa(*(struct in_addr *)&ip_hdr->saddr), ntohs(tcp_hdr->source), inet_ntoa(*(struct in_addr *)&ip_hdr->daddr), ntohs(tcp_hdr->dest));
        } else {
            printf("Accepted: TCP %s:%d -> %s:%d\n", inet_ntoa(*(struct in_addr *)&ip_hdr->saddr), ntohs(tcp_hdr->source), inet_ntoa(*(struct in_addr *)&ip_hdr->daddr), ntohs(tcp_hdr->dest));
        }
    }

    return 0;
}