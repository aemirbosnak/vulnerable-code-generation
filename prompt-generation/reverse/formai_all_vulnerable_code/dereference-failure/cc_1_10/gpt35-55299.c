//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>

#define PORT 8000
#define BUFSIZE 1024

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int create_socket()
{
    int sockfd = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP);

    if(sockfd < 0) {
        error("Error opening socket");
    }

    return sockfd;
}

void set_socket_nonblocking(int sockfd)
{
    int flags = fcntl(sockfd, F_GETFL, 0);

    if(flags < 0) {
        error("Error getting socket flags");
    }

    if(fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) < 0) {
        error("Error setting socket flags");
    }
}

void scan_network()
{
    int sockfd = create_socket();
    set_socket_nonblocking(sockfd);

    struct sockaddr_in6 multicast_addr;
    memset(&multicast_addr, 0, sizeof(struct sockaddr_in6));
    multicast_addr.sin6_family = AF_INET6;
    multicast_addr.sin6_port = htons(PORT);
    inet_pton(AF_INET6, "ff02::1", &multicast_addr.sin6_addr);

    char buf[BUFSIZE];
    ssize_t num_bytes;

    fd_set readfds;

    while(1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        int retval = select(sockfd+1, &readfds, NULL, NULL, &tv);

        if(retval == -1) {
            error("Error in select");
        } else if(retval == 0) {
            break;
        } else {
            num_bytes = recvfrom(sockfd, buf, BUFSIZE, 0, NULL, NULL);

            if(num_bytes < 0 && errno != EWOULDBLOCK) {
                error("Error receiving data");
            } else if(num_bytes > 0) {
                buf[num_bytes] = '\0';
                printf("%s\n", buf);
            }
        }
    }

    close(sockfd);
}

int main()
{
    scan_network();
    return 0;
}