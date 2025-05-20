//Falcon2-11B DATASET v1.0 Category: Networking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CONNECTIONS 5
#define MAX_DATA 1024

int main()
{
    int socket_fd, new_fd, portno, newsockfd, i, numbytes;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_DATA];
    struct hostent *server;

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up server address struct
    server = gethostbyname("localhost");
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(5000);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    // Set up message to send
    printf("Enter message to send: ");
    fgets(buffer, MAX_DATA, stdin);

    // Send message
    numbytes = send(socket_fd, buffer, strlen(buffer), 0);
    if (numbytes < 0)
    {
        perror("ERROR sending message");
        exit(1);
    }
    printf("Message sent\n");

    // Set up buffer to receive message
    bzero(buffer, MAX_DATA);
    i = sizeof(cli_addr);
    if ((new_fd = accept(socket_fd, (struct sockaddr *) &cli_addr, &i)) < 0)
    {
        perror("ERROR accepting connection");
        exit(1);
    }
    printf("Connection accepted\n");

    // Receive message
    numbytes = recv(new_fd, buffer, MAX_DATA, 0);
    if (numbytes < 0)
    {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("Message received: %s\n", buffer);

    // Close the sockets
    close(new_fd);
    close(socket_fd);

    return 0;
}