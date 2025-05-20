//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFERSIZE 1024

void send_command(int sockfd, char *command) {
    int numSent = send(sockfd, command, strlen(command), 0);
    if (numSent < 0) {
        perror("send");
        exit(1);
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFERSIZE];
    int numReceived = recv(sockfd, buffer, BUFFERSIZE, 0);
    if (numReceived < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s\n", buffer);
}

void login(int sockfd) {
    char login_command[] = "USER";
    send_command(sockfd, login_command);
    receive_response(sockfd);
    printf("Login successful!\n");
}

void quit(int sockfd) {
    char quit_command[] = "QUIT";
    send_command(sockfd, quit_command);
    receive_response(sockfd);
    printf("Connection closed.\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char hostname[1024];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    snprintf(hostname, sizeof(hostname), "%s", argv[1]);
    rv = getaddrinfo(hostname, "pop3", &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd < 0) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) < 0) {
            perror("connect");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "connect: failed\n");
        exit(1);
    }

    login(sockfd);

    char recv_buffer[BUFFERSIZE];
    while (1) {
        int num_bytes = recv(sockfd, recv_buffer, BUFFERSIZE, 0);
        if (num_bytes < 0) {
            perror("recv");
            exit(1);
        }

        if (num_bytes == 0) {
            break;
        }

        printf("%s\n", recv_buffer);
    }

    quit(sockfd);

    freeaddrinfo(servinfo);

    close(sockfd);
    return 0;
}