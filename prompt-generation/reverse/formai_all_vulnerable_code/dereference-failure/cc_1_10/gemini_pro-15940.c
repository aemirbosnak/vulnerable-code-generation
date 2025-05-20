//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

void process_connection(int sockfd) {
    char buffer[1024];
    int n;

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        // Process the data received from the client
        printf("Received %d bytes from client: %s\n", n, buffer);

        // Send a response back to the client
        send(sockfd, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello from the firewall!</h1></body></html>\r\n", strlen("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello from the firewall!</h1></body></html>\r\n"), 0);
    }

    if (n == 0) {
        printf("Client disconnected\n");
    } else {
        printf("recv() failed: %s\n", strerror(errno));
    }
}

int main() {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t addrlen;

    // Create a TCP socket
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        return -1;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt() failed");
        return -1;
    }

    // Bind the socket to the port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind() failed");
        return -1;
    }

    // Listen for connections
    if (listen(listenfd, MAX_CONNECTIONS) < 0) {
        perror("listen() failed");
        return -1;
    }

    printf("Firewall listening on port %d\n", PORT);

    // Accept connections and process them in a loop
    while (1) {
        addrlen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &addrlen)) < 0) {
            perror("accept() failed");
            continue;
        }

        printf("Connection established with client %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        process_connection(connfd);

        // Close the connection
        close(connfd);
    }

    // Close the listening socket
    close(listenfd);

    return 0;
}