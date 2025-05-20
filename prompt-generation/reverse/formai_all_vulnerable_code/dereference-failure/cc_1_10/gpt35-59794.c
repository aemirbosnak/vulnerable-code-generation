//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define DEFAULT_PORT "8080"
#define PACKET_SIZE 1024

int main(int argc, char *argv[]) {

    char *port = DEFAULT_PORT;

    if (argc == 2) {
        port = argv[1];
    }

    int sock_fd;
    struct sockaddr_in server_address;

    sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(port));
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock_fd, SOMAXCONN) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %s...\n", port);

    struct sockaddr_storage client_address;
    socklen_t client_address_len = sizeof(client_address);

    char buffer[PACKET_SIZE];

    while (1) {

        int client_fd = accept(sock_fd, (struct sockaddr*)&client_address, &client_address_len);

        if (client_fd == -1) {
            perror("Failed to accept client socket");
            continue;
        }

        char *client_ip = inet_ntoa(((struct sockaddr_in *)&client_address)->sin_addr);

        printf("Accepted client connection from %s\n", client_ip);

        ssize_t bytes_received;
        int total_bytes_received = 0;
        while ((bytes_received = recv(client_fd, buffer, PACKET_SIZE, 0)) > 0) {

            total_bytes_received += bytes_received;
            printf("Received (%d bytes): %s", (int)bytes_received, buffer);

            if (send(client_fd, buffer, bytes_received, 0) == -1) {
                perror("Failed to respond to client");
                close(client_fd);
                break;
            }
        }

        printf("Client %s disconnected. Total bytes received: %d\n", client_ip, total_bytes_received);

        close(client_fd);
    }

    close(sock_fd);
    return 0;
}