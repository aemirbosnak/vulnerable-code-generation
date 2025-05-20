//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 1024
#define TIMEOUT 2000

int main(int argc, char **argv) {
    int sockfd, i;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    struct hostent *server;
    struct timeval tv;
    fd_set readfds;

    if (argc != 2) {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    write(sockfd, "PING\n", 5);

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    tv.tv_sec = TIMEOUT / 1000;
    tv.tv_usec = (TIMEOUT % 1000) * 1000;

    int result = select(sockfd + 1, &readfds, NULL, NULL, &tv);

    if (result < 0) {
        perror("ERROR on select");
        exit(1);
    } else if (result > 0) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            printf("Reply received: %s", buffer);
        } else {
            printf("No reply received");
        }
    } else {
        printf("Timeout");
    }

    close(sockfd);
    return 0;
}