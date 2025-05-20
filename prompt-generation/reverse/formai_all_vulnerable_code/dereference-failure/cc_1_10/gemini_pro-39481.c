//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} connection_t;

void *handle_connection(void *arg) {
    connection_t *conn = (connection_t *)arg;

    char buffer[1024];
    int n;

    while ((n = read(conn->sockfd, buffer, sizeof(buffer))) > 0) {
        // Process request
        // ...

        // Send response
        write(conn->sockfd, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, world!", strlen("HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, world!"));
    }

    close(conn->sockfd);
    free(conn);

    return NULL;
}

int main() {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set socket options
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind socket to address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for connections
    listen(sockfd, MAX_CONNECTIONS);

    // Accept connections
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Create thread to handle connection
        pthread_t thread;
        connection_t *conn = malloc(sizeof(connection_t));
        conn->sockfd = newsockfd;
        conn->addr = cli_addr;
        pthread_create(&thread, NULL, handle_connection, (void *)conn);
    }

    // Close socket
    close(sockfd);

    return 0;
}