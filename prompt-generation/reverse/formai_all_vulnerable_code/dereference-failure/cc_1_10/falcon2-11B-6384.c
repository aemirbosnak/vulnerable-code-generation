//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>

#define SERVER_ADDR "smtp.gmail.com"
#define SERVER_PORT 587
#define USER "your_email@gmail.com"
#define PASSWORD "your_password"

int main() {
    int sockfd, valread;
    struct hostent *server;
    struct sockaddr_in serveraddr;
    char buf[1024];
    char username[] = USER;
    char password[] = PASSWORD;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(SERVER_PORT);

    connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    printf("Username: ");
    fgets(buf, 1024, stdin);
    buf[strcspn(buf, "\n")] = '\0';
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("ERROR sending username");
        exit(1);
    }

    printf("Password: ");
    fgets(buf, 1024, stdin);
    buf[strcspn(buf, "\n")] = '\0';
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("ERROR sending password");
        exit(1);
    }

    if (recv(sockfd, buf, 1024, 0) < 0) {
        perror("ERROR receiving message");
        exit(1);
    }

    printf("Message received: %s\n", buf);

    close(sockfd);
    return 0;
}