//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_LINE 1024

void die(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        die("Usage:./ftp_client <ip> <port> <filename>");
    }

    char* ip = argv[1];
    int port = atoi(argv[2]);
    char* filename = argv[3];

    struct addrinfo hints, *servinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(ip, NULL, &hints, &servinfo)!= 0) {
        die("getaddrinfo");
    }

    int sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        die("socket");
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        die("connect");
    }

    char buf[MAX_LINE];
    snprintf(buf, MAX_LINE, "STOR %s\r\n", filename);
    send(sockfd, buf, strlen(buf), 0);

    char response[MAX_LINE];
    if (recv(sockfd, response, MAX_LINE, 0) == -1) {
        die("recv");
    }

    if (strncmp(response, "150", 3)!= 0) {
        die("STOR failed");
    }

    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        die("fopen");
    }

    char data[MAX_LINE];
    while (fgets(data, MAX_LINE, fp)!= NULL) {
        send(sockfd, data, strlen(data), 0);
    }

    fclose(fp);

    if (recv(sockfd, response, MAX_LINE, 0) == -1) {
        die("recv");
    }

    if (strncmp(response, "226", 3)!= 0) {
        die("transfer failed");
    }

    close(sockfd);
    return 0;
}