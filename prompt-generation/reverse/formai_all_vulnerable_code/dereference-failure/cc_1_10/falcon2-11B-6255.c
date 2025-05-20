//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define MAX_PACKET_SIZE 65535

int main() {
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char packet[MAX_PACKET_SIZE];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    // Set up server address struct
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host\n");
        return 2;
    }

    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *) &server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(80);

    // Send a packet
    printf("Sending packet...\n");
    n = sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (n < 0) {
        perror("sendto");
        return 3;
    }

    // Receive the response
    printf("Receiving response...\n");
    memset(packet, 0, MAX_PACKET_SIZE);
    n = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, NULL, NULL);
    if (n < 0) {
        perror("recvfrom");
        return 4;
    }

    // Close the socket
    printf("Closing socket...\n");
    close(sockfd);

    return 0;
}