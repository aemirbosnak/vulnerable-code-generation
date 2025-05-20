//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to send data over socket
int sendData(int sockfd, char* data, int len) {
    int sent = send(sockfd, data, len, 0);
    if (sent < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    return sent;
}

// Function to receive data from socket
int receiveData(int sockfd, char* data, int len) {
    int received = recv(sockfd, data, len, 0);
    if (received < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    return received;
}

int main(int argc, char** argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[100];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [portno]\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 1) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connection...\n");

    while (1) {
        sockfd = accept(sockfd, (struct sockaddr*) NULL, NULL);
        if (sockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

        while (1) {
            int len = receiveData(sockfd, buffer, sizeof(buffer));
            if (len <= 0) {
                break;
            }
            printf("Received: %s\n", buffer);

            char response[100];
            strcpy(response, "ACK");
            sendData(sockfd, response, strlen(response));
        }

        close(sockfd);
    }

    close(sockfd);
    return 0;
}