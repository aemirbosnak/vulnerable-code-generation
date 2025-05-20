//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct sockaddr_in dest_addr;
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("Error: Unknown host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}