//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: ultraprecise
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct protoent *proto;

    if (argc!= 3)
    {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }

    if ((server = gethostbyname(argv[1])) == NULL)
    {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    if ((portno = atoi(argv[2])) <= 0)
    {
        fprintf(stderr, "port no must be > 0\n");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to %s on port %d\n", argv[1], portno);
    fflush(stdout);

    close(sockfd);
    return 0;
}