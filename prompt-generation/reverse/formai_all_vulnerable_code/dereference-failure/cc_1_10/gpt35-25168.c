//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

void printHeader(int sockfd, char* host, char* path, char* query_param) {
    char header[1024], message[1024];
    strcpy(header, "");
    if(query_param == NULL)
        sprintf(header, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    else
        sprintf(header, "GET %s?%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, query_param, host);
    send(sockfd, header, strlen(header), 0);
    int recv_len;
    while ((recv_len = read(sockfd, message, 1024)) > 0) {
        message[recv_len] = '\0';
        printf("%s", message);
    }
}

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in server;

    if (argc != 4 && argc != 5) {
        printf("Usage: ./httpClient <host> <port> <path> [<query parameters>]");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Failed to create socket");
        exit(1);
    }

    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed");
        exit(1);
    }
    else {
        printf("Connected to server.\n");
    }

    printHeader(sockfd, argv[1], argv[3], argc == 5 ? argv[4] : NULL);

    close(sockfd);

    return 0;
}