//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* host = argv[1];
    char* port = argv[2];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    serv_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    ssize_t n = send(sockfd, "PING /?\r\n\r\n", 24, 0);
    if (n == -1) {
        perror("Error sending PING");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    printf("Received response: %s\n", buffer);

    close(sockfd);
    return 0;
}