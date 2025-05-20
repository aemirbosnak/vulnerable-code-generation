//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main()
{
    // Create a socket
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Resolve hostname
    struct hostent *host;
    host = gethostbyname("google.com");
    if (host == NULL)
    {
        perror("ERROR, no such host");
        exit(1);
    }

    // Create a new socket
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    bcopy((char *) host->h_addr, (char *) &serv_addr.sin_addr.s_addr, host->h_length);
    serv_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    // Send the ping request
    int num_bytes = send(sockfd, "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n", 61, 0);
    if (num_bytes < 0)
    {
        perror("ERROR sending data");
        exit(1);
    }

    // Receive the response
    char buffer[1024];
    int num_bytes_recv = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes_recv < 0)
    {
        perror("ERROR receiving data");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    // Print the response
    printf("Response: %s\n", buffer);

    return 0;
}