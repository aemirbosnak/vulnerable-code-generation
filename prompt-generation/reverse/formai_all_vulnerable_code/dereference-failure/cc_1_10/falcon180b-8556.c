//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <port> <file_name>\n");
        return -1;
    }

    char *server_ip = argv[1];
    int port = atoi(argv[2]);
    char *file_name = argv[3];

    int sockfd;
    struct sockaddr_in server_addr;
    int opt = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return -1;
    }

    char command[BUFFER_SIZE];
    sprintf(command, "STOR %s\r\n", file_name);

    send(sockfd, command, strlen(command), 0);

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    if (recv(sockfd, response, BUFFER_SIZE, 0) == -1) {
        printf("Error receiving response\n");
        return -1;
    }

    if (strncmp(response, "226", 3)!= 0) {
        printf("Error uploading file\n");
        return -1;
    }

    close(sockfd);

    printf("File uploaded successfully\n");

    return 0;
}