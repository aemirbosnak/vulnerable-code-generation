//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 512
#define MAX_RESPONSE_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char command[MAX_COMMAND_LENGTH] = "HELO example.com\r\n";
    char response[MAX_RESPONSE_LENGTH] = {0};

    if (argc!= 3) {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    send(sockfd, command, strlen(command), 0);

    while (1) {
        memset(response, 0, MAX_RESPONSE_LENGTH);
        int bytes_received = recv(sockfd, response, MAX_RESPONSE_LENGTH - 1, 0);
        if (bytes_received <= 0) {
            printf("Error receiving response\n");
            close(sockfd);
            return 1;
        }

        printf("Response: %s", response);

        if (strstr(response, "250")!= NULL) {
            break;
        }
    }

    close(sockfd);
    return 0;
}