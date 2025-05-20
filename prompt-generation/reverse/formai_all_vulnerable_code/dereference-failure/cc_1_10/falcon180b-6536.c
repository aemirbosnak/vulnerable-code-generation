//Falcon-180B DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 2048
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    int opt = TRUE;
    char buffer[BUFFER_SIZE];

    if (argc < 4) {
        printf("Usage: %s <IP Address> <Port Number> <Allowed/Denied>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    if (strcmp(argv[3], "Allowed") == 0) {
        send(sockfd, argv[3], strlen(argv[3]), 0);
    } else {
        send(sockfd, argv[3], strlen(argv[3]), 0);
        close(sockfd);
        exit(0);
    }

    while (TRUE) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Connection closed by server\n");
            exit(0);
        }
        printf("Received: %s", buffer);
    }

    close(sockfd);
    exit(0);
}