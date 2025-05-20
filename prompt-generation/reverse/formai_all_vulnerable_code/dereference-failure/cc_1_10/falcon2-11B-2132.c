//Falcon2-11B DATASET v1.0 Category: Networking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "Usage %s hostname port\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[256];
    while (1) {
        printf("Enter a message: ");
        fgets(buffer, sizeof(buffer), stdin);
        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("send");
            exit(1);
        }
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("recv");
            exit(1);
        }
        printf("Received: %s\n", buffer);
        if (n == 0)
            break;
    }
    close(sockfd);
    return 0;
}