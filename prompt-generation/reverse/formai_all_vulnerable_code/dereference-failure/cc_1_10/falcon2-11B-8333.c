//Falcon2-11B DATASET v1.0 Category: Networking ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server;
    struct hostent *serverHostInfo;

    char buffer[1024];
    char message[1024];
    int message_len = 0;

    printf("Server\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    serverHostInfo = gethostbyname("localhost");
    if (serverHostInfo == NULL) {
        fprintf(stderr, "gethostbyname: no such host\n");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = *(unsigned long *)serverHostInfo->h_addr;
    server.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    while (1) {
        bzero(buffer, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        buffer[n] = '\0';

        printf("Received: %s\n", buffer);

        bzero(message, sizeof(message));
        scanf("%s", message);

        if (strlen(message) == 0) {
            continue;
        }

        bzero(buffer, sizeof(buffer));
        sprintf(buffer, "Received: %s\n", message);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}