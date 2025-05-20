//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 80

int main()
{
    int sockfd, portno, valread, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Get server name and address
    server = gethostbyname("www.example.com");
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Store the server address
    memcpy((char *) &serv_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s on port %d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    // Read data from server
    while ((valread = recv(sockfd, &n, sizeof(n), 0)) > 0)
    {
        printf("Received data: %s\n", (char*)&n);
    }

    return 0;
}