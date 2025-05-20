//FormAI DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 256
#define PORT_NUMBER 8080

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        fprintf(stderr,"Usage: %s hostname\n", argv[0]);
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error: couldn't open socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT_NUMBER);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error: couldn't connect to server");
    }

    printf("Connected to server. Type 'quit' to exit.\n");

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    FD_SET(STDIN_FILENO, &readfds);

    while (1) {
        fd_set curr_readfds = readfds;
        if (select(sockfd + 1, &curr_readfds, NULL, NULL, NULL) == -1) {
            error("Error: select failed");
        }

        if (FD_ISSET(STDIN_FILENO, &curr_readfds)) {
            bzero(buffer, BUFFER_SIZE);
            fgets(buffer, BUFFER_SIZE - 1, stdin);

            if (strcmp(buffer, "quit\n") == 0) {
                break;
            }

            n = write(sockfd, buffer, strlen(buffer));
            if (n < 0) {
                error("Error: couldn't write to socket");
            }
        }

        if (FD_ISSET(sockfd, &curr_readfds)) {
            bzero(buffer, BUFFER_SIZE);
            n = read(sockfd, buffer, BUFFER_SIZE - 1);
            if (n < 0) {
                error("Error: couldn't read from socket");
            } else if (n == 0) {
                printf("Disconnected from server.\n");
                break;
            } else {
                printf("Server: %s", buffer);
            }
        }
    }

    close(sockfd);
    return 0;
}