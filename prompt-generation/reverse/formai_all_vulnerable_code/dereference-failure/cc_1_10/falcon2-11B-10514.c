//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

void mapTopology(int port) {
    struct hostent *host;
    struct sockaddr_in address;
    char buffer[100];

    printf("Mapping Network Topology...\n");

    // Initialize address structure
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;

    // Create socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Resolve hostname
    host = gethostbyname("localhost");
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Set address
    memcpy((char *)&address.sin_addr, host->h_addr_list[0], host->h_length);

    // Send UDP packet
    int bytes = sendto(sock, "Hello, World!", sizeof("Hello, World!"), 0, (struct sockaddr*)&address, sizeof(address));
    if (bytes < 0) {
        perror("sendto");
        exit(1);
    }

    // Receive UDP packet
    bytes = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
    if (bytes < 0) {
        perror("recvfrom");
        exit(1);
    }

    // Print received data
    printf("Received: %s\n", buffer);

    // Close socket
    close(sock);
}

int main() {
    mapTopology(12345);
    return 0;
}