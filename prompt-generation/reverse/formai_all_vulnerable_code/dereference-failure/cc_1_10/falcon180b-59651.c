//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int port = 21;
    char *host = argv[1];
    int opt = 1;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // get server address
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", host);
        exit(EXIT_FAILURE);
    }

    // fill in server address structure
    memcpy(&(server_addr.sin_addr), server->h_addr, server->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // login to server
    send(sockfd, "USER anonymous\r\n", 19, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // change to binary mode
    send(sockfd, "TYPE I\r\n", 9, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // get file list
    send(sockfd, "LIST\r\n", 7, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // print file list
    printf("%s", buffer);

    // close socket
    close(sockfd);

    return 0;
}