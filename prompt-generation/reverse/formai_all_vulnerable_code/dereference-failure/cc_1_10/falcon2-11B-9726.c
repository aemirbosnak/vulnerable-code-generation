//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    char hostname[1024];
    char request[1024];
    char response[1024];
    char error[1024];
    struct hostent* host;
    struct in_addr* ip;
    int sockfd;
    int len, result;
    struct sockaddr_in server;

    printf("Enter the IP address or hostname of the remote server: ");
    gets(hostname);

    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Invalid hostname or IP address.\n");
        return 1;
    }

    ip = (struct in_addr*) host->h_addr;
    server.sin_family = AF_INET;
    server.sin_port = htons(1);
    server.sin_addr.s_addr = ip->s_addr;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }

    sprintf(request, "\x07\x00\x00\x01");
    sprintf(response, "\x06\x00\x00\x01");

    len = sendto(sockfd, request, strlen(request), 0, (struct sockaddr*) &server, sizeof(server));
    if (len < 0) {
        printf("Error: Failed to send request.\n");
        return 1;
    }

    len = recvfrom(sockfd, response, sizeof(response), 0, NULL, NULL);
    if (len < 0) {
        printf("Error: Failed to receive response.\n");
        return 1;
    }

    result = atoi(response);

    printf("Response from %s: %d milliseconds\n", hostname, result);

    close(sockfd);

    return 0;
}