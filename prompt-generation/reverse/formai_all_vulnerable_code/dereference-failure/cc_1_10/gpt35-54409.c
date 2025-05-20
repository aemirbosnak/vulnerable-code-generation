//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_MSG_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        error("ERROR opening socket");
    }
    return sockfd;
}

void bind_socket(int sockfd, int port) {
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }
}

void listen_for_clients(int sockfd) {
    listen(sockfd, 1);
    printf("Listening for incoming connections...\n");

    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);
    int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if(newsockfd < 0) {
        error("ERROR on accept");
    }

    char buffer[MAX_MSG_SIZE];
    bzero(buffer, MAX_MSG_SIZE);
    int n = read(newsockfd, buffer, MAX_MSG_SIZE - 1);
    if(n < 0) {
        error("ERROR reading from socket");
    }
    printf("Client: %s\n", buffer);

    n = write(newsockfd, "Server: I got your message", 26);
    if(n < 0) {
        error("ERROR writing to socket");
    }
}

int main(int argc, char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    int sockfd = create_socket();
    bind_socket(sockfd, port);
    listen_for_clients(sockfd);

    close(sockfd);
    return 0;
}