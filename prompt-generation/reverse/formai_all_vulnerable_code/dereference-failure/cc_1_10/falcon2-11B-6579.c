//Falcon2-11B DATASET v1.0 Category: Networking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Resolve the host name
    server = gethostbyname("localhost");
    if (server == NULL)
    {
        perror("gethostbyname failed");
        exit(EXIT_FAILURE);
    }

    // Store the server's address in a sockaddr structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server!\n");

    // Send data to server
    char buffer[256];
    printf("Enter your message: ");
    fgets(buffer, sizeof(buffer), stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1)
    {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    // Receive data from server
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1)
    {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("Server says: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}