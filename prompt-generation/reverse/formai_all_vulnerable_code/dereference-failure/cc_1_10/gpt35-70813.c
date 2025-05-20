//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Error: Please provide hostname and port number!\n");
        exit(1);
    }

    struct hostent *host = gethostbyname(argv[1]); // Get host details by name
    if(host == NULL)
    {
        printf("Error: Could not get host details!\n");
        exit(1);
    }

    int port = atoi(argv[2]); // Convert port number from string to integer
    if(port <= 0 || port > 65535)
    {
        printf("Error: Invalid port number!\n");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create socket
    if(sockfd == -1)
    {
        printf("Error: Could not create socket!\n");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr);

    int connect_status = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)); //Connect to server
    if(connect_status == -1)
    {
        printf("Error: Could not connect to server!\n");
        exit(1);
    }

    char request[1024];
    memset(request, 0, sizeof(request));
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]); // Prepare HTTP GET request

    write(sockfd, request, strlen(request)); // Send HTTP GET request to server

    char response[4096];
    memset(response, 0, sizeof(response));
    int read_status = read(sockfd, response, sizeof(response)-1); // Read HTTP response from server
    if(read_status == -1)
    {
        printf("Error: Could not read response from server!\n");
        exit(1);
    }

    printf("%s", response); // Print HTTP response from server

    close(sockfd); // Close socket

    return 0; // Exit program
}