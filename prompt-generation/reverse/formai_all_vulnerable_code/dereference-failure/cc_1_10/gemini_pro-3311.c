//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

typedef struct {
    char *ip_address;
    int port;
} FirewallRule;

int main() {
    // Initialize the firewall rules
    FirewallRule rules[] = {
        {"192.168.1.1", 80},
        {"192.168.1.2", 443},
        {"192.168.1.3", 22}
    };
    int num_rules = sizeof(rules) / sizeof(FirewallRule);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to the any address and port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(5000);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming packets
    while (1) {
        // Receive a packet
        char buffer[1024];
        struct sockaddr_in sender_addr;
        socklen_t sender_addr_len = sizeof(sender_addr);
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&sender_addr, &sender_addr_len);
        if (n < 0) {
            perror("Error receiving packet");
            continue;
        }

        // Parse the packet
        char *ip_address = inet_ntoa(sender_addr.sin_addr);
        int port = ntohs(sender_addr.sin_port);
        char *data = buffer + n;

        // Check if the packet is allowed
        int allowed = 0;
        for (int i = 0; i < num_rules; i++) {
            if (strcmp(ip_address, rules[i].ip_address) == 0 && port == rules[i].port) {
                allowed = 1;
            }
        }

        // Respond to the packet
        if (allowed) {
            sendto(sockfd, "Allowed", 7, 0, (struct sockaddr *)&sender_addr, sender_addr_len);
        } else {
            sendto(sockfd, "Denied", 6, 0, (struct sockaddr *)&sender_addr, sender_addr_len);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}