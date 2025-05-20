//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 8888
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd, portnum, i, n, recv_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        return 1;
    }

    printf("Client connected: %s:%d\n", client_addr.sin_addr.s_addr, client_addr.sin_port);

    for (i = 0; i < 10; i++)
    {
        n = recv(newsockfd, buffer, BUFFER_SIZE, 0);
        if (n < 0)
        {
            perror("Error receiving data");
            return 1;
        }

        printf("Received: %s\n", buffer);

        send(newsockfd, buffer, n, 0);
        if (send < 0)
        {
            perror("Error sending data");
            return 1;
        }

        printf("Sent: %s\n", buffer);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}