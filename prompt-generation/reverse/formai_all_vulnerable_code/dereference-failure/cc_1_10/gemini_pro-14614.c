//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>

#define MAX_BUF_SIZE 1024

int main()
{
    // Initialize variables
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUF_SIZE];
    struct timeval start, end;
    double rtt;
    int num_packets = 0;
    int num_lost = 0;

    // Get the server address and port number
    printf("Enter the server address: ");
    scanf("%s", buffer);
    printf("Enter the server port: ");
    scanf("%d", &portno);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Get the server's IP address
    server = gethostbyname(buffer);
    if (server == NULL)
    {
        perror("Error getting server's IP address");
        exit(1);
    }

    // Set up the server address structure
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Send a message to the server
    strcpy(buffer, "Hello, world!");
    n = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (n < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    // Start the timer
    gettimeofday(&start, NULL);

    // Receive a message from the server
    n = recvfrom(sockfd, buffer, MAX_BUF_SIZE, 0, NULL, NULL);
    if (n < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate the RTT
    rtt = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    rtt /= 1000;

    // Print the RTT
    printf("RTT: %f ms\n", rtt);

    // Close the socket
    close(sockfd);

    return 0;
}