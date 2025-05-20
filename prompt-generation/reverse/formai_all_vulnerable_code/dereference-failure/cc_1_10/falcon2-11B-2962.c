//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <target> <start> <end>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the target and port range
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the target
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Scan the port range
    for (int port = atoi(argv[2]); port <= atoi(argv[3]); port++) {
        struct sockaddr_in client;
        client.sin_family = AF_INET;
        client.sin_port = htons(port);
        client.sin_addr.s_addr = INADDR_ANY;

        // Create the socket for the client
        int client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (client_sockfd == -1) {
            perror("socket");
            exit(EXIT_FAILURE);
        }

        // Connect to the client
        if (connect(client_sockfd, (struct sockaddr *)&client, sizeof(client)) < 0) {
            perror("connect");
            exit(EXIT_FAILURE);
        }

        // Send a request to the server
        char request[1024] = "GET / HTTP/1.1\r\nHost: ";
        strcat(request, argv[1]);
        strcat(request, "\r\n\r\n");
        send(sockfd, request, strlen(request), 0);

        // Receive the response from the server
        char response[1024];
        if (recv(sockfd, response, sizeof(response), 0) < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        // Check the response code
        if (response[0] == '1' && response[1] == '0') {
            printf("%s:%d is open\n", argv[1], port);
        }

        // Close the client socket
        close(client_sockfd);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}