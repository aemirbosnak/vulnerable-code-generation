//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080

void send_message(int sockfd, char* message) {
    int bytes_sent = send(sockfd, message, strlen(message), 0);
    if (bytes_sent < 0) {
        perror("send");
        exit(1);
    }
    printf("Message sent: %s\n", message);
}

int main(int argc, char* argv[]) {
    int sockfd, new_sockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        new_sockfd = accept(sockfd, (struct sockaddr*)&cli_addr, (socklen_t*)&portno);
        if (new_sockfd < 0) {
            perror("accept");
            exit(1);
        }

        send_message(new_sockfd, "Welcome to the server!");

        while (1) {
            bzero(buffer, sizeof(buffer));
            int bytes_recv = recv(new_sockfd, buffer, sizeof(buffer), 0);
            if (bytes_recv <= 0) {
                perror("recv");
                exit(1);
            }

            printf("Received message: %s\n", buffer);

            send_message(new_sockfd, "Reply: ");

            bzero(buffer, sizeof(buffer));
            bytes_recv = recv(new_sockfd, buffer, sizeof(buffer), 0);
            if (bytes_recv <= 0) {
                perror("recv");
                exit(1);
            }

            printf("Reply: %s\n", buffer);
        }
    }

    return 0;
}