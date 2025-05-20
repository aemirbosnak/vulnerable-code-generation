//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP address> <Port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == 0) {
            printf("Error: Connection closed by server\n");
            exit(1);
        }
        printf("Received message: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}