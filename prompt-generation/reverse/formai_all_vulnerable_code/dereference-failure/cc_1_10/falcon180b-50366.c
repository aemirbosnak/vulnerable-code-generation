//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

void print_usage(char *program_name) {
    printf("Usage: %s [host] [port] [username] [password]\n", program_name);
}

int main(int argc, char *argv[]) {
    if(argc!= 5) {
        print_usage(argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    if((server = gethostbyname(host)) == NULL) {
        error_handling("gethostbyname error");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        error_handling("socket error");
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("connect error");
    }

    printf("Connected to %s:%d\n", host, port);

    char *user_pass = malloc(strlen(username) + strlen(password) + 3);
    sprintf(user_pass, "%s:%s", username, password);

    if(send(sockfd, user_pass, strlen(user_pass), 0) < 0) {
        error_handling("send error");
    }

    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);

    if(recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        error_handling("recv error");
    }

    printf("Server response: %s\n", buffer);

    close(sockfd);

    return 0;
}