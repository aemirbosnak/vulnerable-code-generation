//FormAI DATASET v1.0 Category: Email Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 256

int create_connection(const char *hostname, const char *port) {
    int sockfd;
    struct addrinfo hints, *res, *p;
    int status;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if((status = getaddrinfo(hostname, port, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return -1;
    }

    for(p = res; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(sockfd == -1) {
            continue;
        }

        if(connect(sockfd, p->ai_addr, p->ai_addrlen) != -1) {
            break;
        }

        close(sockfd);
    }

    freeaddrinfo(res);

    if(p == NULL) {
        fprintf(stderr, "failed to connect to %s:%s\n", hostname, port);
        return -1;
    }

    return sockfd;
}

int send_message(int sockfd, const char *message) {
    if(send(sockfd, message, strlen(message), 0) == -1) {
        return -1;
    }

    return 0;
}

int receive_message(int sockfd, char *buffer, size_t maxlen) {
    int num_bytes = recv(sockfd, buffer, maxlen - 1, 0);

    if(num_bytes == -1) {
        return -1;
    }

    buffer[num_bytes] = '\0';

    return num_bytes;
}

int main(int argc, char *argv[]) {
    // command line argument checks...
    if(argc != 4) {
        fprintf(stderr, "usage: %s <hostname> <port> <username>\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    const char *port = argv[2];
    const char *username = argv[3];

    int sockfd = create_connection(hostname, port);

    if(sockfd == -1) {
        return 1;
    }

    char buffer[BUF_SIZE];

    //receive connection acknowledgement
    if(receive_message(sockfd, buffer, BUF_SIZE) == -1) {
        return 1;
    }

    printf("%s\n", buffer);

    //send username
    snprintf(buffer, BUF_SIZE, "USER %s\n", username);

    if(send_message(sockfd, buffer) == -1) {
        return 1;
    }

    //receive username acknowledgement
    if(receive_message(sockfd, buffer, BUF_SIZE) == -1) {
        return 1;
    }

    printf("%s\n", buffer);

    //send quit message
    if(send_message(sockfd, "QUIT\n") == -1) {
        return 1;
    }

    //receive quit acknowledgement
    if(receive_message(sockfd, buffer, BUF_SIZE) == -1) {
        return 1;
    }

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}