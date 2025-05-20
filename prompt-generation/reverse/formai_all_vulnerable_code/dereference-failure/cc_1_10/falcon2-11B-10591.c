//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    // Initialize variables
    struct sockaddr_in server;
    int sockfd, portno, n;

    // Check for correct number of command line arguments
    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    // Convert hostname to IPv4 address
    struct hostent *host = gethostbyname(argv[1]);

    // Check for error in hostname resolution
    if (host == NULL)
    {
        fprintf(stderr, "Error: Unknown host %s\n", argv[1]);
        return 1;
    }

    // Store IPv4 address of host in server struct
    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    bcopy((char *) host->h_addr, (char *) &server.sin_addr.s_addr, host->h_length);
    server.sin_port = htons(0);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0)
    {
        perror("connect");
        return 1;
    }

    // Send ICMP ECHO_REQUEST message to the server
    n = sendto(sockfd, "PING ", 5, 0, (struct sockaddr *) &server, sizeof(server));

    // Receive ICMP ECHO_REPLY message from the server
    n = recvfrom(sockfd, "PONG", 5, 0, NULL, NULL);

    // Close the socket
    close(sockfd);

    return 0;
}