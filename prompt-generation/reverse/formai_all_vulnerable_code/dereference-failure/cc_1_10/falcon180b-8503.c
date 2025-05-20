//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int n, len;
    char *host;
    char *port;
    int opt = 1;
    int addrlen = sizeof(cli_addr);

    if (argc < 3) {
        printf("Usage:./server <IP Address> <Port>\n");
        exit(0);
    }

    host = argv[1];
    port = argv[2];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("socket failed\n");
        exit(0);
    }

    // Set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("setsockopt");
        exit(0);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(atoi(port));

    // Bind
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Bind failed\n");
        exit(0);
    }

    // Listen
    if (listen(sockfd, 5) < 0) {
        printf("Listen failed\n");
        exit(0);
    }

    while (1) {
        // Accept a connection
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen)) < 0) {
            printf("Accept failed\n");
            exit(0);
        }

        printf("Connection accepted\n");

        // Receive data from client
        n = 0;
        while ((len = recv(newsockfd, buffer + n, BUFFER_SIZE - n, 0)) > 0) {
            n += len;
        }

        // Send data to client
        send(newsockfd, buffer, strlen(buffer), 0);

        // Close connection
        close(newsockfd);
    }

    return 0;
}