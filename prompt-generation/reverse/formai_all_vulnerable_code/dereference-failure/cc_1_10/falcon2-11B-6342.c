//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Creating a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Getting the server name and address
    if ((server = gethostbyname("localhost")) == NULL)
    {
        fprintf(stderr, "gethostbyname failed\n");
        exit(EXIT_FAILURE);
    }

    memset((char *)&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Sending a message to the server
    char msg[100];
    sprintf(msg, "Hello, server!");

    send(sockfd, msg, strlen(msg), 0);

    // Receiving a response from the server
    bzero(msg, sizeof(msg));
    n = recv(sockfd, msg, sizeof(msg), 0);

    printf("Received %s\n", msg);

    // Closing the socket
    close(sockfd);

    return 0;
}