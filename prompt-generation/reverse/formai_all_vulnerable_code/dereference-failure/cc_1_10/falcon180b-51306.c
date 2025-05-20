//Falcon-180B DATASET v1.0 Category: Networking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
    int sockfd, newsockfd, portno;
    int addrlen, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    char *message;
    struct hostent *server;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0)
    {
        printf("Error opening socket\n");
        exit(1);
    }
    
    puts("Socket created");
    
    server = gethostbyname("localhost");
    
    if (server == NULL)
    {
        printf("Error locating host\n");
        exit(1);
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(12345);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
    
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error connecting to server\n");
        exit(1);
    }
    
    puts("Connected to server");
    
    while(1)
    {
        printf("Enter message to send: ");
        fgets(buffer, 1024, stdin);
        message = strtok(buffer, "\r\n");
        send(sockfd, message, strlen(message), 0);
    }
    
    close(sockfd);
    
    return 0;
}