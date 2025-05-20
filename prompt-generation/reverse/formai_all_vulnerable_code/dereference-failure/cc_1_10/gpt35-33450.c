//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, cli_sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    char buffer[MAX_SIZE];

    if (argc < 3)
    {
        fprintf(stderr, "ERROR: Invalid Arguments!\nUsage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        fprintf(stderr, "ERROR: Unable To Create Socket!");
        exit(1);
    }

    // Get server details
    server = gethostbyname(argv[1]);

    if (server == NULL)
    {
        fprintf(stderr, "ERROR: No Such Host!");
        exit(1);
    }

    // Set server address
    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    // Connect to server through proxy
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "ERROR: Unable To Connect!");
        exit(1);
    }

    // Clear buffer
    bzero(buffer, MAX_SIZE);

    // Read request from client
    n = read(cli_sockfd, buffer, MAX_SIZE);

    if (n < 0)
    {
        fprintf(stderr, "ERROR: Unable To Read Data From Client!");
        exit(1);
    }

    // Print request
    printf("REQUEST: %s\n", buffer);

    // Send request to server through proxy
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0)
    {
        fprintf(stderr, "ERROR: Unable To Write Data To Server!");
        exit(1);
    }

    // Clear buffer
    bzero(buffer, MAX_SIZE);

    // Read response from server through proxy
    n = read(sockfd, buffer, MAX_SIZE);

    if (n < 0)
    {
        fprintf(stderr, "ERROR: Unable To Read Data From Server!");
        exit(1);
    }

    // Print response
    printf("RESPONSE: %s\n", buffer);

    // Send response to client
    n = write(cli_sockfd, buffer, strlen(buffer));

    if (n < 0)
    {
        fprintf(stderr, "ERROR: Unable To Write Data To Client!");
        exit(1);
    }

    close(sockfd);
    close(cli_sockfd);

    return 0;
}