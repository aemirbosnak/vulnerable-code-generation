//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct timeval timeout;
    double start, end, time_taken;

    // Initialize the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[1]));
    server = gethostbyname("www.google.com");
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    else
    {
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    // Start the timer
    start = clock();

    // Send a request to the server
    int numBytes = 1024;
    char request[numBytes];
    sprintf(request, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n");
    n = send(sockfd, request, strlen(request), 0);
    if (n < 0)
    {
        perror("ERROR sending data");
        exit(1);
    }

    // Receive the response from the server
    bzero(request, numBytes);
    n = recv(sockfd, request, numBytes, 0);
    if (n < 0)
    {
        perror("ERROR receiving data");
        exit(1);
    }

    // Stop the timer
    end = clock();

    // Calculate the time taken
    time_taken = (end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("Connection established with server.\n");
    printf("Data sent: %d bytes\n", n);
    printf("Data received: %d bytes\n", n);
    printf("Time taken: %.3lf seconds\n", time_taken);

    return 0;
}