//Gemma-7B DATASET v1.0 Category: Email Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

#define SERVER_PORT 50000

int main()
{
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    int bytes_read;
    char filename[256];
    struct stat file_stat;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));

    // Bind the socket to a port
    server_addr.sin_port = htons(SERVER_PORT);
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for clients
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);

    // Receive file information
    bytes_read = recv(newsockfd, buffer, 1024, 0);
    filename[0] = '\0';
    memcpy(filename, buffer, bytes_read);

    // Check if file exists
    if (stat(filename, &file_stat) == 0)
    {
        // Send file size
        sprintf(buffer, "%d", file_stat.st_size);
        send(newsockfd, buffer, strlen(buffer), 0);
    }
    else
    {
        // Send error message
        sprintf(buffer, "Error: file not found");
        send(newsockfd, buffer, strlen(buffer), 0);
    }

    // Close the socket
    close(newsockfd);
    close(sockfd);

    return 0;
}