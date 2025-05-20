//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TIME_OUT 5

int main(int argc, char *argv[]) {
    int sockfd, ret, hostlen, datalen;
    struct sockaddr_in server_addr;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <data>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    strcpy(data, argv[2]);

    hostlen = strlen(hostname);
    datalen = strlen(data);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        fprintf(stderr, "Connection failed: %s\n", strerror(errno));
        exit(1);
    }

    send(sockfd, data, datalen, 0);

    ret = recv(sockfd, data, MAX_DATA, 0);
    if (ret == -1) {
        fprintf(stderr, "Recv failed: %s\n", strerror(errno));
        exit(1);
    }

    close(sockfd);

    printf("Received response: %s\n", data);

    return 0;
}