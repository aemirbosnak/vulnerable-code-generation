//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[BUF_SIZE];

    if (argc!= 4) {
        printf("Usage:./client <IP Address> <Username> <Password>\n");
        exit(1);
    }

    char *ip = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    printf("Connected to server\n");

    char *response = "";
    while (1) {
        memset(buffer, 0, BUF_SIZE);
        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Error: Disconnected\n");
            exit(1);
        }

        response = strcat(response, buffer);

        if (strstr(response, "+OK")) {
            char *token = strtok(response, " ");
            while (token!= NULL) {
                if (strcmp(token, "+OK") == 0) {
                    printf("Login successful\n");
                    break;
                }
                token = strtok(NULL, " ");
            }
            break;
        }
    }

    close(sockfd);
    return 0;
}