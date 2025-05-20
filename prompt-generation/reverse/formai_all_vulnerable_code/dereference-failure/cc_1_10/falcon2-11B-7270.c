//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/tcp.h>

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t addrlen;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server-address>\n", argv[0]);
        exit(1);
    }

    addrlen = sizeof(client_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Server connected.\n");

    while (1) {
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("read");
            exit(1);
        }

        printf("%s", buffer);

        memset(buffer, 0, sizeof(buffer));
        n = write(sockfd, "Client: ", 8);
        if (n < 0) {
            perror("write");
            exit(1);
        }
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("read");
            exit(1);
        }
        printf("Server: %s\n", buffer);
    }

    return 0;
}