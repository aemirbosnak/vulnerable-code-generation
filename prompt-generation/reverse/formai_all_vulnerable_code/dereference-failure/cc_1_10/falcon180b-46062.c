//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *server;
    int port;
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage:./ftp_client <server> <port> <command>\n");
        return 1;
    }

    server = argv[1];
    port = atoi(argv[2]);
    char *command = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct hostent *server_info;
    server_info = gethostbyname(server);
    if (server_info == NULL) {
        printf("Error resolving hostname\n");
        return 1;
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy(server_info->h_addr, &server_addr.sin_addr, server_info->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    if (send(sockfd, command, strlen(command), 0) == -1) {
        printf("Error sending command\n");
        return 1;
    }

    bzero(buffer, BUFFER_SIZE);
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving response\n");
        return 1;
    }

    printf("Server response: %s\n", buffer);

    close(sockfd);
    return 0;
}