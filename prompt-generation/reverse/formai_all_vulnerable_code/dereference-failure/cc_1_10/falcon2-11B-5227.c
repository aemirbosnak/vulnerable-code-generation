//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to get IP address
char *get_ip_address(void) {
    struct hostent *he;
    char *ip_addr = NULL;

    he = gethostbyname("localhost");
    if (he == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    ip_addr = inet_ntoa(*((struct in_addr *)he->h_addr));
    return ip_addr;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    char *file_path = argv[2];

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, get_ip_address(), &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(file_path, "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    int n = fread(NULL, 1, 1024, fp);
    while (n > 0) {
        n = send(sockfd, NULL, n, 0);
        if (n < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        n = fread(NULL, 1, 1024, fp);
    }

    fclose(fp);

    close(sockfd);

    return 0;
}