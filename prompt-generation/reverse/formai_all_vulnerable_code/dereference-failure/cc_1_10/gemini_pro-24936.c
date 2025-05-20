//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        error("Usage: ftpclient <hostname> <port>");
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        printf("ftp>");
        fgets(buffer, BUFFER_SIZE, stdin);

        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        int n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            error("Error sending data to server");
        }

        memset(buffer, 0, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n < 0) {
            error("Error receiving data from server");
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}