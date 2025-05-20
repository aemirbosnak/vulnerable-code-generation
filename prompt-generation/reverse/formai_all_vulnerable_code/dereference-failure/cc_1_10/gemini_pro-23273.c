//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Get the host information
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
        return 1;
    }

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "Error: Could not create socket\n");
        return 1;
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
    {
        fprintf(stderr, "Error: Could not set socket options\n");
        return 1;
    }

    // Set the socket address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    memcpy(&servaddr.sin_addr, host->h_addr_list[0], host->h_length);
    servaddr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        fprintf(stderr, "Error: Could not connect to server\n");
        return 1;
    }

    // Send the ping message
    const char *ping = "PING";
    int ping_len = strlen(ping);
    if (send(sockfd, ping, ping_len, 0) < 0)
    {
        fprintf(stderr, "Error: Could not send ping message\n");
        return 1;
    }

    // Receive the ping response
    char recvbuf[1024];
    int recv_len = recv(sockfd, recvbuf, sizeof(recvbuf), 0);
    if (recv_len < 0)
    {
        fprintf(stderr, "Error: Could not receive ping response\n");
        return 1;
    }

    // Print the ping response
    printf("Received ping response: %s\n", recvbuf);

    // Close the socket
    close(sockfd);

    return 0;
}