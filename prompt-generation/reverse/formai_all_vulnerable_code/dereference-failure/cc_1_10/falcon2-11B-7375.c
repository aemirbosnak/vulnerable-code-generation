//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char hostname[1024];
    strcpy(hostname, argv[1]);
    int port = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in serveraddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        exit(1);
    }

    char request[100] = "PING /?\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }

    char response[1024];
    int num_bytes = recv(sockfd, response, sizeof(response), 0);
    if (num_bytes == -1) {
        perror("recv");
        exit(1);
    }

    response[num_bytes] = '\0';
    printf("Response: %s\n", response);

    return 0;
}