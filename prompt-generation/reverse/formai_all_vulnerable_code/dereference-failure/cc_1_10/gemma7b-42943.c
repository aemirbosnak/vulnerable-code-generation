//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PINGS 5
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, port, n, i, status;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *host;

    // Get the host name from the user
    printf("Enter the host name: ");
    scanf("%s", buffer);

    // Resolve the host name
    host = gethostbyname(buffer);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *(struct in_addr *)host->h_addr;
    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Send a ping message
    for (i = 0; i < MAX_PINGS; i++)
    {
        printf("Sending ping...\n");
        write(sockfd, "PING", 5);

        // Receive the response
        n = read(sockfd, buffer, BUFFER_SIZE);

        // Print the response
        printf("Received response: %s\n", buffer);
    }

    // Close the socket
    close(sockfd);

    return 0;
}