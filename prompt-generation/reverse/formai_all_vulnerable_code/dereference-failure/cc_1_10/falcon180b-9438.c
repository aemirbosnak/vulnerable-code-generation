//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 512
#define MAX_COMMAND 64

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[MAX_LINE];
    char password[MAX_LINE];
    char command[MAX_COMMAND];
    char response[MAX_LINE];
    int n;

    if (argc!= 5) {
        printf("Usage: %s <server> <port> <username> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(username, argv[3]);
    strcpy(password, argv[4]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    while (1) {
        memset(response, 0, MAX_LINE);
        n = recv(sockfd, response, MAX_LINE, 0);
        if (n <= 0) {
            printf("Error receiving response\n");
            break;
        }

        printf("%s", response);
    }

    close(sockfd);
    return 0;
}