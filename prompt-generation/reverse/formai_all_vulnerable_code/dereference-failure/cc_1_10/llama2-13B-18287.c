//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if the user has provided the required arguments
    if (argc != 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    // Get the IP address and port number from the user
    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // Create a UDP socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return 2;
    }

    // Set the IP address and port number of the remote host
    struct sockaddr_in remote_addr;
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &remote_addr.sin_addr);

    // Send a packet to the remote host
    char packet[BUFFER_SIZE];
    packet[0] = 'H';
    packet[1] = 'E';
    packet[2] = 'L';
    packet[3] = 'L';
    packet[4] = 'O';
    packet[5] = '!';
    sendto(sock, packet, strlen(packet), 0, (struct sockaddr *)&remote_addr, sizeof(remote_addr));

    // Receive a packet from the remote host
    char buffer[BUFFER_SIZE];
    recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);

    // Print the received packet
    printf("Received packet: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}