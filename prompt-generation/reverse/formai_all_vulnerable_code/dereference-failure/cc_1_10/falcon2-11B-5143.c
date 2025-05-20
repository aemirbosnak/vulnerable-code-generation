//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// function to send data to the server
void send_data(int sockfd, char* data) {
    send(sockfd, data, strlen(data), 0);
}

// function to receive data from the server
char* receive_data(int sockfd) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer)); // clear the buffer
    int n = recv(sockfd, buffer, sizeof(buffer) - 1, 0); // receive data
    buffer[n] = '\0'; // null terminate the string
    return buffer;
}

// function to connect to the server
int connect_to_server(const char* host, const char* port) {
    struct addrinfo hints, *servinfo, *p;
    int rv, sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(host, port, &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        rv = connect(sockfd, p->ai_addr, p->ai_addrlen);
        if (rv == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    freeaddrinfo(servinfo);
    return sockfd;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    const char* host = argv[1];
    const char* port = argv[2];

    int sockfd = connect_to_server(host, port);
    if (sockfd == -1) {
        fprintf(stderr, "connection failed\n");
        return 1;
    }

    char* message = "USER username\r\n";
    send_data(sockfd, message);
    printf("%s\n", receive_data(sockfd));

    free(message);
    return 0;
}