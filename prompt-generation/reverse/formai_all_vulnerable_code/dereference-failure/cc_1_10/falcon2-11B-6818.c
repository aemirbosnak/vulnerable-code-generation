//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct hostent *server;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s on port %s\n", argv[1], argv[2]);

    char buffer[256];
    bzero(buffer, sizeof(buffer));
    printf("Enter a message to send: ");
    fgets(buffer, sizeof(buffer), stdin);
    send(sockfd, buffer, strlen(buffer), 0);
    printf("Message sent!\n");

    close(sockfd);
    return 0;
}