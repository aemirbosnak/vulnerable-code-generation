//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFERSIZE 1024

void handle_client(int sockfd) {
    char buffer[BUFFERSIZE];
    int n;

    printf("Waiting for a connection...\n");
    fflush(stdout);

    while ((n = read(sockfd, buffer, BUFFERSIZE)) > 0) {
        printf("Received: %s\n", buffer);
        fflush(stdout);

        if (strcmp(buffer, "GET / HTTP/1.1\r\n\r\n") == 0) {
            strcpy(buffer, "HTTP/1.1 200 OK\r\n\r\n");
            strcat(buffer, "<html><body><h1>Hello, World!</h1></body></html>");
            send(sockfd, buffer, strlen(buffer), 0);
            printf("Sent: %s\n", buffer);
            fflush(stdout);
        }
    }
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    int opt = 1;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        printf("Waiting for a connection...\n");
        fflush(stdout);

        sockfd = accept(sockfd, (struct sockaddr *) NULL, NULL);
        if (sockfd < 0) {
            perror("accept");
            exit(1);
        }

        handle_client(sockfd);
        close(sockfd);
    }
}