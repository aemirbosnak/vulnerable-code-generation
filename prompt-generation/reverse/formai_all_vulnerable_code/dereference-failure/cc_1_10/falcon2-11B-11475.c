//Falcon2-11B DATASET v1.0 Category: Networking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address struct
    server = gethostbyname("localhost");
    if (server == NULL)
    {
        fprintf(stderr,"ERROR: no such host\n");
        exit(EXIT_FAILURE);
    }
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(5000);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    char buffer[100];
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "Hello, server!\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive message from server
    bzero(buffer, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0)
    {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Close connection
    close(sockfd);
    return 0;
}