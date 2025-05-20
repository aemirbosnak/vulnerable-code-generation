//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50], password[50], buffer[MAX_LINE];
    int n;
    int port = 110;

    if (argc!= 4) {
        printf("Usage:./pop3_client <server_ip> <username> <password>\n");
        exit(1);
    }

    strcpy(username, argv[2]);
    strcpy(password, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    while (1) {
        memset(buffer, 0, MAX_LINE);
        n = recv(sockfd, buffer, MAX_LINE, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            break;
        }

        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}