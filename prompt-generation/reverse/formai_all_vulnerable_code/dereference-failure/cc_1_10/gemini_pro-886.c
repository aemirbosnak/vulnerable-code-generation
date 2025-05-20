//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

void send_packet(int sockfd, const char *buf, size_t len)
{
    write(sockfd, buf, len);
}

int recv_packet(int sockfd, char *buf, size_t len)
{
    return read(sockfd, buf, len);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <ip address> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_aton(argv[1], &servaddr.sin_addr);
    servaddr.sin_port = htons(atoi(argv[2]));

    char buf[1024];
    memset(buf, 0, sizeof(buf));

    struct timeval start, end;

    gettimeofday(&start, NULL);

    send_packet(sockfd, buf, sizeof(buf));
    int n = recv_packet(sockfd, buf, sizeof(buf));

    gettimeofday(&end, NULL);

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Time elapsed: %f seconds\n", elapsed);
    printf("Packet size: %d bytes\n", n);
    printf("Speed: %f bytes/second\n", n / elapsed);

    close(sockfd);
    return 0;
}