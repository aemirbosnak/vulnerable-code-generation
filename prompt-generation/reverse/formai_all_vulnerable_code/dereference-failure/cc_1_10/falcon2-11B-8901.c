//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

// Function to check website uptime
int checkWebsiteUptime(char* websiteUrl)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address struct
    memset((char*) &serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    server = gethostbyname(websiteUrl);
    if (server == NULL)
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd,(struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    // Send GET request
    sprintf(buffer, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", websiteUrl);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
    {
        perror("ERROR sending request");
        exit(1);
    }

    // Receive response
    bzero(buffer, 256);
    n = recv(sockfd, buffer, 256, 0);
    if (n < 0)
    {
        perror("ERROR receiving response");
        exit(1);
    }
    printf("Response from server: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}

int main(int argc, char* argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <website URL>\n", argv[0]);
        exit(1);
    }

    checkWebsiteUptime(argv[1]);
    return 0;
}