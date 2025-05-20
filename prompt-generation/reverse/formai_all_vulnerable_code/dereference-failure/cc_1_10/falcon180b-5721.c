//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define MAX_LINE 1024
#define MAX_COMMAND 64
#define MAX_RESPONSE 1024
#define POP3_PORT 110
#define POP3_USER "username"
#define POP3_PASS "password"

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    char buffer[MAX_LINE];
    char command[MAX_COMMAND];
    char response[MAX_RESPONSE];
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr *sa;
    struct hostent *hp;
    char s[INET6_ADDRSTRLEN];
    int rv;
    time_t start_time, end_time;

    printf("POP3 Client\n");

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("localhost", "110", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(EXIT_FAILURE);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(EXIT_FAILURE);
    }

    printf("Connected to POP3 server.\n");

    start_time = time(NULL);

    snprintf(command, sizeof(command), "USER %s\r\n", POP3_USER);
    send(sockfd, command, strlen(command), 0);

    snprintf(command, sizeof(command), "PASS %s\r\n", POP3_PASS);
    send(sockfd, command, strlen(command), 0);

    snprintf(command, sizeof(command), "STAT\r\n");
    send(sockfd, command, strlen(command), 0);

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("Received: %s", buffer);
        if (strstr(buffer, "OK")) {
            printf("Successfully logged in.\n");
            break;
        }
    }

    if (n <= 0) {
        fprintf(stderr, "Error receiving data.\n");
        exit(EXIT_FAILURE);
    }

    end_time = time(NULL);
    printf("Time taken: %ld seconds\n", end_time - start_time);

    close(sockfd);

    return 0;
}