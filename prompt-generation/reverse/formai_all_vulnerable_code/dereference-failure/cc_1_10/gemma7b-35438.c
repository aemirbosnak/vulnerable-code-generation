//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

#define MAX_PINGS 10

int main()
{
    int sockfd, port, i, j, recv_len, ping_num = 0;
    char buffer[1024];
    struct sockaddr_in server_addr;
    struct hostent *hp;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    server_addr.sin_port = htons(8080);
    server_addr.sin_family = AF_INET;
    hp = gethostbyname("localhost");
    server_addr.sin_addr.s_addr = hp->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send and receive pings
    for (i = 0; i < MAX_PINGS; i++)
    {
        printf("Enter your ping message: ");
        scanf("%s", buffer);

        // Send the ping message
        send(sockfd, buffer, strlen(buffer), 0);

        // Receive the ping response
        recv_len = recv(sockfd, buffer, 1024, 0);

        // Print the ping response
        printf("Received: %s\n", buffer);

        ping_num++;
    }

    // Close the socket
    close(sockfd);

    // Print the number of pings
    printf("Total number of pings: %d\n", ping_num);

    return 0;
}