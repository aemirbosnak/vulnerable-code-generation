//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Assign local port number
    portno = atoi(argv[1]);

    // Set up server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind to the port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    printf("Server is listening...\n");

    while (1)
    {
        // Accept a connection
        struct sockaddr_in cli_addr;
        socklen_t clilen = sizeof(cli_addr);
        int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0)
        {
            perror("ERROR on accept");
            continue;
        }

        // Send a message to the client
        char buf[1024];
        bzero(buf, 1024);
        printf("Client connected: %s\n", inet_ntoa(cli_addr.sin_addr));

        // Read from the client
        int n = read(newsockfd, buf, sizeof(buf));
        if (n < 0)
        {
            perror("ERROR reading from client");
            close(newsockfd);
            continue;
        }

        // Send a reply to the client
        send(newsockfd, buf, n, 0);
        printf("Sent message to client: %s\n", buf);

        // Close the connection
        close(newsockfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}