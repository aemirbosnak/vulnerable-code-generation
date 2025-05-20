//Falcon-180B DATASET v1.0 Category: Networking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int addrlen;
    int max_clients = 3;
    int listener = 0;
    int *client_socket = (int *)malloc(max_clients * sizeof(int));

    if (argc < 2) {
        printf("Usage:./server <port number>\n");
        exit(0);
    }

    portno = atoi(argv[1]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        printf("socket failed\n");
        exit(0);
    }

    puts("socket created");

    // Set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind server address to socket
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("bind failed\n");
        exit(0);
    }

    puts("bind done");

    // Listen on socket
    if (listen(sockfd, max_clients) < 0) {
        printf("listen failed\n");
        exit(0);
    }

    puts("listen done");

    while (1) {
        // Accept a connection
        addrlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);

        if (newsockfd < 0) {
            printf("accept failed\n");
            exit(0);
        }

        puts("Connection accepted");

        // Add socket to list of client sockets
        for (int i = 0; i < max_clients; i++) {
            if (client_socket[i] == 0) {
                client_socket[i] = newsockfd;
                listener = 1;
                break;
            }
        }

        if (listener == 0) {
            printf("Maximum clients reached\n");
            close(newsockfd);
        }
    }
}