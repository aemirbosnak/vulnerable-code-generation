//GEMINI-pro DATASET v1.0 Category: Networking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to print the contents of a packet
void print_packet(const unsigned char *packet, int length) {
    printf("\nPacket:\n");
    for (int i = 0; i < length; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

// Function to send a packet
int send_packet(const unsigned char *packet, int length, const char *address, int port) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    // Set the destination address
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr.s_addr = inet_addr(address);

    // Send the packet
    if (sendto(sock, packet, length, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("sendto");
        return -1;
    }

    // Close the socket
    close(sock);

    return 0;
}

// Function to receive a packet
int receive_packet(unsigned char *packet, int length, char *address, int *port) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    // Set the destination address
    struct sockaddr_in my_addr;
    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(*port);
    my_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address
    if (bind(sock, (struct sockaddr *)&my_addr, sizeof(my_addr)) < 0) {
        perror("bind");
        return -1;
    }

    // Receive the packet
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);
    if (recvfrom(sock, packet, length, 0, (struct sockaddr *)&src_addr, &src_addr_len) < 0) {
        perror("recvfrom");
        return -1;
    }

    // Close the socket
    close(sock);

    // Set the address and port of the sender
    strcpy(address, inet_ntoa(src_addr.sin_addr));
    *port = ntohs(src_addr.sin_port);

    return 0;
}

// Main function
int main() {
    // Create a packet
    unsigned char packet[1024];
    int length = 0;
    packet[length++] = 0x01;  // Version
    packet[length++] = 0x01;  // Type
    packet[length++] = 0x00;  // Code
    packet[length++] = 0x00;  // Checksum
    packet[length++] = 0x00;  // Length
    packet[length++] = 0x00;  // Data

    // Send the packet
    if (send_packet(packet, length, "127.0.0.1", 5000) < 0) {
        return -1;
    }

    // Receive the packet
    unsigned char received_packet[1024];
    char address[1024];
    int port;
    if (receive_packet(received_packet, 1024, address, &port) < 0) {
        return -1;
    }

    // Print the packet
    print_packet(received_packet, length);

    return 0;
}