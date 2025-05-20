//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_MESSAGE 100
#define PORT 80

int main(int argc, char *argv[]) {
    int sockfd, bytes_recv;
    struct sockaddr_in server_address;
    struct hostent *server;
    char message[MAX_MESSAGE];
    char response[MAX_MESSAGE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        exit(1);
    }

    sprintf(message, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);

    bytes_recv = send(sockfd, message, strlen(message), 0);
    if (bytes_recv < 0) {
        perror("send");
        exit(1);
    }

    memset(response, 0, MAX_MESSAGE);
    bytes_recv = recv(sockfd, response, MAX_MESSAGE, 0);
    if (bytes_recv < 0) {
        perror("recv");
        exit(1);
    }

    printf("Response: %s\n", response);

    close(sockfd);
    return 0;
}