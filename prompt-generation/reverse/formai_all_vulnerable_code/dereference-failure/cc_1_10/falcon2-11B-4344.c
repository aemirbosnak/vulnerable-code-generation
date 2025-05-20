//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_PORTS 1000
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int i;
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER_SIZE];
    char port_number[10];

    if(argc!= 2)
    {
        printf("Usage: %s <host_ip>\n", argv[0]);
        return 1;
    }

    if(inet_aton(argv[1], &serv_addr.sin_addr) == 0)
    {
        printf("Invalid address\n");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    for(i=0; i<MAX_NUM_PORTS; i++)
    {
        portno = i + 1;
        printf("Scanning port %d... ", portno);
        if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            printf("Error opening socket\n");
            continue;
        }
        if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            printf("Connection failed\n");
            close(sockfd);
            continue;
        }
        if((n = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) < 0)
        {
            printf("Error reading from socket\n");
            close(sockfd);
            continue;
        }
        if(n > 0)
        {
            buffer[n] = '\0';
            printf("%s\n", buffer);
        }
        close(sockfd);
    }

    return 0;
}