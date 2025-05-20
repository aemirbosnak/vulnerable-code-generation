//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd;
    char *hostname;
    int hostlen;
    struct sockaddr_in serveraddr;
    int opt = 1;
    char *username = "anonymous";
    char *password = "anonymous@example.com";
    char *command = "LIST";
    char buffer[1024];
    int n;

    printf("FTP Client\n");

    if (argc!= 3) {
        printf("Usage:./ftp_client <hostname> <port>\n");
        exit(1);
    }

    hostname = argv[1];
    hostlen = strlen(hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to %s:%d\n", hostname, PORT);

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    while (1) {
        bzero(buffer, 1024);
        n = recv(sockfd, buffer, 1024, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        printf("%s", buffer);

        bzero(buffer, 1024);
        sprintf(buffer, "LIST %s\r\n", command);
        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);
    return 0;
}