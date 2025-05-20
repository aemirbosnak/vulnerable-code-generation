//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char *ip;
    int port;
    int opt = 1;
    char buffer[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage:./program <server_ip> <port>\n");
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if ((host = gethostbyname(ip)) == NULL) {
        printf("Error resolving hostname\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        fgets(buffer, BUF_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "/quit") == 0) {
            break;
        }
        bzero(buffer, BUF_SIZE);
        recv(sockfd, buffer, BUF_SIZE, 0);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}