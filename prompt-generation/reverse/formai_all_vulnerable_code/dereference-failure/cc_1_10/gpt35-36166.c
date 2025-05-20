//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

/* Function to handle the client request */
void handle_request(int client_sockfd, struct sockaddr_in client_addr, char* proxy_ip, int proxy_port) {
    char buffer[BUFFER_SIZE], proxy_buffer[BUFFER_SIZE];
    int proxy_sockfd, recv_len, send_len;
    struct sockaddr_in proxy_addr;

    /* Create a TCP socket to connect to the proxy server */
    if ((proxy_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(1);
    }

    /* Initialize the proxy server address */
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = inet_addr(proxy_ip);
    proxy_addr.sin_port = htons(proxy_port);

    /* Connect to the proxy server */
    if (connect(proxy_sockfd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("Error connecting to proxy server");
        close(proxy_sockfd);
        exit(1);
    }

    /* Send the client request to the proxy server */
    if (send(proxy_sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending request to proxy server");
        close(proxy_sockfd);
        exit(1);
    }

    /* Receive the response from the proxy server */
    if ((recv_len = recv(proxy_sockfd, proxy_buffer, BUFFER_SIZE, 0)) == -1) {
        perror("Error receiving response from proxy server");
        close(proxy_sockfd);
        exit(1);
    }

    /* Send the response back to the client */
    if ((send_len = send(client_sockfd, proxy_buffer, recv_len, 0)) == -1) {
        perror("Error sending response to client");
        close(proxy_sockfd);
        exit(1);
    }

    /* Close the proxy server socket */
    close(proxy_sockfd);
}

int main(int argc, char *argv[]) {
    int sockfd, client_sockfd, client_len;
    struct sockaddr_in server_addr, client_addr;

    /* Check if the correct number of arguments have been passed in */
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <proxy server ip> <proxy server port>\n", argv[0]);
        exit(1);
    }

    /* Initialize the server address */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    /* Create a TCP socket for the proxy server */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(1);
    }

    /* Bind the socket to the server address */
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        close(sockfd);
        exit(1);
    }

    /* Listen for incoming connections */
    if (listen(sockfd, 5) == -1) {
        perror("Error listening for connections");
        close(sockfd);
        exit(1);
    }

    while (1) {
        client_len = sizeof(client_addr);

        /* Accept incoming connections */
        if ((client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("Error accepting connection");
            close(sockfd);
            exit(1);
        }

        /* Receive the client request */
        char buffer[BUFFER_SIZE];
        int recv_len;
        if ((recv_len = recv(client_sockfd, buffer, BUFFER_SIZE, 0)) == -1) {
            perror("Error receiving client request");
            close(client_sockfd);
            continue;
        }

        /* Print the client request */
        buffer[recv_len] = '\0';
        printf("%s", buffer);

        /* Handle the client request */
        handle_request(client_sockfd, client_addr, argv[1], atoi(argv[2]));

        /* Close the client socket */
        close(client_sockfd);
    }

    /* Close the server socket */
    close(sockfd);

    return 0;
}