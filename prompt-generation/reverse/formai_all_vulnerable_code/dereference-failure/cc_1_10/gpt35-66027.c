//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>
#include <string.h>
#include <errno.h>

#include <sys/time.h>

#define MAX_BUFFER_SIZE 1024
#define TIMEOUT_MICROSECONDS 1000000

int main(int argc, char *argv[])
{
    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = TIMEOUT_MICROSECONDS;

    int sockfd, numbytes;
    char buffer[MAX_BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: monitor hostname\n");
        exit(EXIT_FAILURE);
    }

    struct hostent *he;
    struct sockaddr_in their_addr;

    if ((he=gethostbyname(argv[1])) == NULL) {
        printf("Cannot resolve hostname.\n");
        exit(EXIT_FAILURE);
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        printf("Unable to create socket.\n");
        exit(EXIT_FAILURE);
    }

    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(0);
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(their_addr.sin_zero), '\0', 8);

    if (bind(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        printf("Unable to bind socket.\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server.sin_zero), '\0', 8);

    // start loop
    while(1) {
        sendto(sockfd, "HTTP/1.1\r\n", strlen("HTTP/1.1\r\n"), 0, (struct sockaddr*)&server, sizeof(struct sockaddr));
        numbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);

        if (numbytes == -1) {
            printf("Receive error.\n");
            return EXIT_FAILURE;
        }

        buffer[numbytes] = '\0';

        printf("Received: %s\n", buffer);

        select(0, NULL, NULL, NULL, &timeout);
    }

    close(sockfd);
    
    return EXIT_SUCCESS;
}