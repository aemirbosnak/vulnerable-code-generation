//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buf[1024];

    // Set up the server socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[1]);

    // Set up the server address
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    while (1)
    {
        // Accept a connection
        if ((n = accept(sockfd, NULL, NULL)) < 0)
        {
            perror("ERROR on accept");
            exit(EXIT_FAILURE);
        }

        // Receive the message from the client
        bzero(buf, sizeof(buf));
        n = recv(n, buf, sizeof(buf), 0);
        if (n <= 0)
        {
            perror("ERROR receiving message");
            exit(EXIT_FAILURE);
        }

        // Print the message to the console
        printf("%s\n", buf);

        // Send a response to the client
        bzero(buf, sizeof(buf));
        sprintf(buf, "Thank you for connecting to the chat server!\n");
        send(n, buf, strlen(buf), 0);

        // Close the connection
        close(n);
    }

    return 0;
}