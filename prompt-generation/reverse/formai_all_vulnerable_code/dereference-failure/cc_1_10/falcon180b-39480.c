//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 21
#define MAX_LINE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server_ip = "127.0.0.1";
    char *username = "anonymous";
    char *password = "anonymous@";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char *buffer = malloc(MAX_LINE);
    memset(buffer, 0, MAX_LINE);

    snprintf(buffer, MAX_LINE, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, MAX_LINE, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    char *command = "LIST\r\n";
    send(sockfd, command, strlen(command), 0);

    char *response = malloc(MAX_LINE);
    memset(response, 0, MAX_LINE);

    if (recv(sockfd, response, MAX_LINE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    printf("Server response: %s\n", response);

    close(sockfd);
    free(buffer);
    free(response);

    return 0;
}