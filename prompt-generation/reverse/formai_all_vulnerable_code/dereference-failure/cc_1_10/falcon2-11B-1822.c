//Falcon2-11B DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Convert host name to IP address
    server = gethostbyname("www.google.com");
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Store the address of server in a structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    while (1)
    {
        // Read data from the server
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0)
        {
            perror("read error");
            exit(EXIT_FAILURE);
        }

        // Print the data received
        printf("%s", buffer);

        // Send a request to the server
        sprintf(buffer, "GET / HTTP/1.1\r\n\r\n");
        write(sockfd, buffer, strlen(buffer));

        // Read the server's response
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0)
        {
            perror("read error");
            exit(EXIT_FAILURE);
        }

        // Print the server's response
        printf("%s", buffer);
    }

    return 0;
}