//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 25
#define MAX_MESSAGE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server;
    char buffer[MAX_MESSAGE + 1];
    char message[MAX_MESSAGE];
    int i;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        exit(1);
    }

    memset(server.sin_zero, '\0', sizeof(server.sin_zero));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("localhost");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        fprintf(stderr, "Failed to connect to server\n");
        exit(1);
    }

    bzero(buffer, MAX_MESSAGE + 1);

    for (i = 0; i < strlen(argv[1]); i++) {
        buffer[i] = message[i] = argv[1][i];
    }

    buffer[i] = '\0';
    message[i] = '\0';

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        fprintf(stderr, "Failed to send message\n");
        exit(1);
    }

    if (recv(sockfd, buffer, MAX_MESSAGE, 0) < 0) {
        fprintf(stderr, "Failed to receive message\n");
        exit(1);
    }

    printf("Received: %s\n", buffer);

    close(sockfd);

    return 0;
}