//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage:./ftp_client <hostname> <username> <password>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Unable to create socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        printf("Error: Invalid hostname\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Unable to connect to server\n");
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    send(sockfd, argv[2], strlen(argv[2]), 0);
    send(sockfd, argv[3], strlen(argv[3]), 0);

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE);
        if (n <= 0) {
            printf("Disconnected from server\n");
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}