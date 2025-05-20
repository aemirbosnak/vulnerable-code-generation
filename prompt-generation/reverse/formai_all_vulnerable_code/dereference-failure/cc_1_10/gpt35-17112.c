//FormAI DATASET v1.0 Category: Firewall ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 65536

void die_with_error(const char *error_msg) {
    perror(error_msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *port_str = argv[1];
    const int port = atoi(port_str);
    if (port == 0) {
        fprintf(stderr, "Invalid port: %s\n", port_str);
        return EXIT_FAILURE;
    }

    int sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw < 0) {
        die_with_error("Error: Could not create raw socket");
    }

    int sock_udp = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock_udp < 0) {
        die_with_error("Error: Could not create UDP socket");
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    struct sockaddr_in client_address;
    int client_address_len = sizeof(client_address);

    char buffer[BUFFER_SIZE];

    printf("Server started. Listening on port %d...\n", port);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        const int recv_len = recvfrom(sock_raw, buffer, BUFFER_SIZE, MSG_DONTWAIT, (struct sockaddr *)&client_address, &client_address_len);
        if (recv_len > 0) {
            struct iphdr *ip_header = (struct iphdr *)buffer;
            const int ip_header_len = ip_header->ihl * 4;

            struct tcphdr *tcp_header = (struct tcphdr *)(buffer + ip_header_len);

            if (tcp_header->dest == htons(port)) {
                printf("Warning: Incoming TCP packet from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                continue;
            }
        }

        const int recvfrom_len = recvfrom(sock_udp, buffer, BUFFER_SIZE, MSG_DONTWAIT, (struct sockaddr *)&client_address, &client_address_len);
        if (recvfrom_len > 0) {
            printf("Warning: Incoming UDP packet from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            continue;
        }

        usleep(10);
    }

    close(sock_raw);
    close(sock_udp);
    return EXIT_SUCCESS;
}