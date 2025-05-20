//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    // Create a socket
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error: Cannot create socket.\n");
        exit(1);
    }
    
    // Get the server hostname and port from command line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    
    // Get server information from hostname
    struct hostent *server;
    server = gethostbyname(hostname);
    if (server == NULL)
    {
        printf("Error: Host not found.\n");
        exit(1);
    }

    // Set up the server address and connect to server
    struct sockaddr_in serveraddr;
    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        printf("Error: Cannot connect to server.\n");
        exit(1);
    }

    // Send HTTP request to server
    char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    int bytesSent;
    bytesSent = send(sockfd, request, strlen(request), 0);
    if (bytesSent < 0)
    {
        printf("Error: Cannot send HTTP request.\n");
        exit(1);
    }

    // Receive HTTP response from server
    char response[1024];
    int bytesReceived;
    bytesReceived = recv(sockfd, response, 1024, 0);
    if (bytesReceived < 0)
    {
        printf("Error: Cannot receive HTTP response.\n");
        exit(1);
    }

    // Print the HTTP response
    printf("%s", response);

    // Close the socket
    close(sockfd);

    return 0;
}