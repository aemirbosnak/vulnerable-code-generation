//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PINGS 10

int main()
{
    int sockfd, err, n, i;
    char buf[1024];
    struct sockaddr_in servaddr;
    struct hostent *hp;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(8));
    if (sockfd < 0)
    {
        perror("socket");
        return 1;
    }

    // Get the host's IP address
    hp = gethostbyname("localhost");
    servaddr.sin_addr.s_addr = inet_addr(hp->h_addr_list[0]);

    // Set the port number
    servaddr.sin_port = htons(5000);

    // Send a ping message
    for (i = 0; i < MAX_PINGS; i++)
    {
        sprintf(buf, "Ping!");
        n = sendto(sockfd, buf, strlen(buf) + 1, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

        if (n < 0)
        {
            perror("sendto");
            return 1;
        }

        // Receive the echo message
        n = recvfrom(sockfd, buf, 1024, 0, (struct sockaddr *)&servaddr, NULL);

        if (n < 0)
        {
            perror("recvfrom");
            return 1;
        }

        // Print the echo message
        printf("Echo: %s\n", buf);
    }

    // Close the socket
    close(sockfd);

    return 0;
}