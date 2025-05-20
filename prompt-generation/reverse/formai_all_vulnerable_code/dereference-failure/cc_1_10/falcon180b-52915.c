//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *hostname, *username, *password;
    int port, sockfd, ret;
    struct hostent *hostinfo;
    struct sockaddr_in serveraddr;

    if (argc!= 5) {
        printf("Usage: %s <hostname> <username> <password> <port>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    username = argv[2];
    password = argv[3];
    port = atoi(argv[4]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        printf("Host not found.\n");
        close(sockfd);
        return 1;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    memcpy(&serveraddr.sin_addr, hostinfo->h_addr, hostinfo->h_length);

    ret = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (ret == -1) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    printf("Connected to %s.\n", hostname);

    char *cmd = "USER ";
    send(sockfd, cmd, strlen(cmd), 0);
    cmd = "PASS ";
    send(sockfd, cmd, strlen(cmd), 0);
    cmd = username;
    send(sockfd, cmd, strlen(cmd), 0);
    cmd = password;
    send(sockfd, cmd, strlen(cmd), 0);

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (ret <= 0) {
            printf("Disconnected.\n");
            close(sockfd);
            return 0;
        }
        printf("%s", buffer);
    }

    return 0;
}