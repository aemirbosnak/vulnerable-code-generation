//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];
    int port;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(data, 0, MAX_DATA);
        ret = read(sockfd, data, MAX_DATA);
        if (ret <= 0) {
            printf("Error reading from server\n");
            close(sockfd);
            exit(1);
        }
        printf("Received data: %s\n", data);
    }

    close(sockfd);
    return 0;
}