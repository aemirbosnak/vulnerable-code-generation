//FormAI DATASET v1.0 Category: Firewall ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <errno.h>

#define BUFFER_SIZE 1024 // Define buffer size
#define SOURCE_PORT 1234 // Define source port
#define SOURCE_IP "127.0.0.1" // Define source IP
#define DESTINATION_PORT 80 // Define destination port
#define DESTINATION_IP "10.0.0.1" // Define destination IP

int main()
{
    int sockfd, source_port, destination_port;
    socklen_t len;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set the source port
    source_port = htons(SOURCE_PORT);

    // Set the destination port
    destination_port = htons(DESTINATION_PORT);

    // Set the address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = destination_port;
    addr.sin_addr.s_addr = inet_addr(DESTINATION_IP);

    // Bind the socket to the port
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for incoming packets
    len = sizeof(struct sockaddr);
    if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&addr, &len) < 0) {
        printf("Error receiving packet\n");
        exit(1);
    }

    // Check if packet is TCP
    struct iphdr *ipheader = (struct iphdr *)buffer;
    struct tcphdr *tcpheader = (struct tcphdr *)(buffer + sizeof(struct iphdr));
    if (ipheader->protocol == IPPROTO_TCP) {

        // Check if packet is from allowed source IP and port
        if (strcmp(inet_ntoa(ipheader->saddr), SOURCE_IP) == 0 && tcpheader->source == source_port) {

            // Check if packet is going to allowed destination IP and port
            if (strcmp(inet_ntoa(ipheader->daddr), DESTINATION_IP) == 0 && tcpheader->dest == destination_port) {

                // Drop packet if all conditions are met
                printf("Packet Dropped!\n");

            } else {

                // Allow packet if destination IP and port don't match
                printf("Packet Allowed!\n");
            }

        } else {

            // Allow packet if source IP and port don't match
            printf("Packet Allowed!\n");
        }

    } else {

        // Allow packet if not TCP
        printf("Packet Allowed!\n");
    }

    return 0;
}