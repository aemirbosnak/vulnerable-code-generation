//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct hostent *server;
    struct sockaddr_in server_addr;
    char buffer[1024];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    while (1) {
        int len = read(sockfd, buffer, sizeof(buffer));
        if (len <= 0) {
            perror("read");
            exit(1);
        }
        printf("%s", buffer);
    }

    return 0;
}