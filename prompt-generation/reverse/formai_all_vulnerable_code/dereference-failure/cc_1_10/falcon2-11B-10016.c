//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server_host;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s server-address\n", argv[0]);
        exit(1);
    }

    server_host = gethostbyname(argv[1]);
    if (server_host == NULL) {
        fprintf(stderr, "Error: Unknown server host\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8000);
    memcpy((char *) &server_addr.sin_addr.s_addr, (char *) server_host->h_addr, server_host->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        exit(1);
    }

    char message[MAX_MESSAGE_SIZE];
    memset(message, 0, sizeof(message));

    printf("Enter a message (up to %d characters): ", MAX_MESSAGE_SIZE);
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    send(sockfd, message, strlen(message), 0);

    close(sockfd);

    return 0;
}