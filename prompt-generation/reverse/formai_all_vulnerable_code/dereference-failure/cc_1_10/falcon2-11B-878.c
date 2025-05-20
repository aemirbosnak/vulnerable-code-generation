//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: creative
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    struct sockaddr_in addr;
    int sockfd;
    char buffer[MAX_BUFFER_SIZE];
    char hostname[256];
    char service[256];
    char port[256];
    char mac[256];
    int size;

    printf("Enter the IP Address or Host Name: ");
    scanf("%s", hostname);

    struct hostent *hostinfo = gethostbyname(hostname);

    if (hostinfo == NULL) {
        printf("Invalid Hostname\n");
        return 0;
    }

    struct in_addr *ip = (struct in_addr *) hostinfo->h_addr_list[0];

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr.s_addr = ip->s_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    size = sizeof(addr);
    if (bind(sockfd, (struct sockaddr *) &addr, size) < 0) {
        perror("Binding failed");
        return 1;
    }

    while (1) {
        memset(buffer, 0, MAX_BUFFER_SIZE);

        size = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, NULL, NULL);

        if (size == 0) {
            break;
        }

        printf("Received packet: %s\n", buffer);

        char *token;
        token = strtok(buffer, ",");
        while (token!= NULL) {
            printf("%s,%s,%s,%s\n", token, hostname, service, port);
            token = strtok(NULL, ",");
        }
    }

    close(sockfd);
    return 0;
}