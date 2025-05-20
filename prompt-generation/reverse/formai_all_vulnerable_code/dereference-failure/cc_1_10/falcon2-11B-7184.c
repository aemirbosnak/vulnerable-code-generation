//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1500

int main(int argc, char *argv[]) {
    int sockfd, bytes_sent, bytes_recv, n;
    char buffer[BUFSIZE];
    struct sockaddr_in addr;
    struct hostent *host;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    printf("Pinging %s...\n", argv[1]);

    while (1) {
        bytes_sent = send(sockfd, buffer, BUFSIZE, 0);
        if (bytes_sent <= 0) {
            perror("Error sending data");
            exit(1);
        }

        bytes_recv = recv(sockfd, buffer, BUFSIZE, 0);
        if (bytes_recv <= 0) {
            perror("Error receiving data");
            exit(1);
        }

        printf("%d bytes received from %s\n", bytes_recv, argv[1]);

        if (bytes_recv == 0) {
            printf("No response from %s\n", argv[1]);
            break;
        }
    }

    close(sockfd);
    return 0;
}