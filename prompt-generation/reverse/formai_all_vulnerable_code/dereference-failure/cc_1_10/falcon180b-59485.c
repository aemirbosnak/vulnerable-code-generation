//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, ret, timeout = 5;
    struct sockaddr_in server_addr;
    char *host = argv[1];
    char *buffer = malloc(MAX_DATA_SIZE);
    struct timeval tv;

    memset(&server_addr, 0, sizeof(server_addr));

    if(argc < 2)
    {
        printf("Usage:./ping <host>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("Error opening socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    ret = inet_pton(AF_INET, host, &server_addr.sin_addr);

    if(ret!= 1)
    {
        printf("Invalid IP address\n");
        exit(1);
    }

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if(ret < 0)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to %s\n", host);

    while(1)
    {
        memset(buffer, 0, MAX_DATA_SIZE);

        ret = recv(sockfd, buffer, MAX_DATA_SIZE, 0);

        if(ret <= 0)
        {
            printf("Connection closed\n");
            break;
        }

        printf("Received data: %s", buffer);
    }

    close(sockfd);

    return 0;
}