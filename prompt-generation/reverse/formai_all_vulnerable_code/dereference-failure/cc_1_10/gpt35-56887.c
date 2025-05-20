//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr, client_addr;
    int server_sockfd, client_sockfd, client_len, recv_len;
    char recv_buf[BUFSIZE];

    // Create a socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the server address
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_sockfd, 5) < 0) {
        printf("Error listening for connections\n");
        return 1;
    }

    printf("Server started and is listening for incoming connections...\n");

    while (1) {
        // Accept incoming connection
        client_len = sizeof(client_addr);
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (client_sockfd < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        // Receive data from client
        while ((recv_len = recv(client_sockfd, recv_buf, BUFSIZE, 0)) > 0) {
            // Analyze received data and output QoS metrics
            printf("Received %d bytes from client %s:%d\n", recv_len,
                   inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            // Randomly simulate QoS metrics and output
            int latency = rand() % 100 + 1;
            int jitter = rand() % 50 + 1;
            int packet_loss = rand() % 10 + 1;

            printf("QoS Metrics for client %s:%d:\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            printf("Latency: %d ms\n", latency);
            printf("Jitter: %d ms\n", jitter);
            printf("Packet loss: %d%%\n", packet_loss);
        }

        close(client_sockfd);
    }

    close(server_sockfd);
    return 0;
}