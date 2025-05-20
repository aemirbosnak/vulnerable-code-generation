//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_DATA_SIZE];
    int len;
    int opt = 1;

    if (argc < 2) {
        printf("Usage:./server <port number>\n");
        exit(0);
    }

    portno = atoi(argv[1]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        printf("Error: Socket creation failed\n");
        exit(0);
    }

    printf("Socket created\n");

    // Set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error: setsockopt failed\n");
        exit(0);
    }

    printf("setsockopt done\n");

    // Bind the socket to an address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Bind failed\n");
        exit(0);
    }

    printf("Bind done\n");

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        printf("Error: Listen failed\n");
        exit(0);
    }

    printf("Listen done\n");

    // Accept a connection
    len = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &len);
    if (newsockfd < 0) {
        printf("Error: Accept failed\n");
        exit(0);
    }

    printf("Connection accepted\n");

    // Receive data from client
    while (1) {
        memset(buffer, 0, MAX_DATA_SIZE);
        len = recv(newsockfd, buffer, MAX_DATA_SIZE, 0);
        if (len <= 0) {
            printf("Connection closed by client\n");
            break;
        }
        printf("Received data: %s\n", buffer);
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}