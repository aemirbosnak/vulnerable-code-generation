//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <poll.h>

#define BUFSIZE 1024

static int sockfd;
static struct sockaddr_in servaddr;
static struct pollfd pfds[2];

static void signal_handler(int signum)
{
    switch (signum) {
    case SIGINT:
    case SIGTERM:
        close(sockfd);
        exit(0);
        break;
    }
}

static void init_socket(const char *ip, int port)
{
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    pfds[0].fd = sockfd;
    pfds[0].events = POLLIN;
    pfds[1].fd = STDIN_FILENO;
    pfds[1].events = POLLIN;
}

static void handle_packet(void)
{
    char buf[BUFSIZE];
    socklen_t len = sizeof(servaddr);

    int n = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *)&servaddr, &len);
    if (n < 0) {
        perror("recvfrom");
        exit(1);
    }

    printf("Received packet from %s:%d: %s\n", inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port), buf);
}

static void handle_stdin(void)
{
    char buf[BUFSIZE];

    if (fgets(buf, BUFSIZE, stdin) == NULL) {
        perror("fgets");
        exit(1);
    }

    if (strcmp(buf, "quit\n") == 0) {
        close(sockfd);
        exit(0);
    } else {
        int n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
        if (n < 0) {
            perror("sendto");
            exit(1);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    init_socket(argv[1], atoi(argv[2]));

    while (1) {
        int nfds = poll(pfds, 2, -1);
        if (nfds < 0) {
            perror("poll");
            exit(1);
        }

        if (pfds[0].revents & POLLIN) {
            handle_packet();
        }

        if (pfds[1].revents & POLLIN) {
            handle_stdin();
        }
    }

    return 0;
}