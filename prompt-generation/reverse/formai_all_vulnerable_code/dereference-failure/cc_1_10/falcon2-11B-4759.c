//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: light-weight
//```.
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_BUF 512

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUF];
    char hostname[MAX_BUF];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return 1;
    }

    bzero(hostname, MAX_BUF);
    strcpy(hostname, argv[1]);

    portno = atoi(argv[1]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return 1;
    }

    sprintf(buffer, "PING %s (%s) %d", hostname, inet_ntoa(serv_addr.sin_addr), portno);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, MAX_BUF, 0);
    if (n <= 0) {
        perror("recv");
        return 1;
    }

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}