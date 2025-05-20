//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    // Connect to the server
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("www.example.com");
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        printf("Trying to connect to server...\n");
        send(sockfd, "GET / HTTP/1.1\r\n\r\n", 28, 0);
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n < 0)
        {
            perror("ERROR receiving data");
            exit(EXIT_FAILURE);
        }
        if (strstr(buffer, "200 OK")!= NULL)
        {
            printf("Website is up and running.\n");
        }
        else
        {
            printf("Website is down.\n");
        }
        sleep(60); // Check every minute
    }

    return 0;
}