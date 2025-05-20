//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int sockfd, bytes_sent, bytes_recv;
    struct sockaddr_in server_addr;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("www.google.com");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Pinging %s...\n", "www.google.com");

    send(sockfd, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n", 41, 0);

    while (1) {
        bytes_sent = recv(sockfd, NULL, 0, 0);
        if (bytes_sent < 0) {
            perror("ERROR receiving data");
            exit(1);
        }
        break;
    }

    close(sockfd);
    return 0;
}