//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 512
#define FTP_DATA_PORT 20
#define FTP_COMMAND_PORT 21

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    int opt = 1;
    char *host_name = "localhost";
    char *username = "anonymous";
    char *password = "anonymous@example.com";
    char buffer[MAX_COMMAND_LENGTH];
    int n;
    char *command = "USER anonymous@example.com\r\n";
    char *response;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_DATA_PORT);
    inet_pton(AF_INET, host_name, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s\n", host_name);

    send(sockfd, command, strlen(command), 0);

    response = malloc(MAX_COMMAND_LENGTH);
    memset(response, 0, MAX_COMMAND_LENGTH);

    n = recv(sockfd, response, MAX_COMMAND_LENGTH, 0);
    if (n <= 0) {
        perror("recv");
        exit(1);
    }

    printf("Response: %s\n", response);

    close(sockfd);
    return 0;
}