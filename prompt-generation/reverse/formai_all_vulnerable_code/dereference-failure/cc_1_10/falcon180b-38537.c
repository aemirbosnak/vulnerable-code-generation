//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *hostname;
    struct hostent *host;
    int sockfd, port, result;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "No such host: %s\n", hostname);
        close(sockfd);
        return 1;
    }

    inet_pton(AF_INET, host->h_addr, &server_addr.sin_addr);

    result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result == -1) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        result = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (result == -1) {
            perror("recv");
            close(sockfd);
            return 1;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}