//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int open_connection(char *host, char *port) {
    struct addrinfo hints, *ai;
    int sockfd, err;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((err = getaddrinfo(host, port, &hints, &ai)) != 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    for (; ai; ai = ai->ai_next) {
        if ((sockfd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol)) == -1)
            continue;

        if (connect(sockfd, ai->ai_addr, ai->ai_addrlen) == -1)
            close(sockfd);
        else {
            freeaddrinfo(ai);
            return sockfd;
        }
    }
    fprintf(stderr, "Could not connect to %s on port %s.\n", host, port);
    exit(EXIT_FAILURE);
}

void send_data(int sockfd, char *msg) {
    ssize_t nbytes;

    nbytes = send(sockfd, msg, strlen(msg), 0);
    if (nbytes == -1) {
        perror("Error at send(): ");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    int sockfd;
    char *host, *port, *message;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host = argv[1];
    port = argv[2];
    message = argv[3];

    sockfd = open_connection(host, port);

    send_data(sockfd, message);

    close(sockfd);

    return 0;
}