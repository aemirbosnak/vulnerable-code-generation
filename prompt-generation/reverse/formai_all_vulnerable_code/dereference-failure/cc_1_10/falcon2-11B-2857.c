//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Check if proper number of arguments are passed
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    // Get the IP address of the server
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error resolving server address\n");
        return 1;
    }

    // Create an IP address structure
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    bcopy((char *)server->h_addr, (char *)&addr.sin_addr.s_addr, server->h_length);

    // Set the size of the buffer for receiving packets
    int size = 1024;

    // Create a packet
    char packet[size];

    // Loop indefinitely to receive packets
    while (1) {
        // Receive a packet
        int n = recvfrom(sockfd, packet, size, 0, NULL, NULL);
        if (n <= 0) {
            fprintf(stderr, "Error receiving packet\n");
            continue;
        }

        // Print the packet details
        fprintf(stdout, "Packet received with size %d\n", n);
        fprintf(stdout, "Timestamp: %ld\n", ntohl(packet[0]));
        fprintf(stdout, "Packet number: %d\n", ntohl(packet[1]));
        fprintf(stdout, "Latency: %ld\n", ntohl(packet[2]));
        fprintf(stdout, "Jitter: %ld\n", ntohl(packet[3]));
        fprintf(stdout, "----------------------------\n");
    }

    // Close the socket
    close(sockfd);

    return 0;
}