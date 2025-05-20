//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

struct hostent *gethostbyname(const char *name);

int main(int argc, char **argv) {
    char *hostname;
    int port = 80;
    int sockfd, numbytes;
    char buffer[1024];
    struct hostent *server;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    server = gethostbyname(hostname);

    if (server == NULL) {
        printf("No such host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) server->h_addr, server->h_length) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to %s\n", hostname);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        numbytes = recv(sockfd, buffer, sizeof(buffer), 0);

        if (numbytes <= 0) {
            printf("Connection closed\n");
            break;
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}