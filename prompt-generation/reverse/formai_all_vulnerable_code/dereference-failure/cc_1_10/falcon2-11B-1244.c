//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    char host[256];
    int sockfd, portno;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    printf("Enter the hostname or IP address: ");
    scanf("%s", host);

    portno = 80;

    server = gethostbyname(host);
    if (server == NULL)
    {
        printf("ERROR: hostname not found\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    printf("Connecting to %s on port %d\n", host, portno);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("ERROR: Connection failed\n");
        exit(1);
    }

    char msg[256];
    strcpy(msg, "GET / HTTP/1.0\r\n\r\n");
    send(sockfd, msg, strlen(msg), 0);
    close(sockfd);

    return 0;
}