//FormAI DATASET v1.0 Category: Network Ping Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024
#define MAX_HOST_LEN 64

int create_socket()
{
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void send_ping(int sockfd, struct sockaddr_in *addr, const char *hostname)
{
    char ping_packet[] = "PING";
    size_t packet_size = strlen(ping_packet);

    printf("Pinging %s ...\n", hostname);

    if (sendto(sockfd, ping_packet, packet_size, 0, (struct sockaddr *) addr, sizeof(*addr)) <= 0) {
        perror("Ping send failed");
        exit(EXIT_FAILURE);
    }
}

void receive_ping(int sockfd, struct sockaddr_in *addr)
{
    struct timeval tv = {2, 0};
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);

    char buf[MAX_BUF_SIZE] = {0};

    if (select(sockfd + 1, &rfds, NULL, NULL, &tv) <= 0) {
        printf("Host is not responding.\n");
        return;
    }

    if (recvfrom(sockfd, buf, MAX_BUF_SIZE, 0, (struct sockaddr *) addr, sizeof(*addr)) <= 0) {
        perror("Ping receive failed");
        exit(EXIT_FAILURE);
    }

    printf("Host %s is alive!\n", inet_ntoa(addr->sin_addr));
}

void ping_host(const char *hostname)
{
    struct hostent *host = gethostbyname(hostname);

    if (!host)
    {
        fprintf(stderr, "Invalid hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    memcpy(&(addr.sin_addr.s_addr), host->h_addr, host->h_length);

    int sockfd = create_socket();

    send_ping(sockfd, &addr, hostname);
    receive_ping(sockfd, &addr);

    close(sockfd);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <hostname> ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; ++i)
    {
        ping_host(argv[i]);
    }

    return 0;
}