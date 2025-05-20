//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: realistic
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>

int main()
{
    int sockfd;
    struct sockaddr_in serv_addr;
    int opt = 1;
    char buf[1024];
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("www.google.com");
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        int n = read(sockfd, buf, 1024);
        if (n < 0)
        {
            perror("ERROR reading from socket");
            exit(EXIT_FAILURE);
        }

        if (n == 0)
        {
            printf("No data received from server\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("Received %d bytes from server\n", n);
        }
    }

    return 0;
}