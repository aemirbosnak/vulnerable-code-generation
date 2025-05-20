//GEMINI-pro DATASET v1.0 Category: Networking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define PORT 80

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[1024];

    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    sprintf(buffer, "GET / HTTP/1.1\nHost: %s\n\n", argv[1]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, sizeof(buffer));
    while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        printf("%s", buffer);
    }
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    close(sockfd);
    return 0;
}