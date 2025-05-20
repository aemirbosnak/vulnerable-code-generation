//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_MSG_SIZE];
    struct hostent *server;
    struct in_addr *ip_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("ERROR, no such host\n");
        return 1;
    }
    ip_addr = (struct in_addr *) server->h_addr_list[0];
    portno = htons(5000);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = ip_addr->s_addr;
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR connecting\n");
        return 1;
    }

    n = read(sockfd, buffer, MAX_MSG_SIZE);
    if (n < 0) {
        printf("ERROR reading from socket\n");
        return 1;
    }
    printf("Received %d bytes: %s\n", n, buffer);

    n = write(sockfd, buffer, MAX_MSG_SIZE);
    if (n < 0) {
        printf("ERROR writing to socket\n");
        return 1;
    }
    printf("Sent %d bytes: %s\n", n, buffer);

    close(sockfd);
    return 0;
}