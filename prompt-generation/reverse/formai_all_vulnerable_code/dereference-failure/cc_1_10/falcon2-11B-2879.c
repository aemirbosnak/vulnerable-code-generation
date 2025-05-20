//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to convert an IPv4 address to a string
char* ipToString(struct in_addr ip) {
    char buf[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &ip, buf, sizeof(buf));
    return strdup(buf);
}

// Function to create a TCP socket
int createSocket(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    int opt = 1;
    int val = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("ERROR setting socket option");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listening");
        exit(1);
    }

    return sockfd;
}

// Function to accept a connection and print the client's address
void acceptConnection(int sockfd) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sockfd;

    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (client_sockfd < 0) {
        perror("ERROR on accepting");
        exit(1);
    }

    char* client_ip = ipToString(client_addr.sin_addr);
    printf("Connected to %s:%d\n", client_ip, ntohs(client_addr.sin_port));

    free(client_ip);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    int sockfd = createSocket(port);
    acceptConnection(sockfd);

    close(sockfd);
    return 0;
}