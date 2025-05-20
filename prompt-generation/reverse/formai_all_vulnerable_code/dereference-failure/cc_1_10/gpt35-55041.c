//FormAI DATASET v1.0 Category: Firewall ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    const int port = atoi(argv[1]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation error");
        return 1;
    }

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Socket bind error");
        return 1;
    }

    if (listen(sock, 1) < 0) {
        perror("Listen error");
        return 1;
    }

    printf("[INFO] Firewall started.\n");

    while (1) {

        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);

        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &addr_len);
        if (client_sock < 0) {
            perror("Accept error");
            continue;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);

        printf("[INFO] Client connected: %s:%d\n", client_ip, ntohs(client_addr.sin_port));

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        ssize_t bytes_recv = recv(client_sock, buffer, BUFFER_SIZE, 0);
        if (bytes_recv <= 0) {
            perror("Receive error");
            close(client_sock);
            continue;
        }

        // Apply firewall rules here
        if (strstr(buffer, "attack") != NULL) {
            // Attack detected, drop the packet
            close(client_sock);
            printf("[INFO] Connection from %s dropped due to attack!\n", client_ip);
        } else {
            // Non-malicious packet, forward it
            ssize_t bytes_sent = send(client_sock, buffer, bytes_recv, 0);
            if (bytes_sent < 0) {
                perror("Send error");
            }

            printf("[INFO] Packet forwarded from %s.\n", client_ip);
        }

        close(client_sock);

    }

    close(sock);
    return 0;
}