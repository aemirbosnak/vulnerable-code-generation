//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_HOSTNAME_LEN 64
#define MAX_MESSAGE_LEN 64
#define DEFAULT_PORT "7"

void print_usage(char *progname) {
    printf("Usage: %s <hostname> [port]\n", progname);
}

int main(int argc, char *argv[]) {
    char hostname[MAX_HOSTNAME_LEN];
    char message[MAX_MESSAGE_LEN];
    int port = 0;
    struct sockaddr_in server_addr;
    int sockfd = 0;
    int retval = 0;
    struct timeval timeout;

    if (argc < 3) {
        print_usage(argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    if (argc > 2) {
        port = atoi(argv[2]);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (retval == -1) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    strcpy(message, "PING");
    send(sockfd, message, strlen(message), 0);

    timeout.tv_sec = 3;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    retval = recv(sockfd, message, MAX_MESSAGE_LEN, 0);
    if (retval <= 0) {
        perror("recv");
        close(sockfd);
        return 1;
    }

    close(sockfd);

    if (strncmp(message, "PONG", strlen("PONG")) == 0) {
        printf("%s is alive\n", hostname);
    } else {
        printf("%s is not responding\n", hostname);
    }

    return 0;
}