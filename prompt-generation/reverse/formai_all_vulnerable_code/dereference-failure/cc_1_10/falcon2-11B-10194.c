//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char *hostname = "www.example.com";
    int port = 80;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket");
        return -1;
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("ERROR, no such host\n");
        return -1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    if (send(sockfd, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n", 46, 0) < 0) {
        printf("ERROR sending data");
        return -1;
    }

    char buffer[1024];
    int num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);

    if (num_bytes < 0) {
        printf("ERROR receiving data");
        return -1;
    }

    printf("%s", buffer);

    close(sockfd);
    return 0;
}