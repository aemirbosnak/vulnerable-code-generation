//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 80
#define DEFAULT_TIMEOUT 10

static int check_website(const char *hostname, int port, int timeout)
{
    struct sockaddr_in addr;
    int sockfd, ret;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(hostname);

    ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    ret = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    if (ret < 0) {
        perror("setsockopt");
        close(sockfd);
        return -1;
    }

    close(sockfd);

    return 0;
}

int main(int argc, char **argv)
{
    const char *hostname;
    int port, timeout;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname> [port] [timeout]\n", argv[0]);
        return EXIT_FAILURE;
    }

    hostname = argv[1];
    port = DEFAULT_PORT;
    if (argc >= 3) {
        port = atoi(argv[2]);
    }
    timeout = DEFAULT_TIMEOUT;
    if (argc >= 4) {
        timeout = atoi(argv[3]);
    }

    if (check_website(hostname, port, timeout) == 0) {
        printf("Website %s is up and running!\n", hostname);
    } else {
        printf("Website %s is down!\n", hostname);
    }

    return EXIT_SUCCESS;
}