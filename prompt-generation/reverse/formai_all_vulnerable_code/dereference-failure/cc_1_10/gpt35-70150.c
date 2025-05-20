//FormAI DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    // Check if hostname is provided as argument
    if(argc != 2)
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[BUFFER_SIZE];
    strcpy(hostname, argv[1]);

    struct hostent *host;
    host = gethostbyname(hostname);

    if(!host)
    {
        printf("Error: Host not found\n");
        return 1;
    }

    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(0);
    dest_addr.sin_addr = *((struct in_addr *)host->h_addr);
    memset(&(dest_addr.sin_zero), '\0', 8);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("Error: Could not create socket");
        return 1;
    }

    // Connect to destination address
    int status = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
    if(status == -1)
    {
        perror("Error: Connection Failed");
        close(sockfd);
        return 1;
    }

    // Ping test request
    char message[] = "Ping Test";
    int message_size = strlen(message);

    // Send ping test request
    status = send(sockfd, message, message_size, 0);
    if(status == -1)
    {
        perror("Error: Failed to send message");
        close(sockfd);
        return 1;
    }

    // Receive ping test response
    char response[BUFFER_SIZE];
    int response_size = recv(sockfd, response, sizeof(response), 0);
    if(response_size == -1)
    {
        perror("Error: Failed to receive response");
        close(sockfd);
        return 1;
    }

    // Print response received from the server
    printf("Response Received: %.*s\n", response_size, response);

    // Close socket
    close(sockfd);

    return 0;
}