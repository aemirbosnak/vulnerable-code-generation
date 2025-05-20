//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 80

void main()
{
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("ERROR opening socket");
        exit(1);
    }

    // Connect to remote server
    server = gethostbyname("127.0.0.1");

    if (server == NULL)
    {
        printf("ERROR, no such host");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(2000);

    // Establish connection
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection Failed");
        exit(1);
    }

    // Receive data from server
    printf("Connection Established\n");

    while (1)
    {
        bzero(buffer, MAX);
        printf("Enter your message: ");
        fgets(buffer, MAX, stdin);
        write(sockfd, buffer, strlen(buffer));

        bzero(buffer, MAX);
        printf("Server: ");
        read(sockfd, buffer, MAX);
        printf("%s\n", buffer);
        if (strcmp(buffer, "bye") == 0)
        {
            printf("Server Disconnected\n");
            break;
        }
    }

    // Close connection
    close(sockfd);
}