//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PING_SIZE 56
#define PING_TIMEOUT 1000

int main(int argc, char **argv)
{
    struct sockaddr_in dest_addr;
    struct timeval start, end;
    struct hostent *host;
    int sockfd, n, ret;
    char *host_name;
    char ping[PING_SIZE];

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <host_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host_name = argv[1];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    host = gethostbyname(host_name);
    if (host == NULL)
    {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        exit(EXIT_FAILURE);
    }

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(0);
    dest_addr.sin_addr = *(struct in_addr *)host->h_addr;

    memset(ping, 0, PING_SIZE);
    ping[0] = 8;            // ICMP echo request
    ping[1] = 0;            // code
    ping[2] = 0;            // checksum, to be filled later
    ping[3] = 1;            // identifier
    ping[4] = 2;            // sequence number
    ping[5] = 1;            // payload size

    gettimeofday(&start, NULL);
    ret = sendto(sockfd, ping, PING_SIZE, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (ret < 0)
    {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

     while((n=recvfrom(sockfd,ping,PING_SIZE,0,NULL,NULL)) <= 0)
    {
        if (n == 0)
        {
            printf("timeout!\n");
            return -1;
        }
        else
        {
            perror("recvfrom");
            return -1;
        }
    }

    gettimeofday(&end, NULL);
    double elapse = (end.tv_sec-start.tv_sec)*1000.0 + (end.tv_usec-start.tv_usec)/1000.0;
    printf("Received reply from %s: bytes=%d time=%.2f ms\n", host_name, n, elapse);

    close(sockfd);
    return 0;
}