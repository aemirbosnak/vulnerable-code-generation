//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    // Get the port number from the user.
    printf("Enter the port number: ");
    scanf("%d", &portno);

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Get the server's IP address.
    server = gethostbyname("localhost");
    if (server == NULL)
    {
        perror("ERROR, no such host");
        exit(1);
    }

    // Set up the server's address.
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    // Get the data from the user.
    printf("Enter the data to send: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Send the data to the server.
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Close the socket.
    close(sockfd);

    return 0;
}