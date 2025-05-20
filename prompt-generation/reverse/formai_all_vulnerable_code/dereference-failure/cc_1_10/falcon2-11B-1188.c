//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR: Cannot resolve localhost\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    printf("Enter the message to send: ");
    fgets(buffer, sizeof(buffer), stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    memset(buffer, '\0', sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", buffer);

    close(sockfd);
    return 0;
}