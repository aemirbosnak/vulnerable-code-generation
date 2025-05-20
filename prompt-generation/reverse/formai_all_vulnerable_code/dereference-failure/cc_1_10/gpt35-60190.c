//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char* argv[]) {

    /* Variables for handling sockets */
    int proxy_sockfd, client_sockfd, server_sockfd;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFSIZ];

    /* Arguments handling */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Creating the proxy socket */
    proxy_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sockfd == -1) {
        perror("Proxy socket creation failed");
        exit(EXIT_FAILURE);
    }

    /* Configuring the proxy address*/
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(atoi(argv[1]));

    /* Binding the proxy */
    if (bind(proxy_sockfd, (struct sockaddr*) &proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("Proxy binding failed");
        exit(EXIT_FAILURE);
    }

    /* Listening to incoming connections */
    if (listen(proxy_sockfd, 5) == -1) {
        perror("Proxy listening failed");
        exit(EXIT_FAILURE);
    }

    while (1) {

        /* Accepting incoming client connection */
        client_sockfd = accept(proxy_sockfd, (struct sockaddr*) &client_addr, &client_len);
        if (client_sockfd == -1) {
            perror("Client connection acceptation failed");
            continue;
        }

        printf("New client connected (%s:%d)\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        /* Connection to remote server */
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP of the remote server
        server_addr.sin_port = htons(80); // HTTP server port

        server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd == -1) {
            perror("Server socket creation failed");
            exit(EXIT_FAILURE);
        }

        if (connect(server_sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
            perror("Server connection failed");
            exit(EXIT_FAILURE);
        }

        printf("Connected to remote server\n");

        /* Forwarding HTTP request */
        memset(buffer, 0, BUFSIZ);
        recv(client_sockfd, buffer, BUFSIZ, 0);
        send(server_sockfd, buffer, strlen(buffer), 0);

        printf("HTTP request forwarded to server\n");

        /* Forwarding server's response */
        memset(buffer, 0, BUFSIZ);
        recv(server_sockfd, buffer, BUFSIZ, 0);
        send(client_sockfd, buffer, strlen(buffer), 0);

        printf("HTTP response forwarded to client\n");

        /* Closing communication sockets */
        close(client_sockfd);
        close(server_sockfd);

    }

    close(proxy_sockfd);
    return 0;
}