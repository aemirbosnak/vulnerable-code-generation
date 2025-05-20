//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    char hostname[1024];
    char website[1024];
    struct hostent *hostinfo;
    struct in_addr *ipaddr;
    int sockfd, numbytes, i, j, status;
    int timeout = 3; // seconds
    char ping[1024];

    printf("Enter website to monitor: ");
    scanf("%s", website);

    printf("Enter hostname: ");
    scanf("%s", hostname);

    if ((hostinfo = gethostbyname(hostname)) == NULL) {
        printf("Error: hostname not found.\n");
        exit(1);
    }

    ipaddr = (struct in_addr *) hostinfo->h_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        printf("Error: socket creation failed.\n");
        exit(1);
    }

    numbytes = sizeof(ping);
    status = sendto(sockfd, ping, numbytes, 0, (struct sockaddr *) &ipaddr, sizeof(ipaddr));

    if (status < 0) {
        printf("Error: sendto failed.\n");
        exit(1);
    }

    numbytes = sizeof(ping);
    status = recvfrom(sockfd, ping, numbytes, 0, (struct sockaddr *) &ipaddr, &numbytes);

    if (status < 0) {
        printf("Error: recvfrom failed.\n");
        exit(1);
    }

    for (i = 0; i < numbytes; i++) {
        for (j = 0; j < numbytes; j++) {
            if (ping[i] == ping[j]) {
                printf("Website is up!\n");
                exit(0);
            }
        }
    }

    printf("Website is down!\n");
    exit(0);
}