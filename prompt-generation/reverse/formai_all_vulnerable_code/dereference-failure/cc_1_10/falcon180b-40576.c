//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int sockfd, retval, optval;
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];
    int datalen;
    int addrlen;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <data>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    strcpy(data, argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    addrlen = sizeof(server_addr);

    retval = connect(sockfd, (struct sockaddr *)&server_addr, addrlen);
    if (retval == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    datalen = strlen(data);
    retval = send(sockfd, data, datalen, 0);
    if (retval == -1) {
        printf("Error sending data\n");
        exit(1);
    }

    memset(data, 0, MAX_DATA);
    addrlen = sizeof(server_addr);

    retval = recv(sockfd, data, MAX_DATA, 0);
    if (retval == -1) {
        printf("Error receiving data\n");
        exit(1);
    }

    printf("Received data: %s\n", data);

    close(sockfd);

    return 0;
}