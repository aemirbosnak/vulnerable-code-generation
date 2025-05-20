//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int sockfd;
char recvbuff[BUFF_SIZE];
char sendbuff[BUFF_SIZE];

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void connect_to_server(char *hostname, char *port) {
    struct addrinfo hints, *servinfo, *p;
    int status;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(hostname, port, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    // loop through all the results and connect to the first we can
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("client: connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        exit(2);
    }

    freeaddrinfo(servinfo);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    connect_to_server(argv[1], argv[2]);

    printf("Connection established. Type 'bye' to exit.\n");

    while (1) {
        printf(">> ");

        fgets(sendbuff, BUFF_SIZE, stdin);
        sendbuff[strcspn(sendbuff, "\n")] = 0;

        if (strncmp(sendbuff, "bye", 3) == 0) {
            break;
        }

        // send command to server
        if (send(sockfd, sendbuff, strlen(sendbuff), 0) == -1) {
            error("send");
        }

        // receive response from server
        if (recv(sockfd, recvbuff, BUFF_SIZE-1, 0) == -1) {
            error("recv");
        }

        recvbuff[strcspn(recvbuff, "\n")] = 0;

        printf("Server response: %s\n", recvbuff);
    }

    close(sockfd);
    return 0;
}