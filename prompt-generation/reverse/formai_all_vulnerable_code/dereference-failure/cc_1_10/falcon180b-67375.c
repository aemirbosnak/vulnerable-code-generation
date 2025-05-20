//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 100
#define PORT 8080
#define SA struct sockaddr

int main()
{
    int sockfd, newsockfd, portno, clilen, i;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error opening socket\n");
        exit(1);
    }

    puts("Socket created");

    // set the server address
    server = gethostbyname("127.0.0.1");
    if (server == NULL)
    {
        printf("Error getting host by name\n");
        exit(1);
    }

    // fill server address structure
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // connect to server
    if (connect(sockfd, (SA *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    puts("Connected to server");

    // receive a message from server
    clilen = sizeof(cli_addr);
    recv(sockfd, buffer, MAX, 0);
    buffer[strcspn(buffer, "\r")] = '\0';
    printf("Received message: %s\n", buffer);

    // send a message to server
    sprintf(buffer, "I love you too! ");
    send(sockfd, buffer, strlen(buffer), 0);

    // close socket
    close(sockfd);

    return 0;
}