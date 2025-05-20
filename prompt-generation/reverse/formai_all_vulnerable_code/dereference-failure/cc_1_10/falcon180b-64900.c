//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void die(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    if(argc!= 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        die("socket");
    }

    struct addrinfo hints, *servinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if(getaddrinfo(hostname, "21", &hints, &servinfo)!= 0) {
        die("getaddrinfo");
    }

    if(connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        die("connect");
    }

    char* login_data = (char*)malloc(BUFFER_SIZE);
    snprintf(login_data, BUFFER_SIZE, "USER %s\r\n", username);
    send(sockfd, login_data, strlen(login_data), 0);

    snprintf(login_data, BUFFER_SIZE, "PASS %s\r\n", password);
    send(sockfd, login_data, strlen(login_data), 0);

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    while(recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
        printf("%s", buffer);
    }

    close(sockfd);
    free(login_data);
    return 0;
}