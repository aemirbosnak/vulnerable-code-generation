//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address/subnet>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    struct in_addr inet_addr;

    if (inet_pton(AF_INET, ip_address, &inet_addr) <= 0) {
        printf("Invalid IP address.\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7); // Echo port
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        sendto(sock, "PING", strlen("PING"), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        bytes_received = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (bytes_received <= 0) {
            printf("No response from %s.\n", inet_ntoa(server_addr.sin_addr));
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Response from %s: %s\n", inet_ntoa(server_addr.sin_addr), buffer);
    }

    close(sock);
    return 0;
}