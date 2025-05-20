//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, numbytes;
    char senddata[MAX_DATA_SIZE], recvdata[MAX_DATA_SIZE];
    struct hostent *host;
    struct sockaddr_in serv_addr;

    if(argc!= 2)
    {
        printf("Usage:./ping <hostname/IP address>\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == 0)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    // Get server address
    host = gethostbyname(argv[1]);

    if(host == NULL)
    {
        printf("Error getting host address\n");
        exit(1);
    }

    // Fill in server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);
    serv_addr.sin_port = htons(80);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send data
    strcpy(senddata, "GET / HTTP/1.1\r\nHost: ");
    strcat(senddata, argv[1]);
    strcat(senddata, "\r\nConnection: close\r\n\r\n");

    numbytes = send(sockfd, senddata, strlen(senddata), 0);

    if(numbytes < 0)
    {
        printf("Error sending data\n");
        exit(1);
    }

    // Receive data
    numbytes = recv(sockfd, recvdata, MAX_DATA_SIZE, 0);

    if(numbytes < 0)
    {
        printf("Error receiving data\n");
        exit(1);
    }

    printf("Data received: %s\n", recvdata);

    close(sockfd);

    return 0;
}