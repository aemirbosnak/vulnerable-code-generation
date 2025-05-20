//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <unistd.h>

#define MAX_CONNECTIONS 10

void handle_connection(int sockfd) {
    // Read the request from the client
    char buffer[1024];
    int n = recv(sockfd, buffer, 1024, 0);
    if (n < 0) {
        perror("recv");
        close(sockfd);
        return;
    }

    // Parse the request
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *protocol = strtok(NULL, " ");

    // Check if the request is valid
    if (strcmp(method, "GET") != 0 || strcmp(protocol, "HTTP/1.1") != 0) {
        send(sockfd, "HTTP/1.1 400 Bad Request\n\n", 28, 0);
        close(sockfd);
        return;
    }

    // Check if the path is valid
    if (strcmp(path, "/") != 0 && strcmp(path, "/index.html") != 0) {
        send(sockfd, "HTTP/1.1 404 Not Found\n\n", 26, 0);
        close(sockfd);
        return;
    }

    // Send the response to the client
    char *response = "HTTP/1.1 200 OK\nContent-Length: 13\nContent-Type: text/plain\n\nHello, world!\n";
    send(sockfd, response, strlen(response), 0);

    // Close the connection
    close(sockfd);
}

int main(int argc, char *argv[]) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sockfd);
        return -1;
    }

    // Listen for connections
    if (listen(sockfd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        close(sockfd);
        return -1;
    }

    // Accept connections
    while (1) {
        int newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        // Handle the connection in a separate thread
        pthread_t tid;
        pthread_create(&tid, NULL, (void *(*)(void *))handle_connection, (void *)newsockfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}