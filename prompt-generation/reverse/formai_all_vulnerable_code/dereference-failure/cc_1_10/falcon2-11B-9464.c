//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF 256

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUF];
    char ip[INET_ADDRSTRLEN];
    char* hostname;

    if (argc!= 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    portno = atoi(argv[2]);

    server = gethostbyname(hostname);

    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    memset((char *) &serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    printf("Connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    while (1) {
        n = read(sockfd, buffer, MAX_BUF);
        if (n < 0)
            error("ERROR reading from socket");

        printf("Received: %s\n", buffer);
        send(sockfd, buffer, n, 0);
    }

    close(sockfd);
    return 0;
}