//Gemma-7B DATASET v1.0 Category: Building a SMTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

int main()
{
    int sockfd, newsockfd, portno = 25;
    char buffer[1024];
    struct sockaddr_in serv_addr;
    struct hostent *hp;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(portno));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Get the host name
    hp = gethostbyname("localhost");
    if (hp == NULL)
    {
        perror("Error getting host name");
        exit(1);
    }

    // Bind the socket to a port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_aton(hp->h_addr_list[0], NULL);

    // Listen for connections
    listen(sockfd, 5);

    // Accept a connection
    newsockfd = accept(sockfd, NULL, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    // Send a message
    sprintf(buffer, "Hello, world!");
    write(newsockfd, buffer, strlen(buffer));

    // Close the connection
    close(newsockfd);
    close(sockfd);

    return 0;
}