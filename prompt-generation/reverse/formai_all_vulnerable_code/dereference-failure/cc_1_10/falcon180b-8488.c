//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 21
#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 512

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);
    char buffer[MAX_LINE_LENGTH];

    if (argc!= 3) {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, MAX_LINE_LENGTH);
        printf("Enter command: ");
        fgets(buffer, MAX_LINE_LENGTH, stdin);

        if (strncmp(buffer, "quit", 4) == 0) {
            break;
        }

        send(sockfd, buffer, strlen(buffer), 0);

        memset(buffer, 0, MAX_LINE_LENGTH);
        int bytes_received = recv(sockfd, buffer, MAX_LINE_LENGTH, 0);

        if (bytes_received <= 0) {
            printf("Error receiving data from server\n");
            return 1;
        }

        printf("Received from server: %s", buffer);
    }

    close(sockfd);

    return 0;
}