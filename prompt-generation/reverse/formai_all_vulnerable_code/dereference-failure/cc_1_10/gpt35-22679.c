//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

// Structure for holding ping packet information
struct packet
{
    struct icmphdr header;
    char message[64 - sizeof(struct icmphdr)];
};

// Function for calculating the checksum of the packet
unsigned short calculate_checksum(unsigned short *buffer, int length)
{
    unsigned long sum = 0;
    while (length > 1) {
        sum += *buffer++;
        length -= 2;
    }

    if (length == 1) {
        sum += *(unsigned char *)buffer;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

// Function for sending the ping packet and receiving the response
void send_ping(int socket, struct sockaddr_in addr, int packet_id, int packet_seq)
{
    // Initialize the ping packet
    struct packet ping_packet = {0};
    ping_packet.header.type = ICMP_ECHO;
    ping_packet.header.code = 0;
    ping_packet.header.un.echo.id = htons(packet_id);
    ping_packet.header.un.echo.sequence = htons(packet_seq);
    strcpy(ping_packet.message, "Hello from Alan Turing");

    // Calculate the checksum
    ping_packet.header.checksum = calculate_checksum((unsigned short *)&ping_packet, sizeof(ping_packet));

    // Send the packet
    sendto(socket, &ping_packet, sizeof(ping_packet), 0, (struct sockaddr *)&addr, sizeof(addr));

    // Receive the response
    char buffer[1024] = {0};
    socklen_t addrlen = sizeof(addr);
    ssize_t bytes_received = recvfrom(socket, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addrlen);

    // Check the response
    if (bytes_received > sizeof(struct icmphdr)) {
        struct icmphdr *icmp_header = (struct icmphdr *)(buffer + sizeof(struct iphdr));
        if (icmp_header->type == ICMP_ECHOREPLY) {
            printf("Received ping response from %s\n", inet_ntoa(addr.sin_addr));
        }
    }
}

int main(int argc, char *argv[])
{
    // Check the arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname/IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the socket
    int socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (socket_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get the address info
    struct addrinfo hints;
    struct addrinfo *results;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;

    if (getaddrinfo(argv[1], NULL, &hints, &results) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    // Iterate over the addresses
    int packet_id = (int)getpid();
    int packet_seq = 0;
    struct addrinfo *curr;
    for (curr = results; curr != NULL; curr = curr->ai_next) {
        if (curr->ai_family != AF_INET) {
            continue;
        }

        struct sockaddr_in *addr = (struct sockaddr_in *)curr->ai_addr;
        printf("Pinging %s\n", inet_ntoa(addr->sin_addr));

        send_ping(socket_fd, *addr, packet_id, packet_seq++);
        sleep(1);
    }

    // Clean up
    freeaddrinfo(results);
    close(socket_fd);

    return 0;
}