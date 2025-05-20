//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
    char hostname[MAX_HOST_NAME];
    char data[MAX_DATA_SIZE];
    int sockfd, n, retval;
    struct hostent *hostinfo;
    struct sockaddr_in serveraddr;

    if (argc!= 3) {
        printf("Usage:./ping host data\n");
        exit(1);
    }

    strcpy(hostname, argv[1]);
    strcpy(data, argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        printf("Error getting host information\n");
        exit(1);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(80);
    memcpy(&serveraddr.sin_addr.s_addr, hostinfo->h_addr, hostinfo->h_length);

    retval = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (retval == -1) {
        printf("Error connecting to host\n");
        exit(1);
    }

    send(sockfd, data, strlen(data), 0);
    recv(sockfd, data, MAX_DATA_SIZE, 0);

    printf("Ping response:\n%s\n", data);

    close(sockfd);
    exit(0);
}