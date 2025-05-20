//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define HOST "www.example.com"
#define PAGE "/"
#define PORT 80

char *request_message(char *message, char *host, char *page)
{
    // Create the HTTP request message
    sprintf(message, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", page, host);

    return message;
}

int main()
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];
    char request[4096];
    char *host = HOST;
    char *page = PAGE;
    int port = PORT;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server = gethostbyname(host);
    if (server == NULL)
    {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    request_message(request, host, page);

    // Send the HTTP request message
    n = write(sockfd, request, strlen(request));
    if (n < 0)
    {
        perror("Error writing to socket");
        exit(1);
    }

    printf("HTTP Client: Sending request to server...\n");
    printf("HTTP Client: Request message sent to server: \n%s\n", request);

    // Receive the server's response
    printf("HTTP Client: Received response from server...\n");
    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0)
    {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}