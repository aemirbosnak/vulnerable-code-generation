//MISTRAL-7B DATASET v1.0 Category: Firewall ; Style: ephemeral
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUF_SIZE 1024
#define FILTER "evil"

int main() {
    int sockfd, new_sockfd, client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];
    char *message = "You've been hacked!";

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Start listening for connections
    listen(sockfd, 5);

    printf("Firewall started on port %d\n", PORT);

    while (1) {
        // Accept new connection
        client_len = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (new_sockfd < 0) {
            perror("accept");
            continue;
        }

        // Read incoming packet
        recv(new_sockfd, buffer, BUF_SIZE, 0);

        // Check for forbidden word in packet
        char *packet = strtok(buffer, " ");
        if (strstr(packet, FILTER) != NULL) {
            send(new_sockfd, message, strlen(message), 0);
            close(new_sockfd);
            continue;
        }

        // If no forbidden word found, process packet normally
        printf("Packet from %s:%d: %s\n", inet_ntoa(client_addr.sin_addr),
               ntohs(client_addr.sin_port), buffer);

        // Process packet here

        // Close connection
        close(new_sockfd);
    }

    return 0;
}