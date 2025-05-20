//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <arpa/inet.h>

int main()
{
    int sockfd, bytes_sent, bytes_received;
    struct sockaddr_in server_addr;
    char buffer[1024];
    char hostname[1024];
    int port;

    // Get the hostname of the local machine
    gethostname(hostname, sizeof(hostname));

    // Convert the hostname to an IP address
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        fprintf(stderr, "ERROR: Unable to resolve hostname\n");
        return 1;
    }

    // Initialize the sockaddr structure
    memset((char *) &server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(he->h_addrtype == AF_INET6? htons(60000) : 80);
    bcopy((char *) he->h_addr_list[0], (char *) &server_addr.sin_addr.s_addr, he->h_length);

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "ERROR: Failed to create socket\n");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "ERROR: Failed to connect to server\n");
        return 1;
    }

    // Send the PING command
    bytes_sent = send(sockfd, "PING /? HTTP/1.1\r\n\r\n", strlen("PING /? HTTP/1.1\r\n\r\n"), 0);
    if (bytes_sent < 0) {
        fprintf(stderr, "ERROR: Failed to send PING command\n");
        return 1;
    }

    // Receive the response
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        fprintf(stderr, "ERROR: Failed to receive response\n");
        return 1;
    }

    // Close the socket
    close(sockfd);

    // Print the response
    printf("Response: %s\n", buffer);

    return 0;
}