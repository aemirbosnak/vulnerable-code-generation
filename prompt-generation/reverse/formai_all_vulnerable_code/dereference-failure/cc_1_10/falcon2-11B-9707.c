//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define MAX_HOST 100

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        printf("Usage: %s <target IP> <timeout> \n", argv[0]);
        return 1;
    }

    struct hostent *he;
    struct in_addr *iap;
    char ip_address[INET_ADDRSTRLEN];

    he = gethostbyname(argv[1]);
    if (he == NULL)
    {
        printf("Host %s not found\n", argv[1]);
        return 1;
    }

    iap = (struct in_addr *)he->h_addr_list[0];
    inet_ntop(AF_INET, &(iap->s_addr), ip_address, sizeof(ip_address));

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)iap->s_addr, (char *)&serv_addr.sin_addr.s_addr, serv_addr.sin_addr.s_addr);
    serv_addr.sin_port = htons(0);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 1;
    }

    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection failed\n");
        return 1;
    }

    struct timeval timeout;
    timeout.tv_sec = atoi(argv[2]);
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0)
    {
        printf("Error setting receive timeout\n");
        return 1;
    }

    char buf[1024];
    int n = read(sockfd, buf, sizeof(buf));
    if (n < 0)
    {
        printf("Error reading from socket\n");
        return 1;
    }
    else if (n == 0)
    {
        printf("Connection closed by remote host\n");
        return 1;
    }

    char *host = strstr(buf, "\r\n");
    if (host == NULL)
    {
        printf("Invalid response\n");
        return 1;
    }

    printf("Ping to %s succeeded!\n", argv[1]);
    printf("Time elapsed: %ld ms\n", n);
    printf("Ping response: %s\n", host + 4);

    close(sockfd);
    return 0;
}