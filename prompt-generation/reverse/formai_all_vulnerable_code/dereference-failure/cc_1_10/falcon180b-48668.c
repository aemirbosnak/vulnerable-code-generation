//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define PORT 80

void die(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int scan_port(char *hostname, int port) {
    int sockfd;
    struct sockaddr_in dest;
    int result;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        die("socket");
    }
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    dest.sin_addr.s_addr = inet_addr(hostname);
    result = connect(sockfd, (struct sockaddr *)&dest, sizeof(dest));
    if (result == 0) {
        close(sockfd);
        return TRUE;
    } else if (errno == ECONNREFUSED) {
        close(sockfd);
        return FALSE;
    } else {
        die("connect");
    }
}

int main(int argc, char *argv[]) {
    char *hostname;
    int port;
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    hostname = argv[1];
    port = atoi(argv[2]);
    if (port <= 0 || port > MAX) {
        printf("Invalid port number.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = PORT; i <= port; i++) {
        if (scan_port(hostname, i)) {
            printf("Port %d is open.\n", i);
        } else {
            printf("Port %d is closed.\n", i);
        }
    }
    return 0;
}