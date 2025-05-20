//GEMINI-pro DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// A simple echo server that prints the client's message back to them.

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the socket to the port.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for connections.
    if (listen(sockfd, 5) == -1)
    {
        perror("listen");
        return EXIT_FAILURE;
    }

    printf("Echo server listening on port %d.\n", port);

    // Accept connections and echo messages back to the clients.
    while (1)
    {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1)
        {
            perror("accept");
            continue;
        }

        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));

        // Receive a message from the client.
        int n = recv(client_sockfd, buffer, sizeof(buffer), 0);
        if (n == -1)
        {
            perror("recv");
            close(client_sockfd);
            continue;
        }

        // Print the client's message.
        printf("Received message from %s:%d: %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);

        // Echo the message back to the client.
        if (send(client_sockfd, buffer, n, 0) == -1)
        {
            perror("send");
            close(client_sockfd);
            continue;
        }

        // Close the client socket.
        close(client_sockfd);
    }

    // Close the server socket.
    close(sockfd);

    return EXIT_SUCCESS;
}