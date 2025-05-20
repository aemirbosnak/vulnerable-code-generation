//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <poll.h>

#define PORT 993
#define SERVER "imap.example.com"
#define AUTH_USER "username"
#define AUTH_PASS "password"

int main() {
    struct addrinfo hints, *servinfo, *p;
    int sockfd, rv, n;
    int yes = 1;
    struct timeval timeout;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(SERVER, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to the server.\n");
        return 2;
    }

    char buffer[4096];
    int bufferSize = sizeof(buffer);

    if (sendmail(sockfd, AUTH_USER, AUTH_PASS, bufferSize, buffer) == -1) {
        fprintf(stderr, "Failed to send login information.\n");
        return 3;
    }

    if (recvmail(sockfd, bufferSize, buffer) == -1) {
        fprintf(stderr, "Failed to receive mail list.\n");
        return 4;
    }

    printf("IMAP Client Sample\n");
    printf("===============================================\n");
    printf("Server: %s\n", SERVER);
    printf("User: %s\n", AUTH_USER);
    printf("===============================================\n");

    printf("Mail list:\n");
    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == '\n') {
            printf("%s\n", buffer + i - 1);
            i++;
        }
    }

    close(sockfd);
    freeaddrinfo(servinfo);

    return 0;
}

int sendmail(int sockfd, const char *username, const char *password, int size, char *buf) {
    int n;

    fprintf(stderr, "Logging in...\n");
    n = write(sockfd, "AUTH LOGIN\r\n", 12);
    if (n!= 12) {
        fprintf(stderr, "Failed to authenticate.\n");
        return -1;
    }

    fprintf(stderr, "Sending username: %s\n", username);
    n = write(sockfd, username, strlen(username));
    if (n!= strlen(username)) {
        fprintf(stderr, "Failed to send username.\n");
        return -1;
    }

    fprintf(stderr, "Sending password: %s\n", password);
    n = write(sockfd, password, strlen(password));
    if (n!= strlen(password)) {
        fprintf(stderr, "Failed to send password.\n");
        return -1;
    }

    fprintf(stderr, "Waiting for response...\n");
    n = read(sockfd, buf, size);
    if (n < 0) {
        fprintf(stderr, "Failed to read response.\n");
        return -1;
    }

    return 0;
}

int recvmail(int sockfd, int size, char *buf) {
    int n;

    fprintf(stderr, "Waiting for mail list...\n");
    n = read(sockfd, buf, size);
    if (n < 0) {
        fprintf(stderr, "Failed to read mail list.\n");
        return -1;
    }

    return 0;
}