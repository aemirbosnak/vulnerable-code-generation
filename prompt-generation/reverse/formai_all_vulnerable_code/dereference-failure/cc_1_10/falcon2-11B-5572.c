//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void send_message(int sockfd, const char* message) {
    send(sockfd, message, strlen(message), 0);
}

void receive_message(int sockfd, char* buffer, int length) {
    int n = recv(sockfd, buffer, length, 0);
    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    char message[] = "Hello, World!";

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[1]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int client_fd = accept(sockfd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Received connection from %s\n", inet_ntoa(serv_addr.sin_addr));

        while (1) {
            receive_message(client_fd, buffer, sizeof(buffer));
            printf("Received: %s\n", buffer);
            send_message(client_fd, message);
            printf("Sent: %s\n", message);
        }

        close(client_fd);
    }

    close(sockfd);
    return 0;
}