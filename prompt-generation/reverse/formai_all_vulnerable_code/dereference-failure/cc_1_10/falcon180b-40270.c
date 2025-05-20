//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME_LENGTH 256
#define MAX_PACKET_SIZE 64
#define TIMEOUT 5 // in seconds

void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s <hostname>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage(argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LENGTH];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LENGTH - 1);
    hostname[MAX_HOSTNAME_LENGTH - 1] = '\0';

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7); // Echo port

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid hostname\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to %s: %s\n", hostname, strerror(errno));
        close(sock);
        return 1;
    }

    char packet[MAX_PACKET_SIZE];
    snprintf(packet, MAX_PACKET_SIZE - 1, "PING %s\r\n", hostname);
    packet[MAX_PACKET_SIZE - 1] = '\0';

    int bytes_sent = send(sock, packet, strlen(packet), 0);
    if (bytes_sent == -1) {
        fprintf(stderr, "Error sending packet: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    char buffer[MAX_PACKET_SIZE];
    memset(buffer, 0, sizeof(buffer));

    int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        fprintf(stderr, "Error receiving response: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    close(sock);

    if (strncmp(buffer, "PING ", 5)!= 0) {
        fprintf(stderr, "Invalid response\n");
        return 1;
    }

    return 0;
}