//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int connect_to_server(char *hostname, char *port) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, port, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

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
        return 2;
    }

    freeaddrinfo(servinfo);
    return sockfd;
}

int read_from_server(int sockfd, char *response) {
    int bytes_received = 0;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    while (strstr(buffer, "\r\n\r\n") == NULL) {
        if ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) == -1) {
            perror("recv");
            return 1;
        }
        strcat(response, buffer);
        memset(buffer, '\0', BUFFER_SIZE);
    }

    return 0;
}

int send_command(int sockfd, char *command) {
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    int sockfd, numbytes;
    char buf[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    memset(response, '\0', BUFFER_SIZE);

    if ((sockfd = connect_to_server(argv[1], argv[2])) == -1) {
        fprintf(stderr, "Could not connect to server %s on port %s\n", argv[1], argv[2]);
        return 1;
    }

    read_from_server(sockfd, response);
    printf("%s", response);

    send_command(sockfd, "USER username\r\n");
    read_from_server(sockfd, response);
    printf("%s", response);

    send_command(sockfd, "PASS password\r\n");
    read_from_server(sockfd, response);
    printf("%s", response);

    send_command(sockfd, "LIST\r\n");
    read_from_server(sockfd, response);
    printf("%s", response);

    send_command(sockfd, "RETR 1\r\n");
    read_from_server(sockfd, response);
    printf("%s", response);

    send_command(sockfd, "QUIT\r\n");
    read_from_server(sockfd, response);
    printf("%s", response);

    close(sockfd);
    return 0;
}